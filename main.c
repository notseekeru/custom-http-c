#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *key;
  char *value;
} KVPair;

KVPair *kv_helper(char *key_source, char *value_source) {
  KVPair *pair = malloc(sizeof(KVPair));

  if (pair == NULL) return NULL;

  pair->key = malloc(strlen(key_source) + 1);
  if (pair->key == NULL) {
    free(pair);
    return NULL;
  }

  pair->value = malloc(strlen(value_source) + 1);
  if (pair->value == NULL) {
    free(pair->key);
    free(pair);
    return NULL;
  }

  strcpy(pair->key, key_source);
  strcpy(pair->value, value_source);

  return pair;
}

int main() {
  printf("\n");

  KVPair *my_pair = kv_helper("john_doe", "secret123");

  if (my_pair == NULL) return -1;

  printf("Key: %s\n", my_pair->key);
  printf("Value: %s\n", my_pair->value);

  free(my_pair->key);
  free(my_pair->value);
  free(my_pair);

  return 0;
}
