// compile: g++ ‐‐std=c++11 ‐lpthread mutex_deadlock.cpp
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

int main(void) {
    pthread_t t;
    pthread_create(&t, nullptr, doit, nullptr);

    if (fork() == 0) {
        doit(nullptr);
        return 0;
    }
    pthread_join(t, 0);

    return 0;
}
