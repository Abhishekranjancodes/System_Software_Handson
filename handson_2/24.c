
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

int main(){
	key_t key = ftok(".",'a');
	int msgid = msgget(key, IPC_CREAT | IPC_EXCL| 0744);
	printf("key= 0x%0x  msgid= %d\n",key, msgid);
}
