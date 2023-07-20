# Client-side Coding

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <unistd.h>

    #define PORT 8443

    int main() {
      int client_fd;
      struct sockaddr_in server_address;
      int random_number;

      // Create socket
      client_fd = socket(AF_INET, SOCK_STREAM, 0);
      if (client_fd == -1) {
          perror("socket creation failed");
          exit(EXIT_FAILURE);
      }

      server_address.sin_family = AF_INET;
      server_address.sin_port = htons(PORT);

      // Convert IP address from text to binary form
      if (inet_pton(AF_INET, "192.168.198.132", &server_address.sin_addr) <= 0) {
          perror("inet_pton failed");
          exit(EXIT_FAILURE);
      }

      // Connect to the server
      if (connect(client_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
          perror("connection failed");
          exit(EXIT_FAILURE);
      }

      // Receive the random number from the server
      recv(client_fd, &random_number, sizeof(random_number), 0);

      printf("Received random number from server: %d\n", random_number);

      close(client_fd);

      return 0;
    }

# Sample Screenshot 
![Question 2b (Client)](https://github.com/1ch1m0n/ITT440/assets/129719310/ae525500-7271-47ab-876d-7efc7555474b)



