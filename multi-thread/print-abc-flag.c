//
// Created by Administrator on 2023/12/27.
//

#include <stdio.h>
#include <pthread.h>

int count = 0;
int n = 10;
int flag = 0;

void* printA(void* arg) {
    for (int i = 0; i < n; i++) {
        while (flag != 0) {
            // Wait for flag to be 0
        }
        printf("A");
        flag = 1;
    }
    pthread_exit(NULL);
}

void* printB(void* arg) {
    for (int i = 0; i < n; i++) {
        while (flag != 1) {
            // Wait for flag to be 1
        }
        printf("B");
        flag = 2;
    }
    pthread_exit(NULL);
}

void* printC(void* arg) {
    for (int i = 0; i < n; i++) {
        while (flag != 2) {
            // Wait for flag to be 2
        }
        printf("C\n");
        flag = 0;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threadA, threadB, threadC;

    pthread_create(&threadA, NULL, printA, NULL);
    pthread_create(&threadB, NULL, printB, NULL);
    pthread_create(&threadC, NULL, printC, NULL);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    return 0;
}
