#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  size_t bufsize = 0;
  ssize_t chars;

  printf("Please enter some text: ");
  chars = getline(&buffer, &bufsize, stdin);
  printf("You entered (%zd chars): %s", chars, buffer);

  char *saveptr = NULL;
  char *token = strtok_r(buffer, " ", &saveptr);
  while (token) {
    printf("%s\n", token);
    token = strtok_r(NULL, " ", &saveptr);
  }
  free(buffer);
}
