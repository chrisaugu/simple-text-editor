#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main()
{
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
    {
        cerr << "Socket creation failed\n";
        return -1;
    }
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    const char *message = "Hello, Server!";
    send(clientSocket, message, strlen(message), 0);
    close(clientSocket);
    return 0;
}

// g++ client.cpp -o client
// ./client