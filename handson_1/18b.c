/*
============================================================================
Name: 18b.c
Author: Abhishek Ranjan
Description: Write a program to perform Record locking.
		b. Implement read lock
		Create three records in a file. Whenever you access a particular
		record, first lock it then modify/access
		to avoid race condition.
Date: 20th sep, 2025
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>



int main() {
    int fd;
    char buffer[40];

    fd = open("record.txt", O_RDWR | O_CREAT, 0744);

    write(fd, "This is initial content of the record 0\n", 40);
    write(fd, "This is initial content of the record 1\n", 40);
    write(fd, "This is initial content of the record 2\n", 40);

    int recno;
    printf("Enter record number to access (0-2): ");
    scanf("%d", &recno);
    getchar();


    struct flock lock;
    lock.l_type = F_RDLCK;                 
    lock.l_whence = SEEK_SET;
    lock.l_start = recno * 40;   
    lock.l_len = 40;              
    lock.l_pid = getpid();

    printf("Process %d: Trying to lock record %d...\n", getpid(), recno);
    fcntl(fd, F_SETLKW, &lock);            
    printf("Process %d: Locked record %d\n", getpid(), recno);

    lseek(fd, recno * 40, SEEK_SET);
    read(fd, buffer, 40);
    printf("Current Record[%d]: %s\n", recno, buffer);

    getchar();

    printf("Unlocking the record no:%d\n",recno);

    lock.l_type = F_UNLCK;               
    lock.l_whence = SEEK_SET;
    lock.l_start = recno * 40;
    lock.l_len = 40;
    lock.l_pid = getpid();

    fcntl(fd, F_SETLK, &lock);
    printf("Process %d: Unlocked record %d\n", getpid(), recno);

    close(fd);
    return 0;
}

/*
============================================================================
Output:
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_1$ cc 18b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_1$ ./a.out
Enter record number to access (0-2): 0
Process 11345: Trying to lock record 0...
Process 11345: Locked record 0
Current Record[0]: This is initial content of the record 0


Unlocking the record no:0
Process 11345: Unlocked record 0
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_1$

============================================================================
*/
