/*
============================================================================
Name: 13.c
Author: Abhishek Ranjan
Description: Program to wait for a STDIN for 10 seconds using select.

Date: 1st Sept, 2025
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/select.h>

void main(){
	fd_set rfds;
	struct timeval tv;
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);
	tv.tv_sec = 10;
	tv.tv_usec = 0;
	int n = select(1, &rfds, NULL, NULL, &tv);
	if(n == -1){
		perror("Some error occured");
	}else if(n){
		printf("Data is available for reading within 10 seconds\n");
	}else{
		printf("Data is not available for reading whithin 10 seconds\n");
	}
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 13.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out

Data is available for reading within 10 seconds
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ 
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
Data is not available for reading whithin 10 seconds

============================================================================
*/
