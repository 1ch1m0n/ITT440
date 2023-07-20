# Server-side Coding

    import socket
    import random
    import threading

    # List of deep and meaningful quotes for QOTD
    quotes = [
        "Life is like a boxing match, where defeat is declared not when you fall but when you refuse to stand again. - Muhammad Ali the GOAT"
        "The only limit to our realization of tomorrow will be our doubts of today. - Franklin D. Roosevelt",
        "You miss 100% of the shots you don't take. - Wayne Gretzky",
        "The only way to do great work is to love what you do. - Steve Jobs",
        "The future belongs to those who believe in the beauty of their dreams. - Eleanor Roosevelt",
        "The best way to predict the future is to create it. - Peter Drucker",
        "Life is 10% what happens to us and 90% how we react to it. - Charles R. Swindoll",
        "In the end, we will remember not the words of our enemies, but the silence of our friends. - Martin Luther King Jr."
    ]

    def handle_client(client_socket):
        quote = random.choice(quotes)
        client_socket.send(quote.encode())
        client_socket.close()

    def main():
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        host = "192.168.198.132"  # Server IP
        port = 8443

        server_socket.bind((host, port))
        server_socket.listen(5)
        print("Server is listening on {}:{}".format(host, port))

        while True:
            client_socket, client_address = server_socket.accept()
            print("Accepted connection from {}:{}".format(client_address[0], client_address[1]))

            client_thread = threading.Thread(target=handle_client, args=(client_socket,))
            client_thread.start()

    if __name__ == "__main__":
        main()

# Sample Run Screenshot
![Question 4a (Server)](https://github.com/1ch1m0n/ITT440/assets/129719310/8ec3c3ce-f70c-4073-b46e-7aede9f17274)

