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
#define FILENAME2 \
  "/home/chermnyx/Documents/Innopolis/Course 2 Sem 1/OS/labs/week11/ex1.memcpy.txt"
#define FILLER "This is a nice day\n"

int main(int argc, char const* argv[]) {
  FILE* file1 = fopen(FILENAME, "r+");
  if (file1 == NULL) return -1;
  FILE* file2 = fopen(FILENAME2, "w+");
  if (file2 == NULL) return -1;

  struct stat buf;
  if (stat(FILENAME, &buf) != 0) return -2;

  ftruncate(fileno(file2), buf.st_size);

  char* map1 = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED,
                    fileno(file1), 0);
  char* map2 = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED,
                    fileno(file2), 0);

  if (map1 == NULL) return -3;
  if (map2 == NULL) return -3;

  memcpy(map2, map1, buf.st_size);
  munmap(map2, buf.st_size);

  fclose(file1);
  fclose(file2);
  return 0;
}
