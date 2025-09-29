/*
============================================================================
Name: 21b.c
Author: Abhishek Ranjan
Description: Program to communicate by FIFO
		using two way communication.

Date: 28th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd1 = open("tunnel1", O_RDONLY);
    int fd2 = open("tunnel2", O_WRONLY);
    char buf1[100];
    char buf2[100];
    read(fd1,buf1,sizeof(buf1));
    printf("message from other is:%s\n",buf1);
    printf("Write the message you want to send: \n");
    scanf("%[^\n]",buf2);
    write(fd2, buf2, sizeof(buf2));
    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 21b.c -o b
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./b
message from other is:namaste from a
Write the message you want to send: 
namaste from b
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
