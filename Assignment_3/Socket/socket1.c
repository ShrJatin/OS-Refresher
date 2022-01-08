#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#define size 50
#define LABEL "socket"

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

int main()
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

    int fromlen, i = 0;
    struct sockaddr_un saun, fsaun;
    register int _socket, server;


    printf("\nCreating Server...");
    if ((_socket = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
    {
        perror("Server: Socket acquiration failed");
        exit(1);
    }
    printf("\nSender Server Created\n");

    saun.sun_family = AF_UNIX;
    strcpy(saun.sun_path, LABEL);
    printf("\nUnlinking the Socket path...\n");
    unlink(LABEL);

    printf("\nBinding the Socket to port...\n");
    if (bind(_socket, (struct sockaddr *)&saun, sizeof(struct sockaddr_un)) < 0)
    {
        perror("Server: Binding Unsuccessfull");
        exit(1);
    }
    printf("Binding Successfull...\n");


    printf("\nSeting up the socket for listening...\n");
    if (listen(_socket, 5) < 0)
    {
        perror("Server: Listening Unsuccessfull");
        exit(1);
    }

    printf("\nWaiting for Reciever to Conenct...\n");
    if ((server = accept(_socket , (struct sockaddr *)&fsaun, &fromlen)) == -1)
    {
        perror("Server: Failed to get reciever");
        exit(1);
    }
    printf("Server: Reciever conected successfully");

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

        printf("\n\nServer Sending Packet...");
        send(server, store, sizeof(store), 0);
        printf("\nPacket Sent.\n");


        int log;
        
        if ((read(server, &log, sizeof(log))) == -1)
        {
            perror("Server: Failed to recieve");
            exit(EXIT_FAILURE);
        }

        printf("\nRecieved Feedback(Highest) ID: %d \n", log);

        printf("\nFeeding Recieved Id...\n"); 

        i = log + 1;
    }

    if(close(server) == -1){
        perror("Sender: Closing for server Failed");
        exit(EXIT_FAILURE);
    }    
    printf("Data sent Successfully");
    return 0;   
}
