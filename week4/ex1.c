#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
  int n;
  pid_t fork_pid = fork();
  pid_t pid = getpid();
  if (fork_pid == 0) {
    printf("Hello from child [%d - %d]\n", pid, n);
  } else {
    printf("Hello from parent [%d - %d]\n", pid, n);
  }
  return 0;
}

// The output will be different because PID values won't be the same.
// Also, the order of execution will be different.
// It's up to OS to schedule the different processes.
// the second value (n) will be the same for a parent and it's child because the
// OS copies memory only when a program will write into it.
