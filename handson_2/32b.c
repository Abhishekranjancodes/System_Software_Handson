/*
============================================================================
Name: 32b.c
Author: Abhishek Ranjan
Description: Program to implement semaphore to protect any critical section.
		b. protect shared memory from concurrent write access

Date: 29th sept, 2025
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
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

    int semid = semget(sem_key, 1, IPC_CREAT | 0744);   
    union semun sem_union;
    sem_union.val = 1;
    semctl(semid, 0, SETVAL, sem_union);

    struct sembuf p = {0, -1, 0};  
    struct sembuf v = {0, 1, 0};   

    
    semop(semid, &p, 1);
    printf("Enter text to be written:\n");
    scanf("%[^\n]",data);

    sleep(2);                    
    semop(semid, &v, 1);          

    shmdt(data);

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 32b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Enter text to be written:
Hello ji!
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 6          oldfish    600        524288     2          dest         
0x00000000 32775      oldfish    600        4194304    2          dest         
0x00000000 32784      oldfish    600        524288     2          dest         
0x00000000 22         oldfish    600        524288     2          dest         
0x00000000 23         oldfish    600        4194304    2          dest         
0x00000000 26         oldfish    600        524288     2          dest         
0x610602a6 32800      oldfish    744        1024       0                       
0x00000000 35         oldfish    600        524288     2          dest         
0x00000000 37         oldfish    600        1048576    2          dest         
0x00000000 38         oldfish    600        33554432   2          dest         

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
