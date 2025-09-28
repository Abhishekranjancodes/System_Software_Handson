/*
============================================================================
Name: 12.c
Author: Abhishek Ranjan
Description: Program to create an orphan process, using kill system call to
		send SIGKILL signal to the parent process from the child process

Date: 28th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int main(){
	if(!fork()){
		printf("Inside chid process having pid:%d, and ppid:%d\n",getpid(),getppid());
		printf("Sending kill signal to parent\n");
		kill(getppid(),SIGKILL);
		sleep(3);
		printf("Now my parent pid is:%d\n",getppid());
		exit(0);
	}else{
		printf("Inside parent process\n");
		sleep(10);
	}
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 12.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Inside parent process
Inside chid process having pid:9617, and ppid:9616
Sending kill signal to parent
Killed
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ Now my parent pid is:2150

===============================================================================
*/
