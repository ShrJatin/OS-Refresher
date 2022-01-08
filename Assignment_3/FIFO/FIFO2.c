#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#define FIFO_NAME1 "fifo1"
#define FIFO_NAME2 "fifo2"

struct container
{
    /* data */
    int id;
    char data[10];
};

int main()
{
    /* code */

    printf("\nCreating Reciever FIFO...");
    if(mkfifo(FIFO_NAME2, 0777) == -1){
        perror("FIFO Acquiration Failed");
        exit(EXIT_FAILURE);
    }
    printf("\nReciever FIFO Creation Done.\n");

    int fd1, fd2;

    int i = 0;
    int log = -1;

    printf("\nOpening Reciever FIFO1...\n");
    if ((fd1 = open(FIFO_NAME1, O_RDONLY )) == -1)
    {
        perror("Reciver: for recieving\n");
        exit(EXIT_FAILURE);
    }
    
    sleep(3);

    printf("\nOpening Sender FIFO2...\n");
    printf("\nWaiting for Sender to open FIFO2...\n");
    if ((fd2 = open(FIFO_NAME2, O_WRONLY)) == -1)
    {
        perror("Reciever: for sending FIFO-2");
        exit(EXIT_FAILURE);
    }

    while (log < 49)
    {

        struct container store[5];

        printf("\nRecieving Packet...");

        
        if (read(fd1, store, sizeof(store)) == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < 5; j++)
        {
            if (store[j].id == log + 1)
            {
                // printf("log: %d, id: %d", log, store[j].id);
                log = store[j].id;
                printf("\nString: %s, id : %d ", store[j].data, store[j].id);
            }
            else
                break;
        }   
        
        printf("\nPacket Recieved.\n");

        printf("\nRecieved Highest most ID: %d\n", log);

        sleep(2);


        size_t length;
        printf("\nSending back Highest most ID...");
        if ((length = write(fd2, &log, sizeof(log))) == -1){
            perror("Write fifo2\n");
            exit(EXIT_FAILURE);
        }
     
        printf("\nFeedback ID Sent.\n");
    }

    printf("\nData Recieved Succesfully\n\n");

    if(close(fd1) == -1){
        perror("Reciever: Closing for Sender Failed");
        exit(EXIT_FAILURE);
    }

    if(close(fd2) == -1){
        perror("Reciever: Closing for Reciever Failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
