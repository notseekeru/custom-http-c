#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char key[50];
  char value[50];
} KVPair;

KVPair *kv_helper(char *source) {
  KVPair *pair = malloc(sizeof(KVPair));

  if (pair == NULL) return NULL;

  strcpy(pair->key, "username");
  strcpy(pair->value, source);
  return pair;
}

int main() {
  printf("\n");

  KVPair *my_pair = kv_helper("john_doe");

  if (my_pair == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  printf("Key: %s\n", my_pair->key);
  printf("Value: %s\n", my_pair->value);

  free(my_pair);

  return 0;
}
