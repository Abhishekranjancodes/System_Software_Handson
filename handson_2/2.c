/*
===============================================================================
Name: 2.c
Author: Abhishek Ranjan
Description: Program to print the system resource limits.

Date: 21st Sept, 2025

===============================================================================
*/
#include<stdio.h>
#include<stdio.h>
#include<sys/resource.h>

void print(int r, const char *resourceName){
	struct rlimit limit;
	getrlimit(r, &limit);
	printf("%-40s",resourceName);
	if(limit.rlim_cur == RLIM_INFINITY){
            printf("Soft limit is: unlimited, ");
	}
        else{
            printf("Soft limit is: %ld, ", (long)limit.rlim_cur);
	}
        if(limit.rlim_max == RLIM_INFINITY){
            printf("Hard limit is: unlimited\n");
	}
        else{
            printf("Hard limit is: %ld\n", (long)limit.rlim_max);
	}
}

int main(){
	print(RLIMIT_AS, "Address Space size: ");
	print(RLIMIT_CORE, "Core file size: ");
	print(RLIMIT_CPU, "CPU time limit: ");
	print(RLIMIT_DATA, "Process data segment limit: ");
	print(RLIMIT_FSIZE, "File size limit: ");
	print(RLIMIT_LOCKS, "Locks limit: ");
	print(RLIMIT_MEMLOCK, "Memory lock into RAM limit: ");
	print(RLIMIT_MSGQUEUE, "POSIX message queue limit: ");
	print(RLIMIT_NICE, "NICE value limit: ");
	print(RLIMIT_NOFILE, "FILE descriptor limit: ");
	print(RLIMIT_NPROC, "No of thread limit: ");
	print(RLIMIT_RSS, "Virtual pages resident in RAM limit: ");
	print(RLIMIT_RTPRIO, "Real time priority limit: ");
	print(RLIMIT_RTTIME, "CPU time for real time process limit: ");
	print(RLIMIT_SIGPENDING, "Pending signals limit: ");
	print(RLIMIT_STACK, "Stack size limit: ");
	return 0;
}

/*
===============================================================================
Output:
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 2.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Address Space size:                     Soft limit is: unlimited, Hard limit is: unlimited
Core file size:                         Soft limit is: 0, Hard limit is: unlimited
CPU time limit:                         Soft limit is: unlimited, Hard limit is: unlimited
Process data segment limit:             Soft limit is: unlimited, Hard limit is: unlimited
File size limit:                        Soft limit is: unlimited, Hard limit is: unlimited
Locks limit:                            Soft limit is: unlimited, Hard limit is: unlimited
Memory lock into RAM limit:             Soft limit is: 2056986624, Hard limit is: 2056986624
POSIX message queue limit:              Soft limit is: 819200, Hard limit is: 819200
NICE value limit:                       Soft limit is: 0, Hard limit is: 0
FILE descriptor limit:                  Soft limit is: 1024, Hard limit is: 1048576
No of thread limit:                     Soft limit is: 62450, Hard limit is: 62450
Virtual pages resident in RAM limit:    Soft limit is: unlimited, Hard limit is: unlimited
Real time priority limit:               Soft limit is: 0, Hard limit is: 0
CPU time for real time process limit:   Soft limit is: unlimited, Hard limit is: unlimited
Pending signals limit:                  Soft limit is: 62450, Hard limit is: 62450
Stack size limit:                       Soft limit is: 8388608, Hard limit is: unlimited

===============================================================================
*/
