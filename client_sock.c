/*
We have a TCP server listening on port 8080. The goal is to write a client program that connects to it.
What the client must do:

Create a TCP socket
Configure the server address (IP, port 8080)
Connect to the server using `connect()`
Display a success message if the connection is successful
Close the socket properly
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    //step1: create a tcp socket 
    int client_fd;
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    //config the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //connect to the server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        close(client_fd);
        return EXIT_FAILURE;
    }

    //send data with send()
    const char *message = "Hello, Server!";
    ssize_t bytes_sent = send(client_fd, message, strlen(message), 0);
    if (bytes_sent < 0) {
        perror("send failed");
        close(client_fd);
        return EXIT_FAILURE;

    }
    //receive data with recv()
    char buffer[1024];
    ssize_t bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        close(client_fd);
        return EXIT_FAILURE;
    }

    buffer[bytes_received] = '\0';
    printf("Connected to the server successfully.\n");
    printf("Server replied: %s\n", buffer);
    // Close the socket
    close(client_fd);
    return EXIT_SUCCESS;

}