// 必须会！！！！！

// 面试题目
//三个线程分别打印 A，B，C，要求这三个线程一起运行，打印 n 次，输出形如“ABCABCABC....”的字符串


//分析
//这段代码实现了三个线程按照特定顺序打印字母 A、B、C。然而，存在一个问题，即死锁的风险。
//
//让我们详细分析一下：
//在 printA、printB 和 printC 函数中，我们使用了 pthread_cond_wait(&cond, &mutex)
// 来等待条件变量 cond 的信号。这会释放互斥锁 mutex 并挂起线程，直到其他线程发送信号。
//然后，我们在每个线程中使用 pthread_cond_signal(&cond) 来发送信号，以唤醒其他线程。
//问题在于，如果线程 A 先获得互斥锁 mutex，并且在等待条件变量 cond 的时候被挂起，
// 那么线程 B 和线程 C 将无法获得互斥锁，因为它们都在等待 mutex。
//这样，所有线程都被阻塞，形成了死锁。
//为了解决这个问题，我们可以使用 pthread_cond_broadcast(&cond) 来发送信号，
// 而不是 pthread_cond_signal(&cond)。这样，所有等待条件变量的线程都会被唤醒，而不仅仅是一个线程。这样，我们就可以避免死锁的情况。
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
        //pthread_cond_signal(&cond);
        pthread_cond_broadcast(&cond);  // 使用 broadcast 而不是 signal
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
        //pthread_cond_signal(&cond);
        pthread_cond_broadcast(&cond);  // 使用 broadcast 而不是 signal
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
        //pthread_cond_signal(&cond);
        pthread_cond_broadcast(&cond);  // 使用 broadcast 而不是 signal
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

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
