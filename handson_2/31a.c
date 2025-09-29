/*
============================================================================
Name: 31a.c
Author: Abhishek Ranjan
Description: Program to create a semaphore and initialize value to the semaphore.
		a. create a binary semaphore

Date: 29th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

int main() {
    key_t key;
    int semid;

    key = ftok(".", 'a');
    semid = semget(key, 1, IPC_CREAT | 0744);  

    semctl(semid, 0, SETVAL, 1); 

    printf("Binary semaphore has been created and initialized with 1. \n");

    return 0;
}
/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Binary semaphore has been created and initialized with 1. 
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x610602a6 0          oldfish    744        1         

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

===============================================================================
*/


