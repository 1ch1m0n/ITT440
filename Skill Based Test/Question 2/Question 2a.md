# Server-side Coding

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <unistd.h>
    #include <string.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>

    
    #define PORT 8443

    int main() {
        int server_fd, new_socket, valread;
        struct sockaddr_in address;
        int addrlen = sizeof(address);
        int random_number;

        // Create socket
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == -1) {
            perror("socket creation failed");
            exit(EXIT_FAILURE);
        }

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        // Bind socket to specified IP and port
        if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }
         // Listen for incoming connections
        if (listen(server_fd, 3) < 0) {
            perror("listen failed");
            exit(EXIT_FAILURE);
        }

        srand(time(NULL)); // Seed the random number generator with current time

        while (1) {
            printf("Waiting for a client to connect...\n");
            new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
                if (new_socket < 0) {
                    perror("accept failed");
                    exit(EXIT_FAILURE);
                }

            // Generate a random number between 100 and 999
            random_number = rand() % 900 + 100;

            // Send the random number to the client
            send(new_socket, &random_number, sizeof(random_number), 0);
            printf("Random number sent: %d\n", random_number);

            close(new_socket);
        }

        return 0;
    }


# Sample Screenshot 
![Question 2a (Server)](https://github.com/1ch1m0n/ITT440/assets/129719310/a61a601f-385d-48eb-917d-f2a4ae5cf457)






