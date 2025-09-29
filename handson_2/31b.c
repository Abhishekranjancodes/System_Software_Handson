/*
============================================================================
Name: 31b.c
Author: Abhishek Ranjan
Description: Program to create a semaphore and initialize value to the semaphore.
		b. create a counting semaphore

Date: 29th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    key_t key;
    int semid;
    union semun sem_union;

    key = ftok("abhishek", 'a');
    semid = semget(key, 1, IPC_CREAT | 0666);

    sem_union.val = 3;          
    semctl(semid, 0, SETVAL, sem_union);

    printf("Counting semaphore created with ID = %d and value = 3\n", semid);

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x610602a6 0          oldfish    744        1         

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 31b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Counting semaphore created with ID = 1 and value = 3
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x610602a6 0          oldfish    744        1         
0xffffffff 1          oldfish    666        1         

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/


