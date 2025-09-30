/*
============================================================================
Name: 33c.c
Author: Abhishek Ranjan
Description: Program to communicate between two machines using socket

Date: 30th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    struct sockaddr_in serv;
    int sd;
    char buf[80], data[100];

    sd = socket(AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_port = htons(3559);
    serv.sin_addr.s_addr = inet_addr("10.10.3.147"); 

    connect(sd, (struct sockaddr *)&serv, sizeof(serv));

    printf("Write the message for server: ");
    scanf("%[^\n]", data);

    write(sd, data, strlen(data) + 1);

    read(sd, buf, sizeof(buf));
    printf("Message from server: %s\n", buf);

    close(sd);
    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 33c.c
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Write the message for server: Hello sameer!
Message from server: ACK from Server

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./a.out
Write the message for server: How are you!
Message from server: ACK from Server

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$

===============================================================================
*/
