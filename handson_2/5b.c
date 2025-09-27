/*
============================================================================
Name: 5b.c
Author: Abhishek Ranjan
Description: Program to print the systme limitation of
		b. maximum number of simultaneous process per user id.

Date: 23rd sept, 2025
============================================================================
*/

#include<stdio.h>
#include<sys/resource.h>

int main(){
	struct rlimit lim;
	getrlimit(RLIMIT_NPROC,&lim);
	printf("maximum number of simultaneous process per user id is:%ld\n",(long)lim.rlim_max);
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 5b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
maximum number of simultaneous process per user id is:62450

===============================================================================
*/
