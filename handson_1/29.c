/*
============================================================================
Name: 29.c
Author: Abhishek Ranjan
Description: Program to get scheduling policy and modify the schefuling plicy
		

Date: 3rd Sept, 2025

============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
    int policy;
    struct sched_param param;
    policy = sched_getscheduler(0);
    sched_getparam(0, &param);

    printf("Current policy: %d\n", policy);
    param.sched_priority = 50;
    sched_setscheduler(0, SCHED_RR, &param);
    printf("Changed to SCHED_RR\n");
    policy = sched_getscheduler(0);
    printf("Current policy: %d\n", policy);

    sched_setscheduler(0, SCHED_FIFO, &param);
    printf("Changed to SCHED_FIFO\n");
    policy = sched_getscheduler(0);
    printf("Current policy: %d\n", policy);

}

/*
============================================================================
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 29.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ sudo ./a.out
Current policy: 0
Changed to SCHED_RR
Current policy: 2
Changed to SCHED_FIFO
Current policy: 1

============================================================================
*/
