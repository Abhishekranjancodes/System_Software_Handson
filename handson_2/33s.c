/*
============================================================================
Name: 33s.c
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
    struct sockaddr_in serv, cli;
    int sd, nsd;
    socklen_t sz;
    char buf[80];

    sd = socket(AF_UNIX, SOCK_STREAM, 0);

    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(3559);

    bind(sd, (struct sockaddr *)&serv, sizeof(serv));
    listen(sd, 5);

    while (1) { 
        sz = sizeof(cli);
        nsd = accept(sd, (struct sockaddr *)&cli, &sz);

        read(nsd, buf, sizeof(buf));
        printf("Message from client: %s\n", buf);

        write(nsd, "ACK from server\n", 17);
        close(nsd);
    }

    close(sd);
    return 0;
}

/*
===============================================================================
Output:

sameer@sameer-ACERPCHLY:~/CSE513A/handson2/33$ ./33a
Server listening on port 3559
Message from client: Hello sameer!
Message from client: How are you!

===============================================================================
*/
