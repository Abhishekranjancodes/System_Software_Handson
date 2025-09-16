/*
============================================================================
Name: 1c.c
Author: Abhishek Ranjan
Description: Write c program to create the following types of files
		c. FIFO
Date: 13th Aug, 2025
============================================================================
*/

#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>

int main(){
	int f;
	f = mkfifo("tunnel", 0744);
	if(f != -1){
		printf("fifo file created sucessfully\n");
	}else{
		perror("fifo file creation not successful");
	}
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 1c.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
fifo file created sucessfully

===========================================================================
*/
