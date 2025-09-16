/*
============================================================================
Name: 11c.c
Author: Abhishek Ranjan
Description: Write a c program to open a file, duplicate and append the file
		with both the descriptors and check whter the file is updated
		properly or not.
		c. use fcntl.
Date: 1st Sept, 2025
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(){
	int fd1,fd2;
	fd1 = open("dummy1.txt",O_RDWR | O_CREAT, 0744);
	fd2 = fcntl(fd1, F_DUPFD, 1);
	printf("New fd created is: %d\n",fd2);
	const char* temp = "I am writing using newfd duplicated by fcntl\n";
	write(fd2,temp, strlen(temp));
	const char* temp2 ="I am writing using old fd\n";
	write(fd1, temp2, strlen(temp2));
	return 0;
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 11c.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
New fd created is: 4
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cat dummy1.txt
I am writing using newfd duplicated by fcntl
I am writing using old fd

============================================================================
*/
