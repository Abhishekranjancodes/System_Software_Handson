/*
============================================================================
Name: 11a.c
Author: Abhishek Ranjan
Description: Write a c program to open a file, duplicate and append the file
		with both the descriptors and check whter the file is updated
		properly or not.
		a. use dup.
Date: 28th Aug, 2025
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
	int fd;
	fd = open("dummy1.txt",O_RDWR | O_CREAT, 0744);
	printf("Old fd was: %d\n",fd);
	int newfd;
	newfd = dup(fd);
	printf("New fd created is: %d\n",newfd);
	const char* temp = "I am writing using newfd\n";
	write(newfd,temp, strlen(temp));
	const char* temp2 ="I am writing using old fd\n";
	write(fd, temp2, strlen(temp2));
	return 0;
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 11a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
Old fd was: 3
New fd created is: 4
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cat dummy1.txt
I am writing using newfd
I am writing using old fd

============================================================================
*/
