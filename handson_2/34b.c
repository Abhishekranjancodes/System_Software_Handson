/*
============================================================================
Name: 34b.c
Author: Abhishek Ranjan
Description: Program to create a concurrent server.
		b. use pthread_create

Date: 30th sept, 2025
============================================================================
*/


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdlib.h>

void *handle_client(void *arg) {
    int nsd = *(int *)arg;
    free(arg); 
    char buf[80];

    read(nsd, buf, sizeof(buf));
    printf("Message from client: %s\n", buf);

    write(nsd, "ACK from server\n", 17);
    close(nsd);

    return NULL; 
}

int main() {
    struct sockaddr_in serv, cli;
    int sd, *nsd;
    socklen_t sz;
    pthread_t tid;

    sd = socket(AF_UNIX, SOCK_STREAM, 0);

    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(3541);

    bind(sd, (struct sockaddr *)&serv, sizeof(serv));

    listen(sd, 5);

    printf("Concurrent server (pthread) started, waiting for clients...\n");

    while (1) {
        sz = sizeof(cli);
        nsd = malloc(sizeof(int));          
        *nsd = accept(sd, (struct sockaddr *)&cli, &sz);

        pthread_create(&tid, NULL, handle_client, nsd);
        pthread_detach(tid); 
    }

    close(sd);
    return 0;
}

/*
===============================================================================
Output:

oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ cc 34b.c -o server
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$ ./server
Concurrent server (pthread) started, waiting for clients...
Message from client: how are you
Message from client: sab changa si
^C
oldfish@oldfish-Katana-GF66-12UC:~/Desktop/Term_1/Linux_call/handson/handson_2$


===============================================================================
*/
