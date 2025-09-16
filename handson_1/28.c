/*
============================================================================
Name: 28.c
Author: Abhishek Ranjan
Description: Program to get maximum and minimum real time priority.

Date: 1st Sept, 2025

============================================================================
*/

#include<stdio.h>
#include<sched.h>

int main(){
        printf("Maximum Real time priority is:%d\n", sched_get_priority_max(SCHED_RR));
	printf("Minimum Real time priority is:%d\n", sched_get_priority_min(SCHED_RR));
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 28.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
Maximum Real time priority is:99
Minimum Real time priority is:1

============================================================================
*/


