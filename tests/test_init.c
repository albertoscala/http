#include <stdio.h>

#include "http/http.h"

int main()
{
    Conn conn;
    create_server(&conn, "172.20.10.2", 8080);
    return 0;
}