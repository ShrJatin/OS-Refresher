#include <stdio.h>
#include <stdlib.h>

 
int gen_rand() {
   
    int num;
    num = rand() % 10 + 1;
    return num;
}

void allocate_and_print(char s[], char* argv[], int* type[]) {

    for(int i = 0; i < 6; i++) {
       
        for(int j = 0; j < (*argv[i+1] - 48); j++) {
      
            if(s == "print"){
                printf("%d  ", *(type[i] + j));
            } 

            if(s == "allocate") {
                *(type[i] + j) = gen_rand();
            }
        }

        if(s == "print") printf("\n");
    }

}

int main(int argc, char *argv[]) {
    /* code */

    printf("\n**********Solution-1b: Genrating Matrix with varriable nummber of columns**********\n");


    if (argc != 7) {
        printf("\nPlease give command in the below format.\nUsage: ./21b <R1> <R2> <R3> <R4> <R5> <R6>\n Ri are integers that provides the no of columns in ith row.\n\n");
        return 0;
    }

    int* type[6];

    for(int i = 1; i < 7; i++) {
        type[i-1] = (int*) malloc((*argv[i] - 48) * sizeof(int));
    }

    allocate_and_print("allocate", argv, type);
   
    printf("\nRequired Matrix: \n");
    allocate_and_print("print", argv, type);
    printf("\n");
   
    return 0;
}