/*
============================================================================
Name: 30b.c
Author: Abhishek Ranjan
Description: Program to create a shared memory.
		b. attach with O_RDONLY and check whether you are able to overwrite.

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
    data = shmat(shmid, NULL, SHM_RDONLY); 

    printf("Enter the text to shared memory: ");
    scanf("%[^/n]",data);

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 30b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Enter the text to shared memory: i am trying to overwrite
Segmentation fault (core dumped)
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
