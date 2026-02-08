#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define EXIT_ERROR -1
#define PORT 8080
#define MAX_CLIENTS 256
#define BUF_SIZE 4096

typedef enum
{
    STATE_NEW,
    STATE_CONNECTED,
    STATE_DISCONNECTED
} state_e;

typedef struct
{
    int fd;
    state_e state;
    char buf[BUF_SIZE];
} clientstate_t;

clientstate_t clientstates[MAX_CLIENTS];

void init_clients()
{
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        clientstates[i].fd = -1;
        clientstates[i].state = STATE_NEW;
        memset(&clientstates[i].buf, '\0', BUF_SIZE);
    }
}

int find_free_slot()
{
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        if (clientstates[i].fd == -1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int nfds, listenfd, connectedfd, freeslot;
    fd_set readfds, writefds;
    struct sockaddr_in serverInfo, clientInfo;
    socklen_t clientAddrLen = sizeof(clientInfo);

    init_clients();

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(EXIT_ERROR);
    }

    memset(&serverInfo, 0, sizeof(struct sockaddr_in));
    serverInfo.sin_family = AF_INET;
    serverInfo.sin_addr.s_addr = INADDR_ANY;
    serverInfo.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&serverInfo, sizeof(serverInfo)) ==
        -1)
    {
        perror("bind");
        exit(EXIT_ERROR);
    }

    if (listen(listenfd, 10) == -1)
    {
        perror("listen");
        exit(EXIT_ERROR);
    }

    printf("server listening on port: %d\n", PORT);

    while (1)
    {
        FD_ZERO(&readfds);
        FD_ZERO(&writefds);

        FD_SET(listenfd, &readfds);
        nfds = listenfd + 1;

        // check for active connections in the state machine
        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            if (clientstates[i].fd != -1)
            {
                FD_SET(clientstates[i].fd, &readfds);

                if (clientstates[i].fd > nfds)
                {
                    nfds = clientstates[i].fd + 1;
                }
            }
        }

        if (select(nfds, &readfds, &writefds, NULL, NULL) == -1)
        {
            perror("select");
            exit(EXIT_ERROR);
        }

        if (FD_ISSET(listenfd, &readfds))
        {
            if ((connectedfd = accept(listenfd, (struct sockaddr *)&clientInfo, &clientAddrLen)) == -1)
            {
                perror("accept");
                continue;
            }

            printf("New connection from %s:%d\n", inet_ntoa(serverInfo.sin_addr),
                   ntohs(serverInfo.sin_port));

            freeslot = find_free_slot();
            if (freeslot != -1)
            {
                clientstates[freeslot].fd = connectedfd;
                clientstates[freeslot].state = STATE_CONNECTED;
            }
            else
            {
                printf("Server full, closing new connection\n");
                close(connectedfd);
            }
        }

        for (int i = 0; i < MAX_CLIENTS; i++)
        {
            if (clientstates[i].fd != -1 && FD_ISSET(clientstates[i].fd, &readfds))
            {
                ssize_t bytes_read = read(clientstates[i].fd, clientstates[i].buf,
                                          sizeof(clientstates[i].buf));

                if (bytes_read == -1)
                {
                    close(clientstates[i].fd);

                    clientstates[i].fd = -1;
                    clientstates[i].state = STATE_DISCONNECTED;
                    memset(&clientstates[i].buf, '\0', BUF_SIZE);

                    printf("Disconnecting client due to read error\n");
                }
                else
                {
                    printf("Recieved data from client:%s\n", clientstates[i].buf);
                }
            }
        }
    }

    close(listenfd);
    return 0;
}