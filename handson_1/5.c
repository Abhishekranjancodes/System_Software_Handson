/*
============================================================================
Name: 5.c
Author: Abhishek Ranjan
Description: Write a c program to create five new files with infinite loop.
		Execute the program in background and check file descriptor
Date: 31st Aug, 2025
============================================================================
*/

#include<stdio.h>
#include<stdbool.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>

int main(){
	int fd[5];
	char *file[] = {"file1","file2","file3","file4","file5"};
	for(int i=0;i<5;i++){
		fd[i] = creat(file[i], 0744);
		if(fd[i]>=0){
			printf("%s created successfully\n",file[i]);
		}else{
			perror("file creation unsuccessful\n");
		}
	}
	while(true){
	}
}

/*
============================================================================
Output:
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_1$ cc 5.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_1$ ./a.out &
[1] 4523
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_1$ file1 created successfully
file2 created successfully
file3 created successfully
file4 created successfully
file5 created successfully
ls -l /proc/4523/fd
ls: cannot access '/prols': No such file or directory
/proc/4523/fd:
total 0
lrwx------ 1 oldfish oldfish 64 Sep 20 20:14 0 -> /dev/pts/0
lrwx------ 1 oldfish oldfish 64 Sep 20 20:14 1 -> /dev/pts/0
lrwx------ 1 oldfish oldfish 64 Sep 20 20:14 2 -> /dev/pts/0
l-wx------ 1 oldfish oldfish 64 Sep 20 20:14 3 -> /home/oldfish/Desktop/Term_1/Linux_call/handson/handson_1/file1
l-wx------ 1 oldfish oldfish 64 Sep 20 20:14 4 -> /home/oldfish/Desktop/Term_1/Linux_call/handson/handson_1/file2
l-wx------ 1 oldfish oldfish 64 Sep 20 20:14 5 -> /home/oldfish/Desktop/Term_1/Linux_call/handson/handson_1/file3
l-wx------ 1 oldfish oldfish 64 Sep 20 20:14 6 -> /home/oldfish/Desktop/Term_1/Linux_call/handson/handson_1/file4
l-wx------ 1 oldfish oldfish 64 Sep 20 20:14 7 -> /home/oldfish/Desktop/Term_1/Linux_call/handson/handson_1/file5


============================================================================
*/

