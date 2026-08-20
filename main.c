#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main() {
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in addr = {AF_INET, htons(8080), {INADDR_ANY}};

  bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr));

  listen(socket_fd, 1);

  int client_fd = accept(socket_fd, 0, 0);

  const char *msg = "Hello, Server!";
  int msg_len = strlen(msg);

  int bytes_sent = send(client_fd, msg, msg_len, 0);

  shutdown(client_fd, 1);
  shutdown(socket_fd, 1);
}
