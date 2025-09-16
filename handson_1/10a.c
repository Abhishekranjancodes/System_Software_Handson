/*
============================================================================
Name: 10a.c
Author: Abhishek Ranjan
Description: Write a c program to open a file with read write mode,write 10
		bytes,move the file pointer by 10 bytes and write again 10 
		bytes.
		a. check the return value of lseek
Date: 18th Aug, 2025
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main(){
	int fd;
	fd = open("dummy.txt",O_RDWR);
	char buf[100];
	read(fd,buf,10);
	write(1,buf,10);
	write(1,"\n",1);
	int val = lseek(fd,10,SEEK_SET);
	read(fd,buf,10);
	write(1,buf,10);
	printf("\nReturn value of lseek is: %d\n",val);
	return 0;
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 10a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
I am writt
en in dumm
Return value of lseek is: 10

============================================================================
*/
