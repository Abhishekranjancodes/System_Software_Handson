
/*
============================================================================
Name: 26.c
Author: Abhishek Ranjan
Description: Program to send messages to the message queue.

Date: 29th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>

int main(){
	struct msg {
		long int m_type;
		char message[80];
	}myq;
	key_t key = ftok(".",'a');
	int mqid = msgget(key, 0);
	printf("Enter message type: ");
	scanf("%ld", &myq.m_type);
	getchar();
	printf("Enter message text: ");
	scanf("%[^\n]", myq.message);
	int size = strlen(myq.message);
	msgsnd(mqid, &myq, size +1,0);
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 26.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Enter message type: 4
Enter message text: pandu
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x610602a6 0          oldfish    744        27           4           

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

=============================================================================
