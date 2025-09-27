/*
============================================================================
Name: 5a.c
Author: Abhishek Ranjan
Description: Program to print the systme limitation of
		a. maximum length of the arguments to the exec family of functions.

Date: 23rd sept, 2025
============================================================================
*/


#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>

int main(){
	int lim = sysconf(_SC_ARG_MAX);
	printf("maximum length of the arguments to the exec family of functions:%d\n",lim);
 	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 5a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
maximum length of the arguments to the exec family of functions:2097152
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
