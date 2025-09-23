/*
============================================================================
Name: 4.c
Author: Abhishek Ranjan
Description: Program to find out time taken to execute 100 getpid system call.

Date: 23rd sept, 2025
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
#include<stdint.h>



int main(){
	long long higherbit,lowerbit;
	asm volatile("cpuid" ::: "%rax", "%rbx", "%rcx", "%rdx");
	asm volatile("rdtsc" : "=a"(lowerbit), "=d"(higherbit));
	long long start = (higherbit<<32) | lowerbit;
	
	int i;
	for(i=0;i<100;i++){
		int pid = getppid();
	}
	asm volatile("cpuid" ::: "%rax", "%rbx", "%rcx", "%rdx");
	asm volatile("rdtsc" : "=a"(lowerbit), "=d"(higherbit));
	long long end = (higherbit<<32) | lowerbit;
	printf("Number of cycles taken by getpid() is: %llu\n", (end-start));
	
	return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 4.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Number of cycles taken by getpid() is: 221488
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/

