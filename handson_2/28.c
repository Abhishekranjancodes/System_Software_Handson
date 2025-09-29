
/*
============================================================================
Name: 28.c
Author: Abhishek Ranjan
Description: Program to change the existing message queue permission.

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
    printf("Old permissions: %o\n", info.msg_perm.mode & 0777);

    info.msg_perm.mode = 0766; 
    msgctl(msgid, IPC_SET, &info);

    msgctl(msgid, IPC_STAT, &info);
    printf("New permissions: %o\n", info.msg_perm.mode & 0777);

    return 0;
}


/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 28.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Old permissions: 744
New permissions: 766
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

=============================================================================
*/
