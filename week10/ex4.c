#include <dirent.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FOLDER \
  "/home/chermnyx/Documents/Innopolis/Course 2 Sem 1/OS/labs/week10/tmp/"

#define N 100
#define FNAME_SIZE 256
size_t n = 0;

typedef struct {
  char *name;
  ino_t inode;
  int printed;
} pair_t;

pair_t *pairs;

int main(int argc, char const *argv[]) {
  pairs = (pair_t *)calloc(N, sizeof(pair_t));

  DIR *dirp = opendir(FOLDER);
  if (dirp == NULL) return 1;
  size_t len = strlen(FOLDER);

  struct dirent *dp;

  size_t i;
  while ((dp = readdir(dirp)) != NULL) {
    (pairs + n)->name = (char *)calloc(FNAME_SIZE, sizeof(char));
    strcpy((pairs + n)->name, dp->d_name);
    (pairs + n)->inode = dp->d_ino;
    (pairs + n)->printed = 0;
    n++;
  }
  closedir(dirp);

  for (i = 0; i < n; ++i) {
    if ((pairs + i)->printed) continue;

    struct stat buf;

    // char *fpath = FOLDER + fname;
    char *fpath =
        (char *)malloc(strlen(FOLDER) + strlen((pairs + i)->name) + 1);
    strcpy(fpath, FOLDER);
    strcat(fpath, (pairs + i)->name);

    stat(fpath, &buf);
    free(fpath);
    if (buf.st_nlink < 2) continue;

    printf("i-node %ju: {\n", (uintmax_t)(pairs + i)->inode);

    size_t j;
    for (j = 0; j < n; ++j) {
      if ((pairs + j)->inode == (pairs + i)->inode && (!(pairs + j)->printed)) {
        printf("  '%s',\n", (pairs + j)->name);
        (pairs + j)->printed = 1;
      }
    }
    printf("}\n");
  }
  return 0;
}
