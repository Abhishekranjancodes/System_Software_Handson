/*
============================================================================
Name: 32c.c
Author: Abhishek Ranjan
Description: Program to implement semaphore to protect any critical section.
		c. protect multiple pseudo resources(may be two) using counting
		semaphore.

Date: 29th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main() {
    key_t shm_key = ftok(".", 'a');
    key_t sem_key = ftok(".", 'b');


    int shmid = shmget(shm_key, 1024, IPC_CREAT | 0744);
    char *data = (char *) shmat(shmid, NULL, 0);


    int semid = semget(sem_key, 1, IPC_CREAT | 0666);
    union semun sem_union;
    sem_union.val = 2;      
    semctl(semid, 0, SETVAL, sem_union);

    struct sembuf p = {0, -1, 0};  
    struct sembuf v = {0, 1, 0};   

    printf("Trying to enter critical section...\n");
    semop(semid, &p, 1);            

    
    printf("Using a resource\n");
    printf("write the text: ");
    scanf("%[^\n]",data);
    sleep(2);                        

    semop(semid, &v, 1);            
    printf("Released a resource\n");

    shmdt(data);

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 32c.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Trying to enter critical section...
Using a resource
write the text: hello ji!
Released a resource
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

===============================================================================
*/
