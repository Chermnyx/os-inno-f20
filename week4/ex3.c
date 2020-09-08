#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
  char buf[1337];
  while (1) {
    printf("cmd> ");
    fgets(buf, sizeof(buf), stdin);

    // we need to "run commands without parameters"...
    for (size_t i = 0; i < sizeof(buf); ++i) {
      if (buf[i] == ' ' || buf[i] == '&' || buf[i] == ';' || buf[i] == '\n') {
        buf[i] = '\0';
        break;
      }
      if (buf[i] == '\0') {
        break;
      }
    }

    if (!strcmp(buf, "exit")) {
      return 0;
    }
    system(buf);
  }
  return 0;
}
