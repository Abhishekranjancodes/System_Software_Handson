/*
============================================================================
Name: 21a.c
Author: Abhishek Ranjan
Description: Program to communicate by FIFO
		using two way communication.

Date: 29th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd1 = open("tunnel1", O_WRONLY);
    int fd2 = open("tunnel2", O_RDONLY);
    char buf1[100];
    char buf2[100];
    printf("Write the message you want to send: \n");
    scanf("%[^\n]",buf1);
    write(fd1, buf1, sizeof(buf1));
    printf("message sent successfully\n");
    read(fd2,buf2,sizeof(buf2));
    printf("message from other is:%s\n",buf2);
    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 21a.c -o a
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a
Write the message you want to send: 
namaste from a
message sent successfully
message from other is:namaste from b
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
