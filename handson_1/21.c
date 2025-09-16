/*
============================================================================
Name: 21.c
Author: Abhishek Ranjan
Description: Program to call fork and print the parent and child process id.

Date: 25th Aug, 2025

============================================================================
*/



#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	if(!fork()){
		printf("Inside child process:\n");
		printf("Child process id:%d and parent process id:%d\n",getpid(),getppid());

	}
	else{
		printf("Insid parent process:\n");
		printf("Parent process id:%d\n",getpid());
		wait(0);
	}
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 21.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
Insid parent process:
Parent process id:26237
Inside child process:
Child process id:26238 and parent process id:26237

============================================================================
*/

