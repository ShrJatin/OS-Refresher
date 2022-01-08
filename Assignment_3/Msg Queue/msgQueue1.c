#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define QUEUE_PATH1 "msgQueue"
#define QUEUE_PATH2 "idQueue"


struct container
{
    /* data */
    int id;
    char data[10];
};


struct mesg_buffer {
    long mtype;
    struct container store[5];
} message;


struct id_buffer {
    long mtype;
    char id[1];
} idBuffer;


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

    key_t key1, key2;

    printf("\nSender: cquiring key1...");
    if((key1 = ftok(QUEUE_PATH1, 'd')) == -1){
        perror("key Acquire Failed");
        exit(EXIT_FAILURE);
    }
    printf("\nSender:Acquiration Done.\n");

    printf("\nSender: cquiring key2...");
    if((key2 = ftok(QUEUE_PATH2, 'd')) == -1){
        perror("key Acquire Failed");
        exit(EXIT_FAILURE);
    }
    printf("\nSender: Acquiration Done.\n");


    int msqid1, msqid2, i = 0;
    printf("\nOpening Message Queue with key1 ...: ");
    if ((msqid1 = msgget(key1, 0666 | IPC_CREAT)) == -1)
    {
        perror("Open: Message Queue Failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Done\n");



    printf("\nSender: Opening Message Queue to recieve Feedback ID with key2...: ");
    if ((msqid2 = msgget(key2, 0666 | IPC_CREAT)) == -1)
    {
        perror("Open: Message Queue Recieve\n");
        exit(EXIT_FAILURE);
    }
    printf("Done\n");


    while (i < 50)
    {

        printf("\nSender: Storing following Strings in Packet");

        message.mtype = 1;

        for (int j = i; j < i + 5; j++)
        {
            strcpy(message.store[(j - i) % 5].data, a[j]);
            message.store[(j - i) % 5].id = j;
            printf("\nString: %s, Id : %d ", a[j], j);
        }


        printf("\n\nSender: Message Queue Sending Packet...");
        if (msgsnd(msqid1, &message, sizeof(message), 0) == -1)
        {
            perror("Write: Message Queue Sender");
            exit(EXIT_FAILURE);
        }
        printf("\nSender: Packet Sent.\n");
        
        sleep(2);


        if (msgrcv(msqid2, &idBuffer, sizeof(idBuffer), 2, 0) == -1)
        {
            perror("Read: Message Queue Reciever");
            exit(EXIT_FAILURE);
        }

        printf("\nRecieved Feedback(Highest) ID: %d \n", idBuffer.id[0]);

        printf("\nFeeding Recieved Id...\n");

        i = idBuffer.id[0] + 1;
       
    }

    printf("\nData sent succesfully\n\n");

    printf("closing messege queue with key2\n");
    if(msgctl(msqid2, IPC_RMID, NULL) == -1){
        perror("\nReciever: Closing Failed for Sender\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

