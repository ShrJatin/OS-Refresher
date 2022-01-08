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

void genRandomString(int n, char *res)
{

    char alphabets[26] = "abcdefghijklmnopqrstuvwxyz";
    char buff[2];
    for (int i = 0; i < n; i++)
    {
        snprintf(buff, 2, "%c", alphabets[rand() % 26]);
        strcat(res, buff);
    }
}

int main(int argc, char const *argv[])
{

    /* code */
    char *a[50];
    for (int i = 0; i < 50; i++)
    {

        int len = 10;
        char input[10];
        strcpy(input, "");
        a[i] = malloc(10 * sizeof(char));
        genRandomString(len, input);
        strcpy(a[i], input);
    }

    int fd1, fd2, i = 0;

    printf("\nCreating Sender FIFO1...");
    if(mkfifo(FIFO_NAME1, 0777) == -1){
        perror("FIFO Acquiration Failed");
        exit(EXIT_FAILURE);
    }
    printf("\nSender FIFO1 Created\n");


    printf("\nOpening Sender FIFO1...\n");
    printf("\nWaiting for Reciever to Open FIFO1...\n");
    if ((fd1 = open(FIFO_NAME1, O_WRONLY )) == -1)
    {
        perror("Sender: Failed to open sending FIFO1");
        exit(EXIT_FAILURE);
    }    


    printf("\nOpening Reciever FIFO...\n");
    if ((fd2 = open(FIFO_NAME2, O_RDONLY)) == -1)
    {
        perror("Sender: Failed to open Reciever FIFO2");
        exit(EXIT_FAILURE);
    }

    while (i < 50)
    {
        printf("\nStoring following Strings in Packet");

        struct container store[5];
        for (int j = i; j < i + 5; j++)
        {
            strcpy(store[(j - i) % 5].data, a[j]);
            store[(j - i) % 5].id = j;
            printf("\nString: %s, Id : %d ", a[j], j);
        }


        printf("\n\nFIFO1 Sending Packet...");
        ssize_t length;
        if ((length = write(fd1, store, sizeof(store))) == -1)
        {
            perror("Write: FIFO1 Sender");
            exit(EXIT_FAILURE);
        }
        printf("\nPacket Sent.\n");

        int log;
        
        if ((read(fd2, &log, sizeof(log))) == -1)
        {
            perror("Read: FIFO2 Reciever");
            exit(EXIT_FAILURE);
        }

        printf("\nRecieved Feedback(Highest) ID: %d \n", log);

        printf("\nFeeding Recieved Id...\n"); 

        i = log + 1;
    }

    printf("\nData sent succesfully\n\n");

    if(close(fd1) == -1){
        perror("Sender: Closing for Sender Failed");
        exit(EXIT_FAILURE);
    }

    if(close(fd2) == -1){
        perror("Sender: Closing for Reciever Failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
