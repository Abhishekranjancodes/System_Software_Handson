/*
============================================================================
Name: 20.c
Author: Abhishek Ranjan
Description: Program to find the priority of the running program and change
		the priority with nice command.

Date: 21th Aug, 2025

============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main(){
	int priority;
	priority = getpriority(PRIO_PROCESS,0);
	printf("Priority before:%d\n",priority);
	int n;
	printf("Value by which you want to change the priority:");
	scanf("%d",&n);
	nice(n);
	priority = getpriority(PRIO_PROCESS,0);
	printf("Priority after:%d\n", priority);
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 20.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
Priority before:0
Value by which you want to change the priority:5
Priority after:5
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
Priority before:0
Value by which you want to change the priority:-5
Priority after:0
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ sudo ./a.out
Priority before:0
Value by which you want to change the priority:-5
Priority after:-5

============================================================================
*/
