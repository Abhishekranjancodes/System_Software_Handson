/*
============================================================================
Name: 26a.c
Author: Abhishek Ranjan
Description: Program to execute an executable program
		a. use some executable program

Date: 28th Aug, 2025

============================================================================
*/



#include<unistd.h>

int main(){
	execl("/bin/ls", "ls", NULL);
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 26a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
10a.c  13.c   1a.c		   22.c   3.c  9.c	   dummy.txt
10b.c  14.c   1b.c		   23.c   4.c  answer.txt  file.txt
11a.c  15.c   1c.c		   24.c   5.c  a.out	   linktoanswer
11b.c  16a.c  1.using_command.txt  25.c   6.c  dummy	   solution.txt
11c.c  16b.c  20.c		   26a.c  7.c  dummy1.txt  tunnel
12.c   19.c   21.c		   2.c	  8.c  dummy2.txt

============================================================================
*/
