/*
============================================================================
Name: 23.c
Author: Abhishek Ranjan
Description: Program to create a zombie state of the running program.

Date: 25th Aug, 2025

============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>


int main(){
	if(!fork()){
		printf("child process exiting:%d\n",getpid());
		exit(0);
	}else{
		printf("Inside parent process:%d\n",getpid());
		printf("parent sleep for 30 sec,so child will be zombie for 30sec\n");
		sleep(30);
		printf("Parent process exiting now\n");
	}
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 23.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
Inside parent process:28340
parent will sleep for 30 second
child process exiting:28341
Parent process exiting now

============================================================================
*/


