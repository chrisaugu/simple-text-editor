import sysv_ipc

# Define the same structure as in C++
MESSAGE_TYPE = 1

# Create a unique key for the queue
key = sysv_ipc.ftok("msgqueue", 65)
msg_queue = sysv_ipc.MessageQueue(key, sysv_ipc.IPC_CREAT)

# Send a message
msg_queue.send(b"Hello from Python!", type=MESSAGE_TYPE)
print("Message sent: Hello from Python!")
