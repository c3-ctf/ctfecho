#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BUF_SIZE 262144

const struct timespec req = {
  .tv_sec = 0,
  .tv_nsec = 10000000,
};

int main() {
  char* line;
  size_t len;
  while (1) {
    line = NULL; len = 0;
    ssize_t n_read = getline(&line, &len, stdin);
    if (n_read < 0)
      break;
    write(1, line, n_read);
    fsync(1);
    nanosleep(&req, NULL);
  }
}
