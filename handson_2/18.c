/*
============================================================================
Name: 18.c
Author: Abhishek Ranjan
Description: Program to find out total number of directories on the pwd.
		executing ls -l | grep ^d | wc

Date: 28th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd1[2], fd2[2];
    pipe(fd1);  
    pipe(fd2);  

    if (!fork()) {   
        dup2(fd1[1], 1);   
        close(fd1[0]);
	close(fd1[1]);
        close(fd2[0]);
	close(fd2[1]);
        execlp("ls", "ls", "-l", NULL);
    }

    if (!fork()) {   
        dup2(fd1[0], 0);   
        dup2(fd2[1], 1);   
        close(fd1[0]);
	close(fd1[1]);
        close(fd2[0]);
	close(fd2[1]);
        execlp("grep", "grep", "^d", NULL);
    }

    if (!fork()) {   
        dup2(fd2[0], 0);   
        close(fd1[0]);
	close(fd1[1]);
        close(fd2[0]);
	close(fd2[1]);
        execlp("wc", "wc", NULL);
    }

    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 18.c
18.c: In function ‘main’:
18.c:52:5: warning: implicit declaration of function ‘wait’ [-Wimplicit-function-declaration]
   52 |     wait(NULL);
      |     ^~~~
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
      0       0       0
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

===============================================================================
*/
