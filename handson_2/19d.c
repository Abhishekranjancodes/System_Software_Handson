/*
===============================================================================
Name: 19d.c
Author: Abhishek Ranjan
Description: Script to create a FIFO file by
		d. using mknod system call

Date: 28th sept, 2025
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>

int main() {
    mknod("tunnel", S_IFIFO | 0744, 0);
    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 19d.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ls -l tunnel
prwxr--r-- 1 oldfish oldfish 0 Sep 28 18:42 tunnel
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

===============================================================================
*/

