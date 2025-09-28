/*
============================================================================
Name: 10c.c
Author: Abhishek Ranjan
Description: Program to catch the fillowing signals using sigaction system call
		b.SIGFPE

Date: 28th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void handler(){
	printf("Floating point exception has been occured!\n");
	exit(0);
}
int main(){
	struct sigaction sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGFPE, &sa, NULL);

	int a = 5/0;

	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 10c.c
10c.c: In function ‘main’:
10c.c:30:18: warning: division by zero [-Wdiv-by-zero]
   30 |         int a = 5/0;
      |                  ^
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Floating point exception has been occured!
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

===============================================================================
*/

