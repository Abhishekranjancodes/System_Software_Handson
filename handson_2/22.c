/*
============================================================================
Name: 22.c
Author: Abhishek Ranjan
Description: Program to wait for data to be written into FIFO within 10 seconds,
		using select system call with FIFO.

Date: 29th sept, 2025
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/select.h>

int main(){
	char buff[100];
	fd_set rfds;
	struct timeval tv;
	tv.tv_sec = 10;
	int fd = open("tunnel", O_RDONLY);
	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);
	if(!select(fd +1, &rfds,NULL,NULL, &tv))
		printf("No data is available for reading yet\n");
	else{
		printf("Data is avilable now\n");
		read(fd,buff, sizeof(buff));
		printf("Data from FIFO is : %s\n", buff);
	}
	return 0;
}
/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Data is avilable now
Data from FIFO is : hello fifo

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$
===============================================================================
