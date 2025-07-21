#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main()
{
    const char *pipe_path = "/tmp/my_named_pipe";
    char buffer[128];

    // Open the named pipe in read mode
    int fd = open(pipe_path, O_RDONLY);
    if (fd == -1)
    {
        std::cerr << "Error opening pipe." << std::endl;
        return 1;
    }

    std::cout << "Reading from named pipe..." << std::endl;

    while (true)
    {
        ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
        if (bytesRead > 0)
        {
            buffer[bytesRead] = '\0'; // Null-terminate the string
            std::cout << "Read: " << buffer;
        }
        else
        {
            break; // Exit on EOF or error
        }
    }

    close(fd);
    return 0;
}