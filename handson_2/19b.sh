: <<'END_COMMENT'
===============================================================================
Name: 19b.sh
Author: Abhishek Ranjan
Description: Script to create a FIFO file by
		b. mkfifo command

Date: 28th sept, 2025
============================================================================
END_COMMENT

#!/bin/sh

mkfifo tunnel 
echo "FIFO file named tunnel has been created."
ls -l tunnel

: <<'END_COMMENT'

===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ chmod +x 19b.sh
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./19b.sh
FIFO file named tunnel has been created.
prw-rw-r-- 1 oldfish oldfish 0 Sep 28 16:37 tunnel
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
END_COMMENT
