/*
============================================================================
Name: 20_sender.c
Author: Abhishek Ranjan
Description: Program to communicate by FIFO
		using only one way communication

Date: 28th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    mkfifo("tunnel", 0644);    
    int fd = open("tunnel", O_WRONLY);
    printf("Sending the message to fifo\n");
    write(fd, "Hello from Sender\n", 18);
    printf("message sent successfully\n");
    close(fd);
    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 20_sender.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Sending the message to fifo
message sent successfully
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

===============================================================================
*/
