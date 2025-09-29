/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t seconds = 0;

void alarm_handler(int signum)
{
    seconds++;
    printf("Hello World!\n");
    alarm(1); // schedule next SIGALRM in 1 second
}

void sigint_handler(int signum)
{
    printf("\nTotal time: %d seconds\n", seconds);
    _exit(0); // exit immediately
}

int main()
{
    signal(SIGALRM, alarm_handler);
    signal(SIGINT, sigint_handler); // handle CTRL-C

    alarm(1); // first alarm in 1 second

    while (1) {
        pause(); // wait for signals
    }

    return 0;
}

