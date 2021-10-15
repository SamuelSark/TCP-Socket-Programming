#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(){
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if(connection_status == -1){
        printf("Error: connection to the remote socket was not successful \n");
    }
    
    char server_content[256];
    recv(network_socket, server_content, sizeof(server_content), 0);
    printf("The server's acknowledgment: %s", server_content);
    close(network_socket);
    return 0;
}
