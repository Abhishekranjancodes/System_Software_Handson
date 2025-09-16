/*
============================================================================
Name: 8.c
Author: Abhishek Ranjan
Description: Write a c program to open a file in read only mode, read line by
		line and display each line as it is read.
Date: 18th Aug, 2025
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd1;
	char c;
	char buf[1024];
	int i = 0;
	fd1 = open("dummy.txt",O_RDONLY);
	while(read(fd1,&c,1)>0){
		if(c =='\n'){
			buf[i] = '\0';
			write(1,buf,i);
			write(1,"\n",1);
			i = 0;
		}else{
			buf[i] = c;
			i++;
		}
	}
	if(i>0){
		buf[i] = '\0';
		write(1,buf,i);
		write(1,"\n",1);
	}
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 8.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
I am written in dummy.txt
if you are able to see this text in dummy2.txt
then copying file has been sucessul.

Best Regards,
Abhishek Ranjan

============================================================================
*/
