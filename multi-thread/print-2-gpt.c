#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NUMBER 100

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int number = 0;

void *print_odd(void *arg) {
    while (number < MAX_NUMBER) {
        pthread_mutex_lock(&mutex);
        if (number % 2 == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d\n", number++);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *print_even(void *arg) {
    while (number < MAX_NUMBER) {
        pthread_mutex_lock(&mutex);
        if (number % 2 == 1) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d\n", number++);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    //pthread_cond_init(&cond,NULL);

    pthread_create(&tid1, NULL, print_odd, NULL);
    pthread_create(&tid2, NULL, print_even, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}
