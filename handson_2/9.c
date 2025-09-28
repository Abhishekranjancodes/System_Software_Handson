/*
============================================================================
Name: 9.c
Author: Abhishek Ranjan
Description: Program to ignore a SIGINT signal then reset the default action 
		of the SIGINT signal - using signal system call

Date: 28th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    signal(SIGINT, SIG_IGN);
    printf("SIGINT is now getting ignored for the next 7 second\n");
    
    sleep(7);

    signal(SIGINT, SIG_DFL);
    printf("SIGINT is now reset to default, An infinite loop is running press CTRL+C to exit\n");

    while (1);

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 9.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
SIGINT is now getting ignored for the next 7 second
^C^C^C^C^C^C^CSIGINT is now reset to default, An infinite loop is running press CTRL+C to exit
^C
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
