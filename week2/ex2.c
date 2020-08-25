#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const* argv[]) {
  size_t size = 127;
  char* str = malloc(size + 1);
  getline(&str, &size, stdin);

  // \n is already included because of usage of `getline()`
  printf("%s", str);
  size_t len = strlen(str);
  for (long long i = len - 2; i >= 0; --i) {
    printf("%c", *(str + i));
  }
  printf("\n");
  return 0;
}
