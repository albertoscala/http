#pragma once

#include <stdint.h>

#include <arpa/inet.h>
#include <sys/socket.h>

typedef struct {
    int socket;
    struct sockaddr_in sockaddr;
} Conn;

int create_server(Conn* conn, const char* addr, const uint32_t port);