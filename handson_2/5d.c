/*
============================================================================
Name: 5d.c
Author: Abhishek Ranjan
Description: Program to print the systme limitation of
		d. maximum number of open files.

Date: 23rd sept, 2025
============================================================================
*/

#include<stdio.h>
#include<sys/resource.h>

int main(){
	struct rlimit lim;
	getrlimit(RLIMIT_NOFILE, &lim);
	printf("maximum number of open files:%ld\n",(long)lim.rlim_max);
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 5d.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
maximum number of open files:1048576
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

===============================================================================
*/
