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

    printf("\nE2:sec up alarm_wakeup function!!!\n");

    /* Send first signal in 1 second, 0 microseconds. */    
    tout_val.it_interval.tv_sec = INTERVAL;
    tout_val.it_interval.tv_usec = 0;
    
    /* Send subsequent signals in 1 second, 0 microseconds intervals. */   
    tout_val.it_value.tv_sec = START; /* 10 seconds timer */
    tout_val.it_value.tv_usec = 0;

    if(setitimer(ITIMER_REAL, &tout_val,0) == -1){
        perror("E2:setitimer\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}


unsigned long long rdtsc(void)
{
  unsigned hi, lo;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}



void handlerE1(){
// 9223372036
    unsigned long long cycle  = rdtsc();
    unsigned long long mhz  = 2000000000;
    long sec = (long) cycle/mhz;

    int h, m, s;

	h = (int)(sec/3600); 
	
	m = (int)(sec -(3600*h))/60;
	
	s = (int)(sec -(3600*h)-(m*60));

    int t_stamp = (h*10000+ m*100 + s);



    printf("\nGenerated time stamp Number in E2 handler: %d:%d:%d", h, m, s );

    union sigval value;
    value.sival_int = t_stamp;

    if(sigqueue(pid, SIGTERM, value) == -1){
        perror("E2:SIGQUEUE");
        exit(EXIT_FAILURE);
    }

    if (kill(pid, SIGTERM) == -1){
        perror("E2:KILL FAILURE");
        exit(EXIT_FAILURE);
    }

}


void main(int argc, char *argv[]){


    pid = atoi(argv[0]);


    int iRet;
    void (*pfRet)(int);


    if ((iRet = alarm_wakeup()) == -1) {
        printf("Failure in Alarm Wakeup in E2\n");
        exit(EXIT_FAILURE);
    }


    struct sigaction sAction = {0};
    sAction.sa_handler = handlerE1;
    sAction.sa_flags = SA_RESTART;


    if (sigaction(SIGALRM, &sAction, NULL) == -1) {
        perror("E2:SIGACTION");
        exit(EXIT_FAILURE);
    }

    while(1) usleep(10000);
}

