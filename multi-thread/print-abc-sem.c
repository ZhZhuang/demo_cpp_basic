//
// Created by Administrator on 2023/12/27.
//

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semA, semB, semC;

void* printA(void* arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&semA);
        printf("A");
        sem_post(&semB);
    }
    pthread_exit(NULL);
}

void* printB(void* arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&semB);
        printf("B");
        sem_post(&semC);
    }
    pthread_exit(NULL);
}

void* printC(void* arg) {
    for (int i = 0; i < 10; i++) {
        sem_wait(&semC);
        printf("C");
        sem_post(&semA);
    }
    pthread_exit(NULL);
}

int main() {
    sem_init(&semA, 0, 1);
    sem_init(&semB, 0, 0);
    sem_init(&semC, 0, 0);

    pthread_t threadA, threadB, threadC;
    pthread_create(&threadA, NULL, printA, NULL);
    pthread_create(&threadB, NULL, printB, NULL);
    pthread_create(&threadC, NULL, printC, NULL);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    sem_destroy(&semA);
    sem_destroy(&semB);
    sem_destroy(&semC);

    return 0;
}
