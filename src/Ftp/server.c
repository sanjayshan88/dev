#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

#define MAX_BUF_LEN 256

int main(int argc, char *argv[]) {

    char server_message[MAX_BUF_LEN];
    char ch;
    int i = 0;
    FILE *fp = NULL;

    if (argc < 2) {
        printf("Usage: ./server <src_file>\n");
        return 1;
    }
    fp = fopen(argv[1], "r");   

    // create the server socket
    int server_socket;
    server_socket = socket (AF_INET,
                            SOCK_STREAM,
                            0);

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to our specified IP and port
    bind(server_socket,
         (struct sockaddr *) &server_address,
         sizeof(server_address));

    listen(server_socket, 5);

    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    i = 0;
    while ((ch = getc(fp)) != EOF) {
        if (i == MAX_BUF_LEN - 1) {
            server_message[i] = '\0';
            i = 0;
            // send the message
            send(client_socket, 
                 server_message, 
                 sizeof(server_message), 0);
            memset(server_message, 0, sizeof(server_message));
        }
        server_message[i++] = ch;
    }
    if (i > 0) {
        // send the message
        send(client_socket, 
             server_message, 
             sizeof(server_message), 0);
    }

    fclose(fp);
    // close the socket
    close(server_socket);

    return 0;
}
