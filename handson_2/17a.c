/*
============================================================================
Name: 17a.c
Author: Abhishek Ranjan
Description: Program to execute ls -l | wc.
		a. use dup
Date: 28th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (!fork()) {   
        close(fd[0]);    
        close(1);        
        dup(fd[1]);      
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
    } 
    else {              
        close(fd[1]);
        close(0);        
        dup(fd[0]);      
        close(fd[0]);
        execlp("wc", "wc", NULL);
    }

    return 0;
}
/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 17a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
     36     319    1927
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
