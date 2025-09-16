#include<stdio.h>
#include<unistd.h>

int main(){
	char buf1[100];
	char buf2[100];
	int fd1[2];
	int fd2[2];
	pipe(fd1);
	pipe(fd2);
	if(!fork()){
		close(fd1[1]);
		close(fd2[0]);
		write(fd2[1],"Namaste_parent",15);
		read(fd1[0],buf1,13);
		printf("Message from Patent:%s\n", buf1);
	}else{
		close(fd1[0]);
		close(fd2[1]);
		read(fd2[0],buf2,15);
		write(fd1[1],"Namaste_child",13);
		printf("Messsage from child: %s\n", buf2);
	}
}

