#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void doSomethingInFather(int working);
void doSomethingInChild(int working);

int main () {
    const int index = 42;

    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork error: ");
    } else if (pid > 0){
        doSomethingInFather(index);
    } else {
        doSomethingInChild(index);
    }

    return EXIT_SUCCESS;
}

void doSomethingInFather(int working) {
    printf("I'm the father, and I have %d apple(s).\n", working);
    sleep(2);
    return;
}

void doSomethingInChild(int working) {
    working = 42;
	execl("./say_yes.sh","say_yes.sh", NULL);
    printf("Something that will never be printed.\n");
    return;
}
