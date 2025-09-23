/*
===============================================================================
Name: 3.c
Author: Abhishek Ranjan
Description: Program to set the system resource limits.

Date: 22nd Sept, 2025

===============================================================================
*/

#include<stdio.h>
#include<sys/resource.h>

int main(){
	struct rlimit old,new;
	getrlimit(RLIMIT_NPROC, &old);
	printf("Old No of thread limit: Soft:%ld , Hard:%ld\n",(long)old.rlim_cur,(long)old.rlim_max);
	new.rlim_cur = 62448;
	new.rlim_max = 62449;
	setrlimit(RLIMIT_NPROC, &new);
	printf("New No of thread limit: Soft:%ld, Hard:%ld\n",(long)new.rlim_cur,(long)new.rlim_max);

	return 0;
}

/*
===============================================================================
Output:
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 3.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Old No of thread limit: Soft:62450 , Hard:62450
New No of thread limit: Soft:62448, Hard:62449
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
