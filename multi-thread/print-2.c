//
// Created by Administrator on 2023/12/27.
//

//2. 两个线程交替打印 0~100 的奇偶数

// 自带同步效果

#include<stdio.h>
#include <pthread.h>
#include <unistd.h>

int num=0;

void *thread1(void *arg){
    while (num<=100){
        if(num&1){
            printf("%d,pid:%lu \n",num,pthread_self());
            num++;
            //sleep(1);
        }
    }
    pthread_exit(NULL);
}

void *thread2(void *arg){
    while (num<=100){
        if( !(num&1) ){
            printf("%d,pid:%lu \n",num,pthread_self());
            num++;
        }
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t pid1,pid2;
    pthread_create(&pid1,NULL,thread1,NULL);
    pthread_create(&pid2,NULL,thread2,NULL);

    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);
    return 0;
}