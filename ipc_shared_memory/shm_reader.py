import sysv_ipc


def main():
    key = 1234  # The same key used in C++

    # Access the existing shared memory segment
    try:
        shm = sysv_ipc.SharedMemory(key)
        print("Python Reader: Attached to shared memory.")

        # Read the value from shared memory
        message = shm.read()

        # Decode and print the message
        print("Python Reader: Read from shared memory:", message.decode().strip())

        # Clean up (detach) if necessary - not strictly needed here as it's read-only
        shm.detach()

    except sysv_ipc.ExistentialError:
        print("Shared memory does not exist.")


if __name__ == "__main__":
    main()
