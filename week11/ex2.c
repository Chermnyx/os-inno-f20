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
  char* buf = calloc(32, sizeof(char));
  setvbuf(stdout, buf, _IOLBF, 32);

  char* to_print = "Hello";
  size_t i = 0;
  for (i = 0; i < strlen(to_print); ++i) {
    printf("%c", *(to_print + i));
    sleep(1);
  }
  printf("\n");

  return 0;
}
