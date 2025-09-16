/*
============================================================================
Name: 24.c
Author: Abhishek Ranjan
Description: Program to create an oprphan process.

Date: 25th Aug, 2025

============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	if(!fork()){
		printf("Inside child process:\n");
		printf("child's Parent process id before beign oprphan :%d\n",getpid());
		printf("Child is going to sleep for 30 second:\n");
		sleep(30);
		printf("child's parent process id after being orphan:%d\n",getppid());
	}else{
		printf("Inside parent process:\n");
		printf("Parent process id:%d\n",getpid());
		printf("parent exiting now\n");
		exit(0);
	}
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 24.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
Inside parent process:
Parent process id:29125
parent exiting now
Inside child process:
child's Parent process id before beign oprphan :29126
Child is going to sleep for 30 second:
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ child's parent process id after being orphan:1875

============================================================================
*/
