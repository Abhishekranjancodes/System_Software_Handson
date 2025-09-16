/*
============================================================================
Name: 7.c
Author: Abhishek Ranjan
Description: Write a c program to copy file1 into file2.
Date: 14th Aug, 2025
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd1,fd2;
	fd1= open("dummy.txt",O_RDONLY);
	fd2 = open("dummy2.txt",O_RDWR);
	char buf[100];
	ssize_t bytes;
	while((bytes = read(fd1,buf,sizeof(buf)))>0){
		write(fd2,buf,bytes);
	}
	return 0;
}

/*
===========================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 7.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cat dummy.txt
I am written in dummy.txt
if you are able to see this text in dummy2.txt
then copying file has been sucessul.

Best Regards,
Abhishek Ranjan
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cat dummy2.txt

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 7.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cat dummy2.txt
I am written in dummy.txt
if you are able to see this text in dummy2.txt
then copying file has been sucessul.

Best Regards,
Abhishek Ranjan

===========================================================================

*/

