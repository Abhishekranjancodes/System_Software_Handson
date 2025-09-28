/*
============================================================================
Name: 15.c
Author: Abhishek Ranjan
Description: Program to send some data from parent to the child process

Date: 28th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	int fd[2];
	char buf[100];
	pipe(fd);
	if(!fork()){
		close(0);
		dup(fd[0]);
		close(fd[1]);
		read(fd[0],buf,sizeof(buf));
		printf("message:%s\n",buf);
	}else{
		close(1);
		dup(fd[1]);
		close(fd[0]);
		write(fd[1],"Abhishek_Ranjan",16);
	}
}
/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 15.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
message:Abhishek_Ranjan
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
