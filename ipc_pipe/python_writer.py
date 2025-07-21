import os
import time

# Specify the path to the named pipe
pipe_path = "/tmp/my_named_pipe"

# Open the named pipe in write mode
with open(pipe_path, "w") as fifo:
    for i in range(5):
        message = f"Message {i + 1} from Python\n"
        fifo.write(message)
        fifo.flush()  # Ensure the message is sent immediately
        print(f"Written: {message.strip()}")
        time.sleep(1)  # Wait for a second before sending the next message
