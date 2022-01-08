#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#define LABEL "socket"

struct container
{
    /* data */
    int id;
    char data[10];
};

int main()
{
    /* code */

    register int i, _socket, len;
    struct sockaddr_un saun;

    printf("\nCreating Client...");
    if ((_socket = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
    {
        perror("Client: Socket acquiration failed\n\n");
        exit(1);
    }
    printf("\nClient Created\n");


    saun.sun_family = AF_UNIX;
    strcpy(saun.sun_path, LABEL);
    int log = -1;
    len = sizeof(saun.sun_family) + strlen(saun.sun_path);

    printf("\nClient: client connecting with server\n");
    if (connect(_socket, (struct sockaddr *)&saun, len) < 0) 
    {
        perror("Client: Connection failed");
        exit(1);
    }
    printf("Connected to server successfully\n\n");

    while (log < 49)
    {

        struct container store[5];

        printf("\nRecieving Packet...");

        if (read(_socket, store, sizeof(store)) == -1)
        {
            perror("READ");
            exit(EXIT_FAILURE);
        }


        for (int j = 0; j < 5; j++)
        {
            if (store[j].id == log + 1)
            {
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
        if ((length = send(_socket, &log, sizeof(log), 0)) == -1){
            perror("Write fifo2\n");
            exit(EXIT_FAILURE);
        }

        printf("\nFeedback ID Sent.\n");

    }

    if(close(_socket) == -1){
        perror("Client: Closing for Reciever Failed");
        exit(EXIT_FAILURE);
    }

    printf("Data sent Successfully");

    return 0;
}