import socket


def send_content(content):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connect to the server on localhost and port 8080
    s.connect(("127.0.0.1", 8080))

    # Send content to the server
    s.sendall(content.encode())

    # Receive response from the server
    response = s.recv(1024).decode()

    print("Server response:", response)

    s.close()


if __name__ == "__main__":
    text_to_send = "Hello from Python! This is the content to save."
    send_content(text_to_send)
