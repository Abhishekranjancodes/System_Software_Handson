: <<'END_COMMENT'
===============================================================================
Name: 19c.sh
Author: Abhishek Ranjan
Description: Script to create a FIFO file by
		c. use strace command to find out, which command is better.

Date: 28th sept, 2025
============================================================================
END_COMMENT

#!/bin/sh


strace -o mknod.txt -e trace=file mknod tunnel1 p
strace -o mkfifo.txt -e trace=file mkfifo tunnel2

grep mknod mknod.txt
grep mknod mkfifo.txt

: <<'END_COMMENT'
===============================================================================
Output:

Both command is using the same system call - mknodat()

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ chmod +x 19c.sh
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./19c.sh
execve("/usr/bin/mknod", ["mknod", "tunnel1", "p"], 0x7ffd40615d40 /* 47 vars */) = 0
mknodat(AT_FDCWD, "tunnel1", S_IFIFO|0666) = 0
mknodat(AT_FDCWD, "tunnel2", S_IFIFO|0666) = 0
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
END_COMMENT

