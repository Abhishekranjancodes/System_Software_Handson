/*
============================================================================
Name: 30c.c
Author: Abhishek Ranjan
Description: Program to create a shared memory.
		c. detach the shared memory

Date: 29th sept, 2025
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>

int main() {
    key_t key;
    int shmid;
    char *data;

    key = ftok(".", 'a');               
    shmid = shmget(key, 1024, IPC_CREAT | 0744);  
    data = shmat(shmid, NULL, 0); 

    printf("Data from the shared memory:%s\n ",data);
    shmdt(data);
    printf("shared memory detached successfully\n");

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 30c.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Data from the shared memory:Heyy! this is Abhishek Ra
 shared memory detached successfully
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
