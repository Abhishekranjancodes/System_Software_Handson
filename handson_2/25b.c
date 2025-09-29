/*
============================================================================
Name: 25b.c
Author: Abhishek Ranjan
Description: Program to print a message queue's
		b. uid, gid

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
    msgid = msgget(key, IPC_CREAT |  0744);
    msgctl(msgid, IPC_STAT, &info);

    printf("Message Queue UID and GID is: \n");
    printf("  UID : %d\n", info.msg_perm.uid);
    printf("  GID : %d\n", info.msg_perm.gid);

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 25b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Message Queue UID and GID is: 
  UID : 1000
  GID : 1000
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
