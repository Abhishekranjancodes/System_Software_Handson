/*
============================================================================
Name: 8c.c
Author: Abhishek Ranjan
Description: Program to catch the following signals using signal system call.
		c. SIGFPE

Date: 27th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void handler(int sig){
	printf("There is a Floating point Execption\n");
	printf("The caught signal is:%d\n",sig);
	exit(0);
}
int main(){
	signal(SIGFPE,handler);
	int a = 5/0;
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 8c.c
8c.c: In function ‘main’:
8c.c:23:18: warning: division by zero [-Wdiv-by-zero]
   23 |         int a = 5/0;
      |                  ^
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
There is a Floating point Execption
The caught signal is:8
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

===============================================================================
*/

