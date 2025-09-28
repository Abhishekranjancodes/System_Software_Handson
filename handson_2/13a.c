/*
============================================================================
Name: 13a.c
Author: Abhishek Ranjan
Description: Program to waiting to catch SIGSTOP signal(but SIGSTOP can never be 
		caught, so my handler will never work)

Date: 28th sept, 2025
============================================================================
*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void handler(){
	printf("SIGSTOP has been caught\n");
	printf("SIGSTOP signal have been received\n");
	exit(0);

}

int main(){
	signal(SIGSTOP,handler);
	printf("waiting for SIGSTOP signal\n");
	while(1);
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 13a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out &
[1] 10390
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ waiting for SIGSTOP signal
^C

[1]+  Stopped                 ./a.out

===============================================================================
*/
