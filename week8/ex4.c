#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/resource.h>

#define MB10 (10 * 1000 * 1000)

int main(int argc, char const* argv[]) {
  size_t i = 0;
  struct rusage usage;
  for (i = 0; i < 10; ++i) {
    void* mem = malloc(MB10);
    memset(mem, 0, MB10);

		getrusage(RUSAGE_SELF, &usage);
		printf("ru_maxrss: %ld\n", usage.ru_maxrss);

    sleep(1);
  }
  return 0;
}
