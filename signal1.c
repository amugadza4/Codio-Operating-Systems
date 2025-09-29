/* signal1.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t sig_received = 0; // global flag

void handler(int signum)
{
    printf("Hello World!\n");
    sig_received = 1; // signal received
}

int main()
{
    signal(SIGALRM, handler); // register handler
    alarm(5);                  // schedule SIGALRM in 5 sec

    while (!sig_received) {
        ; // busy wait for signal
    }

    printf("Turing was right!\n");

    return 0;
}
