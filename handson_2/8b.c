/*
============================================================================
Name: 8b.c
Author: Abhishek Ranjan
Description: Program to catch the following signals using signal system call.
		b. SIGINT

Date: 27th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void handler(int sig){
	printf("CTRL+C has been pressed\n");
	printf("The caught signal is:%d\n",sig);
	exit(0);
}
int main(){
	signal(SIGINT,handler);
	while(1);
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 8b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
^CCTRL+C has been pressed
The caught signal is:2
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/

