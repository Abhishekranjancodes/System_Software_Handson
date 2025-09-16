/*
============================================================================
Name: 1a.c
Author: Abhishek Ranjan
Description: Write c program to create the following types of files
		a.soft link
Date: 13th Aug, 2025
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(void){
	int f;
	f = symlink("answer.txt","linktoanswer");
	if(f == 0){
		printf("soft link created sucessfully\n");
	}
	else{
		perror("soft link creation failed");
	}
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 1a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
soft link created sucessfully

============================================================================
*/

