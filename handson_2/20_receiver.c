
/*
============================================================================
Name: 20_receiver.c
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
    char buf[100];
    int fd = open("tunnel", O_RDONLY);
    int n = read(fd, buf, sizeof(buf));
    write(1, buf, n);       
    close(fd);
    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 20_receiver.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Hello from Sender
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

===============================================================================
*/
