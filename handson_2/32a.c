/*
============================================================================
Name: 32a.c
Author: Abhishek Ranjan
Description: Program to implement semaphore to protect any critical section
		a. rewrite the ticket number creation program using semaphore.

Date: 29th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    int fd;
    struct {
	    int ticket_no;
    } db;

    key_t key;
    int semid;
    struct sembuf p, v;
    union semun sem_union;


    db.ticket_no = 17;


    key = ftok(".", 'a');
    semid = semget(key, 1, IPC_CREAT | 0766);
    sem_union.val = 1;          
    semctl(semid, 0, SETVAL, sem_union);
    p.sem_num = 0;
    p.sem_op = -1;
    p.sem_flg = 0;
    semop(semid, &p, 1);


    fd = open("db", O_CREAT | O_RDWR, 0744);
    write(fd, &db, sizeof(db));
    close(fd);


    fd = open("db", O_RDONLY);
    read(fd, &db, sizeof(db));
    printf("Ticket no: %d\n", db.ticket_no);
    close(fd);

    
    v.sem_num = 0;
    v.sem_op = 1;
    v.sem_flg = 0;
    semop(semid, &v, 1);

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 32a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Ticket no: 17
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 
===============================================================================
*/
