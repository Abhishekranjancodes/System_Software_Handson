#include<stdio.h>
#include<unistd.h>

int main(){
	int fd[2];
	char buf[100];
	pipe(fd);
	if(!fork()){
		close(0);
		dup(fd[0]);
		close(fd[1]);
		read(fd[0],buf,sizeof(buf));
		printf("message:%s\n",buf);
	}else{
		close(1);
		dup(fd[1]);
		close(fd[0]);
		write(fd[1],"Abhishek_Ranjan",16);
	}
}
