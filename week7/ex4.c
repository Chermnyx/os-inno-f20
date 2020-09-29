#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* realloc_(void* ptr, size_t new_size) {
  if (ptr == NULL) return malloc(new_size);
  if (new_size == 0) {
    free(ptr);
    return NULL;
  }

  void* new_ptr = malloc(new_size);
  memcpy(new_ptr, ptr, new_size);
  free(ptr);
  return new_ptr;
}

int main(int argc, char const* argv[]) {
  void* a = malloc(5 * sizeof(int));
  a = realloc_(a, 3 * sizeof(int));
  return 0;
}
