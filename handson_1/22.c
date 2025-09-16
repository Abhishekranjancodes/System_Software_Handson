/*
============================================================================
Name: 22.c
Author: Abhishek Ranjan
Description: Program to open a file, call fork, and then write to the file by
		both the child as well as the parent process

Date: 25th Aug, 2025

============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd;
	fd = open("dummy.txt", O_RDWR);
	if(!fork()){
		write(fd,"Writing this sentence from child process\n",42);
	}
	else{
		write(fd,"Writing this sentence from parent process\n",42);
	}
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cat dummy.txt
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 22.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cat dummy.txt
Writing this sentence from parent process
Writing this sentence from child process

============================================================================
*/
