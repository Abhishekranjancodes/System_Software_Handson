
/*
============================================================================
Name: 29.c
Author: Abhishek Ranjan
Description: Program to remove the message queue.

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

    key = ftok(".", 'a');
    msgid = msgget(key, 0);  
    msgctl(msgid, IPC_RMID, NULL);

    printf("Message queue removed.\n");
    return 0;
}


/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 29.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Message queue removed.
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

=============================================================================
*/
