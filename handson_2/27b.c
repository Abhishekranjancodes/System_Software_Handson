
/*
============================================================================
Name: 27b.c
Author: Abhishek Ranjan
Description: Program to receive message from the message queue.
		a. with IPC_NOWAIT as a flag.

Date: 29th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
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
	int ret = msgrcv(mqid, &myq, sizeof(myq.message), myq.m_type, IPC_NOWAIT);
	if(ret == -1)
		exit(-1);

	printf("message type: %ld\n message: %s\n", myq.m_type, myq.message);
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 27b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Enter message type: 3
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

=============================================================================
*/
