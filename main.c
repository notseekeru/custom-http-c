#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main() {
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  addr.sin_addr.s_addr = INADDR_ANY;

  bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr));

  listen(socket_fd, 1);
  const char *msg = "Hello, Server!";
  int msg_len = strlen(msg);

  while (1) {
    int client_fd = accept(socket_fd, 0, 0);
    if (client_fd >= 1) {
      send(client_fd, msg, msg_len, 0);
      shutdown(client_fd, 1);
    }
  }

  shutdown(socket_fd, 1);
}
