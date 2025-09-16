/*
============================================================================
Name: 1b.c
Author: Abhishek Ranjan
Description: Write c program to create the following types of files
		b.hard link
Date: 13th Aug, 2025
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	int f;
	f = link("answer.txt", "solution.txt");
	if(f != -1){
		printf("Hard link created successfully\n");
	}else{
		perror("Hard link creation failed");
	}
}

/*
============================================================================
output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 1b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
Hard link created successfully

============================================================================
*/
