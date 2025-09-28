/*
============================================================================
Name: 8a.c
Author: Abhishek Ranjan
Description: Program to catch the following signals using signal system call.
		a. SIGSEGV

Date: 27th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void handler(int sig){
	printf("The caught signal is:%d\n",sig);
	exit(0);
}
int main(){
	signal(SIGSEGV,handler);
	int *ptr = NULL;
	*ptr = 5;
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 8a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
The caught signal is:11
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
