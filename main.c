#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main() {
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    perror("socket");
    exit(1);
  }

  struct sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    exit(1);
  }

  if (listen(socket_fd, 1) < 0) {
    perror("listen");
    exit(1);
  }

  const char *msg = "Hello, Server!";
  int msg_len = strlen(msg);

  while (1) {
    int client_fd = accept(socket_fd, 0, 0);
    if (client_fd < 0) {
      perror("accept");
      continue;
    }

    send(client_fd, msg, msg_len, 0);

    close(client_fd);
  }

  // TODO: add proper graceful shutdown and cleanup code here
  shutdown(socket_fd, 1);
  close(socket_fd);
}
