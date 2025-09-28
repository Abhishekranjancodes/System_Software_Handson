/*
============================================================================
Name: 17c.c
Author: Abhishek Ranjan
Description: Program to execute ls -l | wc.
		c. fcntl
Date: 28th sept, 2025
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd);

    if (!fork()) {   
        close(fd[0]);    
        close(1);          
        fcntl(fd[1], F_DUPFD, 1);       
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
    } 
    else {              
        close(fd[1]);
        close(0);                      
        fcntl(fd[0], F_DUPFD, 0);      
        close(fd[0]);
        execlp("wc", "wc", NULL);
    }

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 17c.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
     38     337    2037
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
