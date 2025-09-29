/*
============================================================================
Name: 25h.c
Author: Abhishek Ranjan
Description: Program to print a message queue's
		h. pid of the msgsnd and msgrcv

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

    printf("Message Queue PIDs:\n");
    printf("Last msgsnd PID : %d\n", info.msg_lspid);
    printf("Last msgrcv PID : %d\n", info.msg_lrpid);

    return 0;
}


/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 25h.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Message Queue PIDs:
Last msgsnd PID : 5618
Last msgrcv PID : 5633
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
