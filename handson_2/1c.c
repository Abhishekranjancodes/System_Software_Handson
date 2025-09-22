/*
===============================================================================
Name: 1c.c
Author: Abhishek Ranjan
Description: Program to set a interval timer in 10sec and 10 micro second
		a.ITIMER_PROF

Date: 22nd Sept, 2025

===============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum) {
    printf("Timer expired \n");
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, handler);

    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1);

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 1c.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Timer expired 
Timer expired 
Timer expired 
^C
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 
===============================================================================
*/
