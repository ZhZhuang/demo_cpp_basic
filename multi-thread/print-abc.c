// 会死锁！！！

// 分析原因！！！！！！

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int count = 0;
int n = 10;

void* printA(void* arg) {
    for (int i = 0; i < n; i++) {
        pthread_mutex_lock(&mutex);
        while (count % 3 != 0) {    // 当信号到来是 count 的值会改变
            pthread_cond_wait(&cond, &mutex);
        }
        printf("A");
        count++;
        pthread_cond_signal(&cond);
        //pthread_cond_broadcast(&cond);  // 使用 broadcast 而不是 signal
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void* printB(void* arg) {
    for (int i = 0; i < n; i++) {
        pthread_mutex_lock(&mutex);
        while (count % 3 != 1) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("B");
        count++;
        pthread_cond_signal(&cond);
        //pthread_cond_broadcast(&cond);  // 使用 broadcast 而不是 signal
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void* printC(void* arg) {
    for (int i = 0; i < n; i++) {
        pthread_mutex_lock(&mutex);
        while (count % 3 != 2) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("C");
        count++;
        pthread_cond_signal(&cond);
        //pthread_cond_broadcast(&cond);  // 使用 broadcast 而不是 signal
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threadA, threadB, threadC;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&threadA, NULL, printA, NULL);
    pthread_create(&threadB, NULL, printB, NULL);
    pthread_create(&threadC, NULL, printC, NULL);

    pthread_cond_broadcast(&cond);  // 使用 broadcast 而不是 signal

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
