/*
============================================================================
Name: 7.c
Author: Abhishek Ranjan
Description: Program to print the created thread ids.

Date: 27th sept, 2025
============================================================================
*/

#include<stdio.h>
#include<pthread.h>


void *threadfunction(void *argvp){
	pthread_t tid = pthread_self();
	printf("Thread id is:%lu\n",(unsigned long)tid);
	return NULL;
}

int main(){
	pthread_t tid;
	pthread_create(&tid,NULL, threadfunction, NULL);
	pthread_join(tid,NULL);
	
	return 0;
}
/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 7.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Thread id is:130105179371072
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2

===============================================================================
