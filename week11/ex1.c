#include <dirent.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FILENAME \
  "/home/chermnyx/Documents/Innopolis/Course 2 Sem 1/OS/labs/week11/ex1.txt"
#define FILLER "This is a nice day\n"

int main(int argc, char const* argv[]) {
  FILE* file = fopen(FILENAME, "w+");
  if (file == NULL) return -1;

  size_t len = sizeof(FILLER) - 1; // - '\0' symbol

  ftruncate(fileno(file), len);

  char* map =
      mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(file), 0);

  if (map == NULL) return -3;
  memcpy(map, FILLER, len);
  munmap(map, len);

  fclose(file);

  return 0;
}
