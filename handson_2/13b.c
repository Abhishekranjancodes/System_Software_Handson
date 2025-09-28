/*
============================================================================
Name: 13b.c
Author: Abhishek Ranjan
Description: Program to send the SIGSTOP signal using kill system call

Date: 28th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

int main(int argc, char*argv[]){
	int pid = atoi(argv[1]);
	printf("sending SIGSTOP singanl to the process:%d\n",pid);
	kill(pid, SIGSTOP);
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 13b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out 10390
sending SIGSTOP singanl to the process:10390
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
