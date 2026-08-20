#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


int main() {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr = {AF_INET, htons(8080), {INADDR_ANY}};

    bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr));

    listen(socket_fd, 1);

    int client = accept(socket_fd, 0, 0);

    write(client, "Hello\n", 6);

    close(client);
    close(socket_fd);
}
