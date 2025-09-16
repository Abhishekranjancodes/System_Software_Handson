/*
============================================================================
Name: 3.c
Author: Abhishek Ranjan
Description: Write a c program to create a file and print the file descriptor value
		Use creat() system call
Date: 14th Aug, 2025
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


void main(){
	int fd;
	fd = creat("file.txt", 0744);
	if(fd>0){
		printf("file creation successful\n");
	}else{
		perror("file creation unsuccessful");
	}
	printf("file descripter value is: %d\n",fd);
}

/*
=================================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 3.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
file creation successful
file descripter value is: 3

=================================================================================

*/
