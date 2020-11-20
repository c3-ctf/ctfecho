#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 262144

int main() {
  char* line;
  size_t len;
  while (1) {
    line = NULL; len = 0;
    ssize_t n_read = getline(&line, &len, stdin);
    if (n_read < 0)
      break;
    write(1, line, n_read);
    free(line);
  }
}
