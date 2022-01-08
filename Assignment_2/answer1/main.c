#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <assert.h>


pid_t child_S1 = 0;
pid_t child_SR = 0;
pid_t child_ST = 0;


// ------------------------Process-S1---------------------------------------------
void handlerS1(int sig, siginfo_t *si, void *uap)
{  
    int val = si->si_int;
    int odd = val;
    if(odd/1000000 == 0){
        printf("Printing time stamp in S1 handler: %d:%d:%d\n\n", val/10000, (val%10000)/100, (val%10000)%100);

    } else {
        printf("Printing Random Number in S1 handler: %u\n", si->si_int);
    }

}

void processS1()
{
    struct sigaction sAction = {0};
    sAction.sa_sigaction = handlerS1;
    sAction.sa_flags = SA_SIGINFO;

    // Registering signal handler for SIGTERM
    if (sigaction(SIGTERM, &sAction, NULL) == -1)
    {
        perror("SIGTERM");
        exit(EXIT_FAILURE);
    }

    while(1) sleep(10); 
}


int main(int argc, const char *argv[])
{
    // Fork
    if ((child_S1 = fork()) == 0){
        printf("PID of S1: %d\n", getpid());
        printf("Registering SIGTERM Handler for S1\n");
        processS1();

    } else {

        if ((child_SR = fork()) == 0){
            printf("PID of SR: %d\n", getpid());
            
            char buff[50];
            snprintf(buff, sizeof(buff), "%d", child_S1);

            execlp("./e1", buff, NULL);
        }

        if ((child_ST = fork()) == 0)
        {
            printf("PID of ST: %d\n", getpid());
            
            char buff[50];
            snprintf(buff, sizeof(buff), "%d", child_S1);

            execlp("./e2", buff, NULL);
        }
    }

    


    //     if ((child_SR = fork()) == 0)
    //     {

            // char buff[50];
            // snprintf(buff, sizeof(buff), "%d", S1);
            // printf("s1 pid SR %d getpid: %d\n ", child_S1, S1);

            // E1(child_S1);
            // execlp("./e1", buff, NULL);
        // }

    //     if ((child_ST = fork()) == 0)
    //     {
    //     // char buff[50];
    // //     snprintf(buff, sizeof(buff), "%d", child_S1);
    //         printf("/ns1 pid ST %d\n", child_S1);

    //         E2(child_S1);
    // //     execlp("./e2", buff, NULL);
    //     }
    // }
    // processST(child_S1);

    // printf("S1 bhar, s1 id: %d\n", child_S1);
    
    return 0;
}