/*
============================================================================
Name: 10b.c
Author: Abhishek Ranjan
Description: Program to catch the fillowing signals using sigaction system call
		b.SIGINT

Date: 28th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void handler(){
	printf("CTRL+C has been pressed within 7 second\n");
	exit(0);
}
int main(){
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGINT, &sa, NULL);

	sleep(7);

	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 10b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
^CCTRL+C has been pressed within 7 second
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
