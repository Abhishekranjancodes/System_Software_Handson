/*
============================================================================
Name: 16a.c
Author: Abhishek Ranjan
Description: Program to perform mandatory locking.
                a. Implement write lock

Date: 21st Aug, 2025
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	struct flock lock;
	int fd;
	fd = open("dummy.txt",O_RDWR);
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len  = 0;
	lock.l_pid = getpid();
	printf("Entering into critical section\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Inside critical section\n");
	printf("press any button to exit\n");
	getchar();
	printf("outside critical section\n");
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLKW, &lock);
	printf("Critical Section Unlocked sucessfully\n");
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 16a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
Entering into critical section
Inside critical section
press any button to exit

outside critical section
Critical Section Unlocked sucessfully

============================================================================
*/

