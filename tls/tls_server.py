import socket
import ssl

# Define the server address and port
SERVER_ADDRESS = ("localhost", 8443)

# Create a TCP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Wrap the socket with SSL
ssl_socket = ssl.wrap_socket(
    server_socket, keyfile="cert.key", certfile="cert.crt", server_side=True
)

# Bind and listen
ssl_socket.bind(SERVER_ADDRESS)
ssl_socket.listen(5)
print(f"Server listening on {SERVER_ADDRESS}")

while True:
    # Accept incoming connections
    client_socket, addr = ssl_socket.accept()
    print(f"Connection from {addr}")

    # Receive data from the client
    data = client_socket.recv(1024).decode()
    print(f"Received: {data}")

    # Simple response logic
    if data.startswith("GET"):
        response = "HTTP/1.1 200 OK\n\nHello from TLS Server!"
    else:
        response = "HTTP/1.1 400 Bad Request\n\nInvalid Command"

    # Send response back to the client
    client_socket.send(response.encode())

    # Close the client connection
    client_socket.close()


# Generate a private key
# openssl genrsa -out server.key 2048

# Generate a self-signed certificate
# openssl req -new -x509 -key server.key -out server.crt -days 365 -subj "/CN=localhost"
