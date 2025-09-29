/*
============================================================================
Name: 23.c
Author: Abhishek Ranjan
Description: Program to print the maximum number of files can be opened within
		a process and size of a pipe (circular buffer).

Date: 29th sept, 2025
============================================================================
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/resource.h>
#include <fcntl.h>

int main() {
    struct rlimit rl;
    getrlimit(RLIMIT_NOFILE, &rl);
    printf("Maximum number of files can be opened within a process is: %ld\n", rl.rlim_max);
    int fd[2];
    pipe(fd);
    int pipe_size = fcntl(fd[0], F_GETPIPE_SZ);
    printf("Pipe buffer size: %d bytes\n", pipe_size);

    return 0;
}

/*
===============================================================================
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Maximum number of files can be opened within a process is: 1048576
Pipe buffer size: 65536 bytes
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*i/
