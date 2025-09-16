/*
============================================================================
Name: 12.c
Author: Abhishek Ranjan
Description: program to find out the opening mode of a file using fcntl.

Date: 1st Sept, 2025
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main(){
	int fd;
	fd = open("dummy1.txt", O_RDONLY);
	int f;
	f = fcntl(fd, F_GETFL);
	int n;
	n = f & 003;
	if(n == 0){
		printf("opened in Read only mode\n");
	}else if(n == 1){
		printf("opened in Write only mode\n");
	}else if(n == 2){
		printf("opened in Read write mode\n");
	}
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 12.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
opened in Read only mode

============================================================================
*/
