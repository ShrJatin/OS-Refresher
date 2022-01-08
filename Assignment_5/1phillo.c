#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <pthread.h>

struct My_semaphore
{
    ssize_t count;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

void init(struct My_semaphore *sem, int count)
{
    sem->count = count;
    pthread_mutex_init(&sem->mutex, NULL);
    pthread_cond_init(&sem->cond, NULL);
}

void signal(struct My_semaphore *sem)
{
    pthread_mutex_lock(&sem->mutex);
    sem->count++;
    if (sem->count == 1)
    {
        pthread_cond_signal(&sem->cond);
    }
    pthread_mutex_unlock(&sem->mutex);
}

void wait(struct My_semaphore *sem)
{
    pthread_mutex_lock(&sem->mutex);
    while (sem->count == 0)
    {
        pthread_cond_wait(&sem->cond, &sem->mutex);
    }
    sem->count--;
    pthread_mutex_unlock(&sem->mutex);
}

int f;
struct My_semaphore *Fork;

void *dinner(void *args)
{
    int i = *(int *)args;
    while (1)
    {
        printf("Philospher %d is ready to eat.\n", i);
        if (i % 2 == 0)
        {
            wait(&Fork[i]);
            wait(&Fork[(i + 1) % f]);
        }
        else
        {
            wait(&Fork[(i + 1) % f]);
            wait(&Fork[i]);
        }
       
        printf("Philospher %d is currently eating using forks %d and %d. \n", i, (i + 1) % f, i);
        printf("Philospher %d is done eating. \n\n", i);
        sleep(1);
    
        if (i % 2 == 0)
        {
            signal(&Fork[(i + 1) % f]);
            signal(&Fork[i]);
        }
        else
        {
            signal(&Fork[i]);
            signal(&Fork[(i + 1) % f]);
        }
    }
}

void main()
{
    f = 5;
    printf("%s\n", "Welcome to the dinner. ");

    Fork = (struct My_semaphore *)malloc(sizeof(struct My_semaphore) * f);
    if (Fork == NULL)
    {
        printf("%s\n", "Out of memory error...");
        return;
    }

    pthread_t philospers[f];

    for (int i = 0; i < f; i++)
    {
        init(&Fork[i], 1);
    }

    for (int i = 0; i < f; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        pthread_create(&philospers[i], NULL, &dinner, a);
    }

    for (int i = 0; i < f; i++)
    {
        pthread_join(philospers[i], NULL);
    }
    return;
}
