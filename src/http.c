#include "http/http.h"

#include <string.h>
#include <stdio.h>

int create_server(Conn* conn, const char* addr, const uint32_t port)
{
    conn->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (conn->socket == 0)
    {
        printf("[HTTP] Error while initialization...");
        return -1;
    }

    // Reusing addr
    int opt = 1;
    setsockopt(conn->socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    memset(&conn->sockaddr, 0, sizeof(struct sockaddr_in));
    conn->sockaddr.sin_family = AF_INET;
    inet_pton(AF_INET, addr, &conn->sockaddr.sin_addr);
    conn->sockaddr.sin_port = htons(port);

    // Bind
    if (bind(conn->socket, (struct sockaddr*)&conn->sockaddr, sizeof(struct sockaddr_in)) < 0)
    {
        printf("[HTTP] Error while binding...");
        return -1;
    }

    return 0;
}