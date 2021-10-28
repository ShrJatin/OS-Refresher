#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>


int readLine(int filedesc, char *data, int num_bytes) {
    memset(data, 0, num_bytes);

    // printf("processing\n");

    int i = 0;
    while(i < num_bytes){

        int file_size = read(filedesc, &data[i], 1);

        if(file_size < 0){
            perror("Line:20-error while reading the file");
            return 0;
        }

        if(data[i] == '\n') {
            // printf("done\n");
            data[i] = '\0';
            return 1;
        }

        i++;
    }
    // printf("not reached\n");
    return 0;
}


int cleanSum(char *data, int *marks, char section) {
    char *buffer_context[1024];

    char *token;
   
    /* get the first token */
    token = strtok_r(data, ",", buffer_context);
    if(token == NULL){
        return -1;
    }

    /* get the second token */
    token = strtok_r(NULL, ",", buffer_context);
    if(token == NULL){
        return -1;
    }

    if(token[0] != section){
        return -1;
    }


    /* walk through other tokens having marks*/
    for(int i=0; i<6; ++i) {
        token = strtok_r(NULL, ",", buffer_context);
        if(token == NULL){
            return -1;
        }
        *(marks + i) += atoi(token);
    }

    return 0;
}


void printAndDumb(int *marks, int no_of_student, char section, int temp, char process[]){

    char res[300];

    int read = snprintf(res,300,"AVERAGE Of ASSIGNMENTS ACROSS SECTION %c Calculated by %s Process :\nAssignment1--> %f\nAssignment2--> %f\nAssignment3--> %f\nAssignment4--> %f\nAssignment5--> %f\nAssignment6--> %f\n\n", section, process, (double)(*(marks + 0))/no_of_student, (double)(*(marks + 1))/no_of_student, (double)(*(marks + 2))/no_of_student, (double)(*(marks + 3))/no_of_student, (double)(*(marks + 4))/no_of_student, (double)(*(marks + 5))/no_of_student);
    if(read < 0){
        perror("Line:78-Error while storing formated output");
        exit(0);
    }

    res[strlen(res)] = '\0';

    int wr = write(STDOUT_FILENO, res, strlen(res));
    if(wr < 0){
        perror("Line:86-Error while writing to stdout");
        exit(0);
    }

    wr = write(temp, res, strlen(res));
    if(wr < 0){
        perror("Line:92-Error while writing to stdout");
        exit(0);
    }
}


void main() {
    
    int temp = open("fork_Dumb.txt",  O_WRONLY | O_CREAT, 0644);
    if(temp < 0){
        perror("Line:102-Error while opening the file that is used to dump!\n");
        exit(0);
    }

    pid_t pid = fork();

    if(pid < 0) {
        perror("Line:109-Failure in forking!\n");
        exit(1);
    }

    int filedesc = open("student_record.csv", O_RDONLY, S_IRUSR);
    if(filedesc < 0) {
        perror("Line:115-Error while opening the file!\n");
        exit(0);
    }

    int num_bytes = 100;
    char data[num_bytes];

    int marks[6] = {0,0,0,0,0,0};


    // child process
    if(pid == 0) {

        char print1[] = "---------------------------\nChild Process in Progress...\n---------------------------\n";
        int wr = write(STDOUT_FILENO, print1, strlen(print1));
        if(wr < 0){
            perror("Line:131-Error while writing to stdout");
            exit(0);
        }

        int no_of_student = 0;

        readLine(filedesc, data, num_bytes); //to skip 1st row

        while(readLine(filedesc, data, num_bytes)) {

            // printf("lendata: %lu\n", strlen(data));
            // printf("data%s\n", data);

            int line_res = cleanSum(data, marks, 'A');
            if(line_res >= 0){
                no_of_student++;
                // for(int i = 0; i < 6; i++){
                //     printf("%d ", marks[i]);
                // }
                // printf("\n");
            }
        }

        int cl = close(filedesc); 
        if(cl < 0) {
            perror("Line:156-Error while closing the file!");
            exit(0);
        }

        printAndDumb(marks, no_of_student, 'A', temp, "Child");
		exit(0);

    //Parent Process starts here!
	} else {

        waitpid(0, NULL, 0);

        char print2[] = "---------------------------\nChild Process Terminated...\n---------------------------\n\n---------------------------\nParent Process in Progress...\n---------------------------\n";
        int wr = write(STDOUT_FILENO, print2, strlen(print2));
        if(wr < 0){
            perror("Line:171-Error while writing to stdout");
            exit(0);
        }

        int no_of_student = 0;

        readLine(filedesc, data, num_bytes); //to skip 1st row

        while(readLine(filedesc, data, num_bytes)>0) {

            // printf("lendata: %lu\n", strlen(data));
            // printf("data%s\n", data);

            int line_res = cleanSum(data, marks, 'B');
            if(line_res >= 0){
                no_of_student++;

                // for(int i = 0; i < 6; i++){
                //     printf("%d ", marks[i]);
                // }
                // printf("\n");
                
            }
        }

        int cl = close(filedesc); 
        if(cl < 0) {
            perror("Line:198-Error while closing the file!");
            exit(0);
        }

        printAndDumb(marks, no_of_student, 'B', temp, "Parent");

        cl = close(temp); 
        if(cl < 0) {
            perror("Line:206-Error while closing the file!");
            exit(0);
        }

        char print3[] = "---------------------------\nParent Process Terminated...\n---------------------------\n\n";
        wr = write(STDOUT_FILENO, print3, strlen(print3));
        if(wr < 0){
            perror("Line:213-Error while writing to stdout");
            exit(0);
        }

        exit(0);
    }
}

