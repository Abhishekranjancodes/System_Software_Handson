/*
============================================================================
Name: 10b.c
Author: Abhishek Ranjan
Description: Write a c program to open a file with read write mode,write 10
		bytes,move the file pointer by 10 bytes and write again 10 
		bytes.
		b. open the file with od and check the empty spaces in between
		the data.
Date: 18th Aug, 2025
============================================================================
*/

Command:
	od -c dummy.txt


/*
===========================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson$ od -c dummy.txt
0000000   I       a   m       w   r   i   t   t   e   n       i   n    
0000020   d   u   m   m   y   .   t   x   t  \n   i   f       y   o   u
0000040       a   r   e       a   b   l   e       t   o       s   e   e
0000060       t   h   i   s       t   e   x   t       i   n       d   u
0000100   m   m   y   2   .   t   x   t  \n   t   h   e   n       c   o
0000120   p   y   i   n   g       f   i   l   e       h   a   s       b
0000140   e   e   n       s   u   c   e   s   s   u   l   .  \n  \n   B
0000160   e   s   t       R   e   g   a   r   d   s   ,  \n   A   b   h
0000200   i   s   h   e   k       R   a   n   j   a   n  \n
0000215

============================================================================
*/
