/*
============================================================================
Name: 25d.c
Author: Abhishek Ranjan
Description: Program to print a message queue's
		d. time of last change in the message queue

Date: 29th sept, 2025
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <time.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds info;

    key = ftok(".", 'a');
    msgid = msgget(key, IPC_CREAT | 0744);
    msgctl(msgid, IPC_STAT, &info);

    printf("Message Queue Time Info:\n");
    printf("Time of last change : %ld -> %s", info.msg_ctime, ctime(&info.msg_ctime));
    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 25d.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Message Queue Time Info:
Time of last change : 1759152477 -> Mon Sep 29 18:57:57 2025
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
