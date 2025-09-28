/*
============================================================================
Name: 8f.c
Author: Abhishek Ranjan
Description: Program to catch the following signals using signal system call.
		f. SIGVTALRM(using setitimer system call)

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
	signal(SIGVTALRM,handler);
	
	timer.it_value.tv_sec = 1;     
    	timer.it_value.tv_usec = 0;
    	timer.it_interval.tv_sec = 1;   
    	timer.it_interval.tv_usec = 0;

    	setitimer(ITIMER_VIRTUAL, &timer, NULL); 
    
	while(1){
		for(int i=0;i<1000;i++);
	}
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 8f.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Time has been expired!
The caught signal is:26
Time has been expired!
The caught signal is:26
Time has been expired!
The caught signal is:26
Time has been expired!
The caught signal is:26
^C
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 


===============================================================================
*/

