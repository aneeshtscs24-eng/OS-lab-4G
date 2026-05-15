#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N];

void* philosopher(void* num) {
    int id = *(int*)num;

    while(1) {
        printf("Philosopher %d is thinking\n", id);
        sleep(1);

        sem_wait(&forks[id]);
        printf("Philosopher %d picked up left fork\n", id);

        sem_wait(&forks[(id + 1) % N]);
        printf("Philosopher %d picked up right fork\n", id);

        printf("Philosopher %d is eating\n", id);
        sleep(2);

        sem_post(&forks[id]);
        sem_post(&forks[(id + 1) % N]);

        printf("Philosopher %d released forks\n", id);
    }
}

int main() {
    pthread_t phil[N];
    int ids[N];

    for(int i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
    }

    for(int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&phil[i], NULL, philosopher, &ids[i]);
    }

    for(int i = 0; i < N; i++) {
        pthread_join(phil[i], NULL);
    }

    return 0;
}
