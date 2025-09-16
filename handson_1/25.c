/*
============================================================================
Name: 25.c
Author: Abhishek Ranjan
Description: Program to create three child processes. The parent should wait for 
		a paritcular child.

Date: 25th Aug, 2025

============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
	int i=1;
	int cd;
	int wstatus;
	while(i<=3){
		cd = fork();
		if(cd == 0){
		printf("Inside child %d, :  %d\n",i,getpid());
		printf("Child %d is going to sleep \n",i);
		sleep(3+i);
		printf("Child %d exiting from sleep\n", i);
		exit(0);
		}
		i++;
	}
	printf("Inside Parent child:%d\n",getpid());
	printf("Waiting for third child to exit\n");
	waitpid(cd, &wstatus,0);
	printf("Now parent exiting\n");

}
/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 25.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
Inside Parent child:1088429
Waiting for third child to exit
Inside child 1, :  1088430
Child 1 is going to sleep 
Inside child 2, :  1088431
Child 2 is going to sleep 
Inside child 3, :  1088432
Child 3 is going to sleep 
Child 1 exiting from sleep
Child 2 exiting from sleep
Child 3 exiting from sleep
Now parent exiting

============================================================================
*/

