// Message Queue for Reader Proces
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>

struct Message
{
    long messageType;  // Message type
    char payload[100]; // Message content
};

int main()
{
    key_t key = ftok("msgqueue", 65);          // Generate unique key
    int msgid = msgget(key, 0666 | IPC_CREAT); // Get message queue

    Message message;

    msgrcv(msgid, &message, sizeof(message.payload), 1, 0); // Receive message
    std::cout << "Message received: " << message.payload << std::endl;

    msgctl(msgid, IPC_RMID, NULL); // Destroy the message queue

    return 0;
}