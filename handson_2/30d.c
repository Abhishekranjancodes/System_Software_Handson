/*
============================================================================
Name: 30d.c
Author: Abhishek Ranjan
Description: Program to create a shared memory.
		d. remove the shared memory.

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
    shmctl(shmid,IPC_RMID,NULL);
    printf("shared memory remove successfully\n");

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 6          oldfish    600        524288     2          dest         
0x00000000 22         oldfish    600        524288     2          dest         
0x00000000 23         oldfish    600        4194304    2          dest         
0x00000000 26         oldfish    600        524288     2          dest         
0x00000000 35         oldfish    600        524288     2          dest         
0x00000000 37         oldfish    600        1048576    2          dest         
0x00000000 38         oldfish    600        33554432   2          dest         
0x00000000 56         oldfish    600        524288     2          dest         
0x610602a6 57         oldfish    744        1024       0                       

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 30d.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
shared memory remove successfully
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 6          oldfish    600        524288     2          dest         
0x00000000 22         oldfish    600        524288     2          dest         
0x00000000 23         oldfish    600        4194304    2          dest         
0x00000000 26         oldfish    600        524288     2          dest         
0x00000000 35         oldfish    600        524288     2          dest         
0x00000000 37         oldfish    600        1048576    2          dest         
0x00000000 38         oldfish    600        33554432   2          dest         
0x00000000 56         oldfish    600        524288     2          dest         

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$
===============================================================================
*/
