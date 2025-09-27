/*
============================================================================
Name: 5e.c
Author: Abhishek Ranjan
Description: Program to print the systme limitation of
		e. size of a page

Date: 23rd sept, 2025
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	int pagesize = sysconf(_SC_PAGESIZE);
	printf("maximum page size is:%d\n",pagesize);
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 5e.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
maximum page size is:4096
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
