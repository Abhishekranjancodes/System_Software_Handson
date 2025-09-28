/*
============================================================================
Name: 17b.c
Author: Abhishek Ranjan
Description: Program to execute ls -l | wc.
		b.use dup2.
Date: 28th sept, 2025
============================================================================
*/


#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {   
        close(fd[0]);    
        dup2(fd[1], 1);  
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
    } 
    else {             
        close(fd[1]);
        dup2(fd[0], 0); 
        close(fd[0]);
        execlp("wc", "wc", NULL);
    }

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 17b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
     37     328    1982
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
