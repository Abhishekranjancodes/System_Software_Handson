/*
============================================================================
Name: 6.c
Author: Abhishek Ranjan
Description: Program to create three threads.

Date: 27th sept, 2025
============================================================================
*/


#include<stdio.h>
#include<pthread.h>


void *threadFunction(void *argvp){
	printf("inside a thread\n");
	return NULL;
}
int main(){
	pthread_t tid[3];
	pthread_create(&tid[0], NULL, threadFunction,NULL);
	pthread_create(&tid[1], NULL, threadFunction,NULL);
	pthread_create(&tid[2], NULL, threadFunction,NULL);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	pthread_join(tid[2],NULL);
	printf("All threads finished it's work!\n");
	return 0;
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 6.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
inside a thread
inside a thread
inside a thread
All threads finished it's work!
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

============================================================================
*/

