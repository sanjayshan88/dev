#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#define MAX_BUF_LEN 256

int main(int argc, char *argv[])
{

    FILE *fp = NULL;
    char server_response[MAX_BUF_LEN];
    int i = 0, rc = 0;

    if (argc < 2) {
        printf("Usage: ./client <dst_file>\n");
        return 1;
    }    

    // create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0); 

  
    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY; 

    // connect
    int connection_status = connect(network_socket, 
                                    (struct sockaddr *) &server_address, 
                                    sizeof(server_address));
    // check for error with the connection
    if (connection_status == -1) {
        printf("There was an error making a connection to the remote socket\n");
        return 1;
    }
    
    fp = fopen(argv[1], "w+");
    while (1) {
        // receive data from the server
        rc = recv(network_socket, 
             &server_response, 
             sizeof(server_response), 0);
        i++;
        // check if server has closed the connection
        if (rc == 0) {
            break;
        }
        fputs(server_response, fp);
        memset(server_response, 0, sizeof(server_response));
    }

    fclose(fp);
    // close the socket
    close(network_socket);

    return 0;
}
