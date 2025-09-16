#include<stdio.h>
#include<unistd.h>

int main(){
	int fd[2];
	pipe(fd);
	char buf[100];
	int bytes = write(fd[1],"Abhishek_Ranjan",16);
	read(fd[0],buf,bytes);
	printf("message:%s\n",buf);
}
