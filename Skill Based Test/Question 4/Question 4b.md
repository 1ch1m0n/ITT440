# Client Side Coding

    import socket

    def main():
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        host = "192.168.198.132"  # Server IP
        port = 8443

        try:
            client_socket.connect((host, port))
            print("Connected to server at {}:{}".format(host, port))

            quote = client_socket.recv(1024).decode()
            print("Received quote of the day: {}".format(quote))

        except ConnectionRefusedError:
            print("Connection to the server refused.")
        finally:
            client_socket.close()

    if __name__ == "__main__":
        main()

# Sample Run Screenshot
![Question 4b (Client)](https://github.com/1ch1m0n/ITT440/assets/129719310/305a3dee-2f2b-4a81-89ec-064cc9659723)
