/*
============================================================================
Name: 25g.c
Author: Abhishek Ranjan
Description: Program to print a message queue's
		g. maximum number of bytes allowed

Date: 29th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds info;

    key = ftok(".", 'a');
    msgid = msgget(key, IPC_CREAT | 0744);
    msgctl(msgid, IPC_STAT, &info);

    printf("Maximum number of bytes allowed : %lu\n", info.msg_qbytes);
    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 25g.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Maximum number of bytes allowed : 16384
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
