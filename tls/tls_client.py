import socket
import ssl

# Define the server address and port
SERVER_ADDRESS = ("localhost", 8443)

# Create a TCP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Wrap the socket with SSL
ssl_socket = ssl.wrap_socket(client_socket)

# Connect to the server
ssl_socket.connect(SERVER_ADDRESS)

# Send a request to the server
request = "GET /data"
ssl_socket.send(request.encode())

# Receive response from the server
response = ssl_socket.recv(1024).decode()
print(f"Response from server: {response}")

# Close the connection
ssl_socket.close()
