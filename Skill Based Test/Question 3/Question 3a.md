# Server-side Coding

    import socket

    def bar_to_atmosphere(pressure):
    return pressure / 1.01325

    def main():
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        host = "192.168.198.132"  # Server IP
        port = 8443

        server_socket.bind((host, port))
        server_socket.listen(1)
        print("Server is listening on {}:{}".format(host, port))

        while True:
            conn, addr = server_socket.accept()
            print("Connected by:", addr)

            data = conn.recv(1024)
            if not data:
                break

            pressure = float(data.decode())
            atmosphere_standard = bar_to_atmosphere(pressure)
            conn.sendall(str(atmosphere_standard).encode())

            conn.close()

    if __name__ == "__main__":
        main()

# Sample Run Screenshot

![Question 3a (Server)](https://github.com/1ch1m0n/ITT440/assets/129719310/c54015ef-5a00-4b20-a849-7dc8dcab9245)
