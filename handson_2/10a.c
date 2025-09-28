/*
============================================================================
Name: 10a.c
Author: Abhishek Ranjan
Description: Program to catch the fillowing signals using sigaction system call
		a. SIGSEGV

Date: 28th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void handler(){
	printf("There is a segmentation fault\n");
	exit(0);
}
int main(){
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGSEGV, &sa, NULL);

	int *p = NULL;
	*p = 5;

	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 10a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
There is a segmentation fault
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
