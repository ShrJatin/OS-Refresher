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
struct msqid1_ds *buff;

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


int main()
{
    /* code */

    key_t key1, key2;

    printf("\nReciver: Acquiring Key for reciving...");
    if((key1 = ftok(QUEUE_PATH1, 'd')) == -1){
        perror("Key Acquire Failed");
        exit(EXIT_FAILURE);
    }
    printf("\nAcquiration Done.\n");
    
    printf("\nReciver: Acquiring Key for Sending...");
    if((key2 = ftok(QUEUE_PATH2, 'd')) == -1){
        perror("Key Acquire Failed");
        exit(EXIT_FAILURE);
    }
    printf("\nAcquiration Done.\n");


    printf("\nReciever Created\n");
    printf("\nWaiting for Sender...\n");
    
    int msqid1, msqid2, i, log = -1;

    printf("\nOpening Message Queue...\n");
    if ((msqid1 = msgget(key1, 0666 | IPC_CREAT)) == -1)
    {
        perror("Open: Message Queue Failed\n");
        exit(EXIT_FAILURE);
    }

    printf("\nOpening Message Queue for Send Back...");
    if ((msqid2 = msgget(key2, 0666 | IPC_CREAT)) == -1)
    {
        perror("Reciever Message Queue");
        exit(EXIT_FAILURE);
    }
    
    while (log < 49)
    {

        struct container store[5];

        printf("\nRecieving Packet...");

        if (msgrcv(msqid1, &message, sizeof(message), message.mtype, 0) == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < 5; j++)
        {
            if (message.store[j].id == log + 1)
            {
                // printf("log: %d, id: %d", log, store[j].id);
                log = message.store[j].id;
                printf("\nString: %s, id : %d ", message.store[j].data, message.store[j].id);
            }
            else
                break;
        }

        printf("\nPacket Recieved.\n");

        printf("\nRecieved Highest most ID: %d\n", log);

       

        idBuffer.mtype = 2;
        idBuffer.id[0] = log;

        printf("\nSending back Highest most ID...");
        if (msgsnd(msqid2, &idBuffer, sizeof(idBuffer), 0) == -1){
            perror("Write Message Queue\n");
            exit(EXIT_FAILURE);
        }

        printf("\nFeedback ID Sent.\n");
    }

    printf("\nclosing messege queue\n");
    if(msgctl(msqid1, IPC_RMID, NULL) == -1){
        perror("Reciever: Closing Failed for Sender");
        exit(EXIT_FAILURE);
    }

    

    printf("\nData Recieved Succesfully\n\n");

    return 0;
}
