/*
============================================================================
Name: 32d.c
Author: Abhishek Ranjan
Description: Program to implement semaphore to protect any critical section.
		d. remove the created semaphore.

Date: 29th sept, 2025
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

int main() {
    key_t sem_key = ftok(".", 'b');      
    int semid = semget(sem_key, 1, 0744); 

    semctl(semid, 0, IPC_RMID, 0);    

    printf("Semaphore removed successfully.\n");
    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 32d.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x610602a6 0          oldfish    744        1         
0xffffffff 1          oldfish    666        1         
0x620602a6 2          oldfish    744        1         

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Semaphore removed successfully.
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x610602a6 0          oldfish    744        1         
0xffffffff 1          oldfish    666        1         

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
