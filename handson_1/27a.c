/*
============================================================================
Name: 27a.c
Author: Abhishek Ranjan
Description: Program to execute ls -Rl by
                a. execl

Date: 1st Sept, 2025

============================================================================
*/

#include<unistd.h>

int main(){
        execl("/bin/ls", "ls","-Rl", NULL);
}

/*
============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ vim 27a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 27a.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
.:
total 188
-rw-rw-r-- 1 oldfish oldfish  1115 Sep  1 15:06 10a.c
-rw-rw-r-- 1 oldfish oldfish  1369 Sep  1 15:09 10b.c
-rw-rw-r-- 1 oldfish oldfish  1322 Sep  1 15:40 11a.c
-rw-rw-r-- 1 oldfish oldfish  1362 Sep  1 15:49 11b.c
-rw-rw-r-- 1 oldfish oldfish  1321 Sep  1 16:06 11c.c
-rw-rw-r-- 1 oldfish oldfish   990 Sep  1 17:29 12.c
-rw-rw-r-- 1 oldfish oldfish  1292 Sep  1 18:09 13.c
-rw-rw-r-- 1 oldfish oldfish  2048 Sep  6 11:32 14.c
-rw-rw-r-- 1 oldfish oldfish  3873 Sep  6 11:24 15.c
-rw-rw-r-- 1 oldfish oldfish  1338 Sep  6 11:33 16a.c
-rw-rw-r-- 1 oldfish oldfish  1454 Sep  6 11:38 16b.c
-rw-rw-r-- 1 oldfish oldfish  1111 Sep  6 15:45 19.c
-rw-rw-r-- 1 oldfish oldfish   874 Sep  1 11:59 1a.c
-rw-rw-r-- 1 oldfish oldfish   868 Sep  1 12:05 1b.c
-rw-rw-r-- 1 oldfish oldfish   881 Sep  1 12:39 1c.c
-rw-rw-r-- 4 oldfish oldfish   490 Sep  1 11:43 1.using_command.txt
-rw-rw-r-- 1 oldfish oldfish  1433 Sep  6 18:19 20.c
-rw-rw-r-- 1 oldfish oldfish  1059 Sep  6 18:35 21.c
-rw-rw-r-- 1 oldfish oldfish  1192 Sep  6 23:41 22.c
-rw-rw-r-- 1 oldfish oldfish  1091 Sep  6 19:38 23.c
-rw-rw-r-- 1 oldfish oldfish  1380 Sep  6 19:59 24.c
-rw-rw-r-- 1 oldfish oldfish  1493 Sep  7 00:35 25.c
-rw-rw-r-- 1 oldfish oldfish  1039 Sep  7 00:40 26a.c
-rw-rw-r-- 1 oldfish oldfish   781 Sep  7 01:07 26b.c
-rw-rw-r-- 1 oldfish oldfish   539 Sep  7 12:32 27a.c
-rw-rw-r-- 1 oldfish oldfish  2382 Sep  1 12:45 2.c
-rw-rw-r-- 1 oldfish oldfish  1000 Sep  1 12:39 3.c
-rw-rw-r-- 1 oldfish oldfish  1245 Sep  1 13:55 4.c
-rw-rw-r-- 1 oldfish oldfish   426 Sep  1 14:11 5.c
-rw-rw-r-- 1 oldfish oldfish   909 Sep  1 14:17 6.c
-rw-rw-r-- 1 oldfish oldfish  1560 Sep  1 15:06 7.c
-rw-rw-r-- 1 oldfish oldfish  1172 Sep  1 14:37 8.c
-rw-rw-r-- 1 oldfish oldfish  1859 Sep  1 14:46 9.c
-rw-rw-r-- 4 oldfish oldfish   490 Sep  1 11:43 answer.txt
-rwxrwxr-x 1 oldfish oldfish 15960 Sep  7 12:32 a.out
lrwxrwxrwx 1 oldfish oldfish     9 Aug  9 17:47 dummy -> dummy.txt
-rwxr--r-- 1 oldfish oldfish    71 Sep  1 16:05 dummy1.txt
-rw-rw-r-- 1 oldfish oldfish   141 Sep  1 14:26 dummy2.txt
-rw-rw-r-- 1 oldfish oldfish    84 Sep  6 18:57 dummy.txt
-rwxr--r-- 1 oldfish oldfish     0 Sep  1 13:54 file.txt
lrwxrwxrwx 1 oldfish oldfish    10 Sep  1 11:55 linktoanswer -> answer.txt
-rwxrwxr-x 1 oldfish oldfish 16008 Sep  7 01:06 numprinter
-rw-rw-r-- 1 oldfish oldfish   134 Sep  7 01:06 numprinter.c
-rw-rw-r-- 4 oldfish oldfish   490 Sep  1 11:43 solution.txt
prwxr--r-- 1 oldfish oldfish     0 Sep  1 12:12 tunnel

============================================================================
*/
