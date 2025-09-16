/*
============================================================================
Name: 19.c
Author: Abhishek Ranjan
Description: Program to find out time taken to execute getpid system call.

Date: 25th Aug, 2025
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

	int pid = getpid();

	asm volatile("cpuid" ::: "%rax", "%rbx", "%rcx", "%rdx");
	asm volatile("rdtsc" : "=a"(lowerbit), "=d"(higherbit));
	long long end = (higherbit<<32) | lowerbit;
	printf("Number of cycles taken by getpid() is: %llu\n", (end-start));
}
/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
Number of cycles taken by getpid() is: 33402

============================================================================

