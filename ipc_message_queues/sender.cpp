// Message Queue for Sender Proces
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
    int msgid = msgget(key, 0666 | IPC_CREAT); // Create message queue

    Message message;
    message.messageType = 1;                    // Set message type
    strcpy(message.payload, "Hello from C++!"); // Set payload

    // printf("Write Data: ");
    // fgets(message.payload, MAX, stdin);

    msgsnd(msgid, &message, sizeof(message.payload), 0); // Send message
    std::cout << "Message sent: " << message.payload << std::endl;

    return 0;
}