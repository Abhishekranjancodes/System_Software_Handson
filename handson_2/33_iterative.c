#include<stdio.h>
#include<sys/socket.h>

int main(){
	struct sockeaddr_in serv,cli;
	int oldsd, newsd;
	char buf[80];
	oldsd = socket(AF_UNIX,SOCK_STREAM,0);
	serv.sin_family = AF_UNIX;
	serv.sin_addr.s_addr = INADDR_ANY;
	serv.sin_port = 
