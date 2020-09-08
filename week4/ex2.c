#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
  for (size_t i = 0; i < 5; ++i) {
    fork();
  }
  unsigned int sec = 5;
  sleep(sec);
  return 0;
}

/*
The `pstree` will be the following:
├─zsh───ex2─┬─ex2─┬─ex2───ex2
│           │     └─ex2
│           ├─ex2───ex2
│           └─ex2
First, the shell starts `ex2` program explicitly.
Then, each instance of `ex2` forks itself and continues the execution.
A new process becomes a child of the old process.
In the next iteration each instance of ex2 forks itself again.
Therefore, in the end of execution there is 2^3 = 8 processes.

After changing the program to fork() 5 times the tree will be the following (32
processes)
─zsh─┬─ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
     │     │     │     │     └─ex2
     │     │     │     ├─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2─┬─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2───ex2
     │     │     └─ex2
     │     ├─ex2─┬─ex2─┬─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2───ex2
     │     │     └─ex2
     │     ├─ex2─┬─ex2───ex2
     │     │     └─ex2
     │     ├─ex2───ex2
     │     └─ex2

After each fork number of childs of the next process is decreases by one as it
each child forks itself N-1 times
*/
