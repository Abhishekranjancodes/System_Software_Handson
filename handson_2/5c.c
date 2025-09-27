/*
============================================================================
Name: 5c.c
Author: Abhishek Ranjan
Description: Program to print the systme limitation of
		c. number of clock ticks(jiffy) per second.

Date: 23rd sept, 2025
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	int tps = sysconf(_SC_CLK_TCK);
	printf("Number of clock ticks(jiffy) per second:%d\n",tps);
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 5c.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Number of clock ticks(jiffy) per second:100
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

===============================================================================
*/
