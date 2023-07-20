##Coding
    
    #include <stdio.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <string.h>

    int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server;
    char *message;
    char server_response[2000]; // Buffer to store the server response

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr("203.106.71.185");
    server.sin_family = AF_INET;
    server.sin_port = htons(8443);

    // Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("connect error");
        return 1;
    }
    puts("Connected\n");

    // Send some data
    message = "2021816818";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }
    puts("Data Sent\n");
    
     // Receive server response
    int received_bytes = recv(socket_desc, server_response, sizeof(server_respo>
    if (received_bytes < 0) {
        puts("Receive failed");
        return 1;
    }

    // Null-terminate the received data to treat it as a string and print it
    server_response[received_bytes] = '\0';
    printf("Server Response: %s\n", server_response);

    return 0;
    
    }

##Sample Run Screenshot


![Question1](https://github.com/1ch1m0n/ITT440/blob/190f7faee1a7cfeed888a8507dadedee7e64397c/Screenshots/Question%201%20(Sample%20Screenshot).png)


