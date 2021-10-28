#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <string.h>




int readLine(int filedesc, char *data, int num_bytes) {
    memset(data, 0, num_bytes);

    // printf("processing\n");

    int i = 0;
    while(i < num_bytes){

        int file_size = read(filedesc, &data[i], 1);

        if(file_size < 0){
            perror("Line:22-error while reading the file");
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


void printAndDumb(int *marks, int no_of_student, char section, char process[]){

    int temp = open("Thread_Dump.txt",  O_WRONLY | O_APPEND | O_CREAT, 0644);
    
    if(temp < 0){
        perror("Line:79-Error while opening the file that is used to dump!\n");
        exit(0);
    }

    char res[300];

    int read = snprintf(res,300,"AVERAGE Of ASSIGNMENTS ACROSS SECTION %c Calculated by Thread-%s :\nAssignment1--> %f\nAssignment2--> %f\nAssignment3--> %f\nAssignment4--> %f\nAssignment5--> %f\nAssignment6--> %f\n\n", section, process, (double)(*(marks + 0))/no_of_student, (double)(*(marks + 1))/no_of_student, (double)(*(marks + 2))/no_of_student, (double)(*(marks + 3))/no_of_student, (double)(*(marks + 4))/no_of_student, (double)(*(marks + 5))/no_of_student);
    if(read < 0){
        perror("Line:87-Error while storing formated output");
        exit(0);
    }

    res[strlen(res)] = '\0';

    int wr = write(STDOUT_FILENO, res, strlen(res));
    if(wr < 0){
        perror("Line:95-Error while writing to stdout");
        exit(0);
    }

    wr = write(temp, res, strlen(res));
    if(wr < 0){
        perror("Line:101-Error while writing to stdout");
        exit(0);
    }
}


void *myChild(void *vargp) {   

    int num_bytes = 100;
    char data[num_bytes];

    int *marks = (int *) vargp;

    int filedesc = open("student_record.csv", O_RDONLY, S_IRUSR);
    if(filedesc < 0) {
        printf("Line:116-Error while opening the file");
        exit(0);
    }

    int no_of_student;

    readLine(filedesc, data, num_bytes); //to skip 1st row

    while(readLine(filedesc, data, num_bytes)>0) {

        int line_res = cleanSum(data, marks, 'A');
        if(line_res >= 0){
            no_of_student++;
        }
    }

    *(marks + 6) = no_of_student;

    int cl = close(filedesc); 
    if(cl < 0) {
        perror("Line:136-Error while closing the file!");
        exit(0);
    }

    printAndDumb(marks, no_of_student, 'A', "1");
    pthread_exit(0);
}

 
void *myParent(void *vargp) {   

    int num_bytes = 100;
    char data[num_bytes];

    int *marks = (int *)vargp;

    int filedesc = open("student_record.csv", O_RDONLY, S_IRUSR | S_IWUSR);
    if(filedesc < 0) {
        perror("Line:154-Error while opening the file!");
        exit(0);
    }

    int no_of_student;

    readLine(filedesc, data, num_bytes); //to skip 1st row

    while(readLine(filedesc, data, num_bytes)>0) {

        int line_res = cleanSum(data, marks, 'B');
        if(line_res >= 0){
            no_of_student++;
        }
    }

    *(marks + 6) = no_of_student;


    int cl = close(filedesc); 
    if(cl < 0) {
        perror("Line:177-Error while closing the file!");
        exit(0);
    }

    printAndDumb(marks, no_of_student, 'B',"2");
    pthread_exit(0);
}


int main() {

    int marksA[7] = {};
    int marksB[7] = {};

    pthread_t Parent, child;

    char print1[] = "\n---------------------------\nThread-1 and Thread-2 in Progress...\n---------------------------\n";
    write(STDOUT_FILENO, print1, strlen(print1));

    int thread = pthread_create(&child, NULL, myChild, (void*)marksA);
    if(thread != 0){
        perror("Line:196-Error while creating thread");
    }

    thread = pthread_create(&Parent, NULL, myParent, (void*)marksB);
    if(thread != 0){
        perror("Line:201-Error while creating thread");
    }


    thread = pthread_join(child, NULL);
    if(thread != 0){
        perror("Line:207-Error while creating thread");
    }
    thread = pthread_join(Parent, NULL);
    if(thread != 0){
        perror("Line:211-Error while creating thread");
    }

    char print2[] = "---------------------------\nThreaad-1 Child Threaad-2 Terminated...\n---------------------------\n\n";
    int wr = write(STDOUT_FILENO, print2, strlen(print2));
    if(wr < 0){
        perror("Line:217-Error while writing to stdout");
        exit(0);
    }

    int total[7] = {};
    for(int i = 0; i < 7; i++){

        total[i] = marksA[i] + marksB[i];
    }
    printAndDumb(total, total[6], 31, "");
    if(wr < 0){
        perror("Line:245-Error while writing to stdout");
        exit(0);
    }
    exit(0);
}

