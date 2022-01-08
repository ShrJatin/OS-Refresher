#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/*
 * Proucer Program
 */
#define SYS_writer 449

int readData(char *data, int size) {

    int fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0)
    {
       printf("Producer: cann't open /dev/urandom\n");
       return -1;
    }

    int ret = read(fd, data, size);
    if (ret < 0)
    {
       printf("Producer: cann't read /dev/urandom\n");
       return -1;   
    }

    if (close(fd) < 0)
    {
       printf("Producer: cann't close /dev/urandom\n");
       return -1;
    }

    return ret;
}


int main() {

    int i = 1;

    while(1) {
        
        sleep(1);

        char *data = malloc(8);
        if(data == NULL) {
            printf("Producer: malloc failed\n");
            return -1;
        }

        int ret = readData(data, 8);
        if (ret < 0)
        {
            printf("Producer: readData error\n");
            return -1;
        }

        printf("Producer: %d bytes,  %s\n", ret, data);
        
        long res = syscall(SYS_writer, data, 8);
        if(res < 0) {
            printf("Producer: kernel queue is full\n\n");
            continue;
        }

        printf("Producer: Bytes sent to writer syscall successfully for iteration %d\n\n", i);
        i+=1;
        
    }

    return 0;
}
