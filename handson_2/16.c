/*
============================================================================
Name: 16.c
Author: Abhishek Ranjan
Description: Program to send and receive data from parent to child and vice versa.
		using two way communication.

Date: 28th sept, 2025
============================================================================
*/


#include<stdio.h>
#include<unistd.h>

int main(){
	char buf1[100];
	char buf2[100];
	int fd1[2];
	int fd2[2];
	pipe(fd1);
	pipe(fd2);
	if(!fork()){
		close(fd1[1]);
		close(fd2[0]);
		write(fd2[1],"Namaste_parent",15);
		read(fd1[0],buf1,13);
		printf("Message from Patent:%s\n", buf1);
	}else{
		close(fd1[0]);
		close(fd2[1]);
		read(fd2[0],buf2,15);
		write(fd1[1],"Namaste_child",13);
		printf("Messsage from child: %s\n", buf2);
	}
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 16.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Messsage from child: Namaste_parent
Message from Patent:Namaste_child
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/

