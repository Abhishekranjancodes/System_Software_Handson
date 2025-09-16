/*
============================================================================
Name: 9.c
Author: Abhishek Ranjan
Description: Write a c program to print the following information about a file.
		a. inode
		b. number of hard links
		c. uid
		d. gid
		e. size
		f. block size
		g. number of blocks
		h. time of last access
		i. time of last modification
		j. time of last change
Date: 1st sept, 2025
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdint.h>
#include<time.h>

int main(){

	struct stat fileStat;
	stat("dummy.txt", &fileStat);
	printf("Inode number:%ju\n",(uintmax_t)fileStat.st_ino);
	printf("No. of Hard link: %ju\n",(uintmax_t)fileStat.st_nlink);
	printf("user Id: %ju\n", (uintmax_t)fileStat.st_uid);
	printf("group Id: %ju\n", (uintmax_t)fileStat.st_gid);
	printf("File Size: %jd\n", (uintmax_t)fileStat.st_size);
	printf("Block Size: %jd\n", (uintmax_t)fileStat.st_blksize);
	printf("Number of Blocks, %jd\n", (uintmax_t)fileStat.st_blocks);
        printf("Last status change: %s", ctime(&fileStat.st_ctime));
        printf("Last file access: %s", ctime(&fileStat.st_atime));
        printf("Last file modification: %s", ctime(&fileStat.st_mtime));
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ cc 9.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ ./a.out
Inode number:5767242
No. of Hard link: 1
user Id: 1000
group Id: 1000
File Size: 141
Block Size: 4096
Number of Blocks, 8
Last status change: Mon Sep  1 14:23:40 2025
Last file access: Mon Sep  1 14:23:53 2025
Last file modification: Mon Sep  1 14:23:40 2025

============================================================================
*/
