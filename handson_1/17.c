/*
============================================================================
Name: 17.c
Author: Abhishek Ranjan
Description: Program to open a file, store a ticket number and exit.

Date: 14th Aug, 2025

============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(){
	int fd;
	struct{
		int ticket_no;
	}db;

	db.ticket_no = 17;
	fd = open("db", O_CREAT|O_RDWR, 0744);
	write(fd, &db, sizeof(db));
	close(fd);
	fd = open("db", O_RDONLY);
	read(fd, &db, sizeof(db));
	printf("Ticket no: %d\n", db.ticket_no);
	close(fd);
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 17.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
Ticket no: 17

============================================================================
*/
