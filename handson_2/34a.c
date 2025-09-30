/*
============================================================================
Name: 34a.c
Author: Abhishek Ranjan
Description: Program to create a concurrent server.
		a. use fork().

Date: 30th sept, 2025
============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main() {
    struct sockaddr_in serv, cli;
    int sd, nsd;
    socklen_t sz;
    char buf[80];

    sd = socket(AF_UNIX, SOCK_STREAM, 0);

    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(3540);

    bind(sd, (struct sockaddr *)&serv, sizeof(serv));

    listen(sd, 5);

    printf("Concurrent server started, waiting for clients...\n");

    while (1) {
        sz = sizeof(cli);
        nsd = accept(sd, (struct sockaddr *)&cli, &sz);

        if (fork() == 0) {  
            close(sd);  

            read(nsd, buf, sizeof(buf));
            printf("Message from client: %s\n", buf);

            write(nsd, "ACK from server\n", 17);
            close(nsd);

            exit(0);  
        }

        close(nsd);  
    }

    close(sd);
    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 34a.c -o server
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./server
Concurrent server started, waiting for clients...
Message from client: hello ji!
Message from client: kaise ho ji!
^C
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ 

===============================================================================
*/
