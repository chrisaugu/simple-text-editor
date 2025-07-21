#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

void saveToFile(const std::string &content)
{
    std::ofstream outFile("output.txt");
    if (outFile.is_open())
    {
        outFile << content;
        outFile.close();
        std::cout << "Content saved to output.txt" << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file" << std::endl;
    }
}

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        std::cerr << "Set socket options error" << std::endl;
        return -1;
    }

    address.sin_family = AF_INET;         // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // Any address
    address.sin_port = htons(PORT);       // Port

    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        std::cerr << "Bind failed" << std::endl;
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        std::cerr << "Listen failed" << std::endl;
        return -1;
    }

    std::cout << "Waiting for connections..." << std::endl;

    while (true)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            std::cerr << "Accept failed" << std::endl;
            return -1;
        }

        char buffer[1024] = {0};
        read(new_socket, buffer, 1024);

        std::string content(buffer);
        saveToFile(content);

        const char *response = "Content received and saved.";
        send(new_socket, response, strlen(response), 0);

        close(new_socket);
    }

    return 0;
}