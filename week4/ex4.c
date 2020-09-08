#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
  char buf[1337];
  while (1) {
    printf("cmd> ");
    fgets(buf, sizeof(buf), stdin);

    // now there is no code that strips the arguments
    // the background tasks also work because system() handles it ¯\_(ツ)_/¯

    if (!strcmp(buf, "exit\n")) {
      return 0;
    }
    system(buf);
  }
  return 0;
}
