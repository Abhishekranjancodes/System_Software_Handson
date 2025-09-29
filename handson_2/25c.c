/*
============================================================================
Name: 25c.c
Author: Abhishek Ranjan
Description: Program to print a message queue's
		c. time of last message sent and received.

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
    printf("Time of last message sent: %ld -> %s",info.msg_stime, ctime(&info.msg_stime));
    printf("Time of last message received: %ld -> %s", info.msg_rtime, ctime(&info.msg_rtime));

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 25c.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Message Queue Time Info:
Time of last message sent: 1759152517 -> Mon Sep 29 18:58:37 2025
Time of last message received: 1759152563 -> Mon Sep 29 18:59:23 2025
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
