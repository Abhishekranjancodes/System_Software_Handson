/*
============================================================================
Name: 4.c
Author: Abhishek Ranjan
Description: Write a c program to open an existing file with read and write mode
		and try O_EXCL flag also.
Date: 14th Aug, 2025
============================================================================
*/
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(){
	int fd;
	fd= open("file.txt",O_CREAT | O_EXCL | O_RDWR, 0744);
	if(fd !=-1){
		printf("file created successfully\n");
	}else{
		perror("file creation unsuccessful");
	}
	printf("file descripter value is: %d\n", fd);
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 4.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
file created successfully
file descripter value is: 3
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
file creation unsuccessful: File exists
file descripter value is: -1
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ 


===============================================================================

*/
