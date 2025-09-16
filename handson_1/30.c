/*
============================================================================
Name: 30.c
Author: Abhishek Ranjan
Description: Program to run a script at a specific using a Daemon process.        

Date: 3rd Sept, 2025

============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(){
	if(!fork()){
		setsid();
		chdir("/");
		umask(0);
		while(1){
			time_t now = time(NULL);
			struct tm *t = localtime(&now);
			if(t-> tm_hour == 16 && t->tm_min == 15){
				execl("/bin/sh", "sh", "/home/oldfish/Desktop/Term_1/Linux_call/handson_1/script.sh",NULL);
			}
			sleep(60);
		}

		return(0);
	}
	else{
		exit(0);
	}
}


/*
============================================================================
Output:
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cat log
Its the time

============================================================================
*/
