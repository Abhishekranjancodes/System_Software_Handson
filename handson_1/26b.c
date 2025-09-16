/*
============================================================================
Name: 26b.c
Author: Abhishek Ranjan
Description: Program to execute an executable program
                b. pass some input to an executable program

Date: 28th Aug, 2025

============================================================================
*/



#include<unistd.h>

int main(){
        execl("./numprinter", "./numprinter", "17", NULL);
}

/*
============================================================================
Output:


oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ cc 26b.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term 1/Linux_call/handson_1$ ./a.out
The number is : 17

============================================================================
*/
