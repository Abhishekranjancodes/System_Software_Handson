/*
============================================================================
Name: 17_increment_ticket_no.c
Author: Abhishek Ranjan
Description: Program to open a file, implement write lock, read the ticket
		number, increment the number and print the new ticket number
		then clsoe the file.

Date: 14th Aug, 2025

============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(){
	struct {
		int ticket_no;
	}db;
	struct flock lock;
	int fd;
	fd = open("db", O_RDWR);
	printf("Entering Critical section\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Inside critical section\n");
	read(fd, &db, sizeof(db));
	printf("Currnt ticket number: %d\n", db.ticket_no);
	db.ticket_no++;
	lseek(fd,0, SEEK_SET);
	write(fd, &db, sizeof(db));
	printf("Press any button to unlock\n");
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("Outside Critical Section\n");
	lseek(fd, 0, SEEK_SET);
	printf("Ticket number after increment is:%d\n",db.ticket_no);
	close(fd);

}

/*
============================================================================
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 17_increment_ticket_no.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
Entering Critical section
Inside critical section
Currnt ticket number: 17
Press any button to unlock

Outside Critical Section
Ticket number after increment is:18

============================================================================
*/
