#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include <unistd.h>

int main()
{
    const int SIZE = 1024; // Size of the shared memory segment
    key_t key = 1234;      // Unique key for the shared memory segment

    // Create the shared memory segment
    int shmid = shmget(key, SIZE, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        std::cerr << "Error creating shared memory." << std::endl;
        return 1;
    }

    // Attach the shared memory segment
    char *str = (char *)shmat(shmid, nullptr, 0);
    if (str == (char *)-1)
    {
        std::cerr << "Error attaching shared memory." << std::endl;
        return 1;
    }

    // Write a message to the shared memory
    const char *message = "Hello from C++!";
    strncpy(str, message, SIZE);
    std::cout << "C++ Writer: Wrote to shared memory: " << message << std::endl;

    // Wait for user input before detaching and deleting the shared memory
    std::cout << "Press Enter to detach and delete the shared memory..." << std::endl;
    std::cin.get();

    // Detach and delete the shared memory
    shmdt(str);
    shmctl(shmid, IPC_RMID, nullptr);

    return 0;
}