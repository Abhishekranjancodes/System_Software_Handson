/*
============================================================================
Name: 6.c
Author: Abhishek Ranjan
Description: Write a c program to take input from STDIN and display on STDOUT.
		using only read/write system call.
Date: 14th Aug, 2025
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

void main(){
	char buf[100];
	int s;
	s = read(0,buf, sizeof(buf));
	write(1,buf,s);
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 6.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
Hi,this is Abhishek Ranjan!
Hi,this is Abhishek Ranjan!
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$

============================================================================
*/
