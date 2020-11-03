#include <dirent.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const* argv[]) {
  FILE* file = fopen("/dev/random", "r");
  if (file == NULL) return -1;

  size_t len = 20;
  char* buf = (char*)calloc(
      len + 1, sizeof(char));  // len + 1 to make sure that the last byte is \0

  read(fileno(file), buf, len);

  FILE* out = fopen("ex1.txt", "w");

  printf("%s", buf);
  fprintf(out, "%s", buf);

  fclose(file);
  fclose(out);

  return 0;
}
