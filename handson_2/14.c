/*
============================================================================
Name: 14.c
Author: Abhishek Ranjan
Description: Program to create a pipe,write to the pipe, read from pipe and
		display on the monitor.

Date: 28th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){

	int fd[2];
	pipe(fd);
	char buf[100];
	int bytes = write(fd[1],"Abhishek_Ranjan",16);
	read(fd[0],buf,bytes);
	printf("message:%s\n",buf);
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 14.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
message:Abhishek_Ranjan
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
