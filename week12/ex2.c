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
  int append = 0;
  char opt;
  while ((opt = getopt(argc, argv, "a")) != -1) {
    append = opt == 'a';
  }

  size_t n = argc - optind + 1;
  FILE** files = (FILE**)calloc(n, sizeof(FILE*));
  *(files + n - 1) = stdout;

  size_t i;
  for (i = optind; i < argc; ++i) {
    size_t fnum = i - optind;
    *(files + fnum) = fopen(argv[optind], append ? "a" : "w");
  }

  int m;
  char buf[64];

  while ((m = read(fileno(stdin), buf, sizeof buf)) > 0) {
    for (i = 0; i < n; ++i) {
      fwrite(buf, 1, m, *(files + i));
    }
  }
  return 0;
}
