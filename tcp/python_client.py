import socket


def main():
    # Create a socket object
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Define the server address and port
    server_address = ("127.0.0.1", 8080)

    # Connect to the server
    client_socket.connect(server_address)

    # Send a message to the server
    message = "Hello from Python client!"
    client_socket.sendall(message.encode())

    # Receive response from the server
    response = client_socket.recv(1024).decode()

    print("Response from C++ server:", response)

    # Close the connection
    client_socket.close()


if __name__ == "__main__":
    main()
