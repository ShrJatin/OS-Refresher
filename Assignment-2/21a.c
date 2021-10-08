#include <stdio.h>
#include <stdlib.h>

 
int gen_rand() {
    
    int num;
    num = rand() % 10 + 1;
    return num;
}

void allocate_and_print(char s[], int size[], int* type[]) {

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < size[i]; j++) {

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


int main() {
    /* code */

    printf("\n**********Solution-1a: Genrating given Matrix**********\n");


    int size[6] = {7, 4, 6, 3, 7, 2};

    int* type[6];

    for(int i = 0; i < 6; i++) {
        type[i] = (int*) malloc(size[i] * sizeof(int));
    }

    allocate_and_print("allocate", size, type);
   
    printf("\nRequired Matrix: \n");
    allocate_and_print("print", size, type);
    printf("\n");
   
    return 0;
}

