import sysv_ipc

# Define the same structure as in C++
MESSAGE_TYPE = 1

# Create a unique key for the queue
key = sysv_ipc.ftok("msgqueue", 65)
msg_queue = sysv_ipc.MessageQueue(key)

# Receive a message
message, _ = msg_queue.receive(type=MESSAGE_TYPE)
print("Message received:", message.decode())
