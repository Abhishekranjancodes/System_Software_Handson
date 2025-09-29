/*
============================================================================
Name: 25f.c
Author: Abhishek Ranjan
Description: Program to print a message queue's
		f. number of messages in the queue

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

    printf("Number of messages in the queue: %lu\n", info.msg_qnum);
    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 25f.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Number of messages in the queue: 0
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x610602a6 0          oldfish    744        0            0           

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$
===============================================================================
*/
