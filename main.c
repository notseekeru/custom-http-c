#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Goal: Extract "/index.html" from "GET /index.html HTTP/1.1"
// You cannot use strtok, strstr, or any high-level string function.
// Only pointer arithmetic and malloc.

// 1. Find the first space.
// 2. Move the pointer to the character after the first space.
// 3. Find the second space.
// 4. Allocate memory for the substring (use malloc).
// 5. Copy the substring into the allocated memory.
// 6. Return the pointer.
// Bonus: Handle edge cases (no space, invalid format).

typedef struct {
  char* key;
  char* value;
} KVPair;

char *kv_helper(char *source) {}

const char* extract_path(const char *request_line) {
  for (int i = 0; i < strlen(request_line); i++) {
    if (request_line[i] == ' '){
      return &request_line[i];
    }
  }
  return NULL;
}

int main() {
    char* line = "GET /index.html HTTP/1.1";
    const char* path = extract_path(line);
    printf("Path: %s\n", path);
    return 0;
}
