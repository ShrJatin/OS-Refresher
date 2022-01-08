#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
 * Put your syscall number here.
 */
#define SYS_kernel_2d_memcpy 448


void print(void *mat, int row, int col)
{
    float *temp = (float *) mat;
    for(int i = 0; i < row*col; i++)
    {
        printf("%f ", *(temp + i));

        if((i+1)%col == 0) printf("\n");
    }
    printf("\n");
}


int main(int argc, char **argv)
{
    
    float src[2][3] = {{1.2, 2.3, 3.4}, {5.2, 6.3, 2.5}};
    float *dest = (float *) malloc(sizeof(src));

    int row = sizeof(src)/sizeof(src[0]);
    int col = sizeof(src[0])/sizeof(float);

    // printf("%d\n", row);
    // printf("%d\n", col);
    
    printf("\nMaking system call with following Matrix\n");
    printf("Source Matrix\n");
    print(src, row, col);
    printf("Destination Matrix\n");
    print(dest, row, col);
    
    long res = syscall(SYS_kernel_2d_memcpy, dest, src, sizeof(src));
    if(res == -1)
    {
        printf("Syscall Failure");
        assert(res != -1);
    }
    
    printf("\nSystem call returned following matrix\n");
    printf("Source Matrix\n");
    print(src, row, col);
    printf("Destination Matrix\n");
    print(dest, row, col);
    return 0;
}