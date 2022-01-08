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

#define START 1
#define INTERVAL 1 

pid_t pid;

int alarm_wakeup ()
{
    struct itimerval tout_val;

    printf("\nE1:sec up alarm_wakeup function!!!\n");

    /* Send first signal in 1 second, 0 microseconds. */    
    tout_val.it_interval.tv_sec = INTERVAL;
    tout_val.it_interval.tv_usec = 0;
    
    /* Send subsequent signals in 1 second, 0 microseconds intervals. */   
    tout_val.it_value.tv_sec = START; /* 10 seconds timer */
    tout_val.it_value.tv_usec = 0;

    if(setitimer(ITIMER_REAL, &tout_val,0) == -1){
        perror("E1:setitimer\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}


void handlerE1(){

    unsigned int val;
    
    uint64_t ret;
    asm("rdrand %0\n\t"
                         :"=a"(ret)::);
    val = ret;   

    
    printf("\nGenerated Random Number in  E1 handler: %u\n", val);

   
    union sigval value;
    value.sival_int = val;

    if(sigqueue(pid, SIGTERM, value) == -1){
        perror("E1:SIGQUEUE");
        exit(EXIT_FAILURE);
    }

    if (kill(pid, SIGTERM) == -1){
        perror("E1:KILL FAILURE");
        exit(EXIT_FAILURE);
    }
    
}


void main(int argc, char *argv[]){


    pid = atoi(argv[0]);


    int iRet;
    void (*pfRet)(int);


    if ((iRet = alarm_wakeup()) == -1) {
        printf("E1:Failure in Alarm Wakeup\n");
        exit(EXIT_FAILURE);
    }


    struct sigaction sAction = {0};
    sAction.sa_handler = handlerE1;
    sAction.sa_flags = SA_RESTART;


    if (sigaction(SIGALRM, &sAction, NULL) == -1) {
        perror("E1:SIGACTION");
        exit(EXIT_FAILURE);
    }

    while(1) usleep(10000);
}

