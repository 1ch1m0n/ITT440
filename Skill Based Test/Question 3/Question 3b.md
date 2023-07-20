# Client-side Coding

    import socket

    def main():
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        host = "192.168.198.132"  # Server IP
        port = 8443

        try:
            client_socket.connect((host, port))
            print("Connected to server at {}:{}".format(host, port))

            pressure = float(input("Enter the pressure value in bar: "))
            client_socket.sendall(str(pressure).encode())

            data = client_socket.recv(1024)
            atmosphere_standard = float(data.decode())

            print("Received atmosphere standard value: {:.4f}".format(atmosphere_standard))

        except ConnectionRefusedError:
            print("Connection to the server refused.")
        except ValueError:
            print("Invalid input. Please enter a valid pressure value.")
        finally:
            client_socket.close()

    if __name__ == "__main__":
        main()

# Sample Run Screenshot
![Question 3b (Client)](https://github.com/1ch1m0n/ITT440/assets/129719310/cb3de768-3063-4eba-a03d-bdaed2da8c50)
