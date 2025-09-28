/*
============================================================================
Name: 8e.c
Author: Abhishek Ranjan
Description: Program to catch the following signals using signal system call.
		e. SIGALRM(using setitimer system call)

Date: 27th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/time.h>

void handler(int sig){
	printf("Time has been expired!\n");
	printf("The caught signal is:%d\n",sig);

}
int main(){
	struct itimerval timer;
	signal(SIGALRM,handler);
	
	timer.it_value.tv_sec = 2;     
    	timer.it_value.tv_usec = 0;
    	timer.it_interval.tv_sec = 2;   
    	timer.it_interval.tv_usec = 0;

    	setitimer(ITIMER_REAL, &timer, NULL); 
    
	while(1);
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 8e.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Time has been expired!
The caught signal is:14
Time has been expired!
The caught signal is:14
Time has been expired!
The caught signal is:14
Time has been expired!
The caught signal is:14
^C
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

===============================================================================
*/

