#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/*
 * Consumer Program
 */
#define SYS_reader 450

int main() {

    int i = 1;

    while(1) {
        sleep(1);

        char *data = malloc(8);
        if(data == NULL) {
            printf("Consumer: malloc failed\n");
            return -1;
        }

        long res = syscall(SYS_reader, data, sizeof(data));
        if(res < 0) {
            printf("Consumer: kernel queue is empty\n\n");
            continue;
        }

        printf("Consumer: %d bytes,  %s\n", 8, data);
        printf("Consumer: Bytes read using reader syscall successfully for iteration %d\n\n", i);
        
        i+=1;
    }

    return 0;
}
