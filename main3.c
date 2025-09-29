#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    pid_t pid1, pid2;
    int status;

    // Seed random number generator
    srand(time(NULL));

    // Fork first child
    pid1 = fork();
    if (pid1 == 0) { // Child 1
        int iterations = rand() % 30 + 1;
        for (int i = 0; i < iterations; i++) {
            printf("Child Pid: %d is going to sleep!\n", getpid());
            sleep(rand() % 10 + 1);
            printf("Child Pid: %d is awake! Where is my Parent: %d?\n", getpid(), getppid());
        }
        exit(0);
    }

    // Fork second child
    pid2 = fork();
    if (pid2 == 0) { // Child 2
        int iterations = rand() % 30 + 1;
        for (int i = 0; i < iterations; i++) {
            printf("Child Pid: %d is going to sleep!\n", getpid());
            sleep(rand() % 10 + 1);
            printf("Child Pid: %d is awake! Where is my Parent: %d?\n", getpid(), getppid());
        }
        exit(0);
    }

    // Parent waits for both children
    waitpid(pid1, &status, 0);
    printf("Child Pid: %d has completed\n", pid1);
    waitpid(pid2, &status, 0);
    printf("Child Pid: %d has completed\n", pid2);

    return 0;
}

