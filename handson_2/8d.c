/*
============================================================================
Name: 8d.c
Author: Abhishek Ranjan
Description: Program to catch the following signals using signal system call.
		d. SIGALRM(using alarm system call)

Date: 27th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void handler(int sig){
	printf("Time has been expired!\n");
	printf("The caught signal is:%d\n",sig);
	exit(0);
}
int main(){
	signal(SIGALRM,handler);
	alarm(4);
	while(1);
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 8d.c
8d.c: In function ‘main’:
8d.c:23:9: warning: implicit declaration of function ‘alarm’ [-Wimplicit-function-declaration]
   23 |         alarm(4);
      |         ^~~~~
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Time has been expired!
The caught signal is:14
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$  

===============================================================================
*/

