: <<'END_COMMENT'
===============================================================================
Name: 19a.sh
Author: Abhishek Ranjan
Description: Script to create a FIFO file by
		a. mknod command

Date: 28th sept, 2025
============================================================================
END_COMMENT

#!/bin/sh

mknod tunnel p
echo "FIFO file named tunnel has been created."
ls -l tunnel

: <<'END_COMMENT'

===============================================================================
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ chmod +x 19a.sh
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./19a.sh
FIFO file named tunnel has been created.
prw-rw-r-- 1 oldfish oldfish 0 Sep 28 16:24 tunnel
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
END_COMMENT
