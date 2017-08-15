// compile: g++ ‐‐std=c++11 ‐lpthread mutex_deadlock_fix.cpp
// execute: ./a.out

#include <iostream>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

using namespace std;


void* doit(void*) {
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);
    struct timespec ts = {20, 0};
    nanosleep(&ts, 0);
    pthread_mutex_unlock(&mutex);
    return 0;
}

void prepare(void) {
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);
}

void parent(void) {
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_unlock(&mutex);
}

void child(void) {
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_unlock(&mutex);
}

int main(void) {
    pthread_atfork(prepare, parent, child);

    pthread_t t;
    pthread_create(&t, nullptr, doit, nullptr);

    if (fork() == 0) {
        doit(nullptr);
        return 0;
    }
    pthread_join(t, 0);

    return 0;
}
