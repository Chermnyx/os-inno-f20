#include <dirent.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define nres 3
#define nproc 5
#define INPUT_FILE "input_ok.txt"

int E[nres];
int A[nres];
int C[nproc][nres];
int R[nproc][nres];

int all(int flags[], size_t len) {
  size_t i = 0;
  for (i = 0; i < len; ++i) {
    if (flags[i] == 0) return 0;
  }
  return 1;
}

int check_res(int request_num) {
  size_t i;
  for (i = 0; i < nres; ++i) {
    if (R[request_num][i] > A[i]) return 0;
  }
  return 1;
}

void print_feedback(int sched, int proc_n) {
  printf("  schedulable: %d\n", sched);
  printf("  A   : ");
  size_t i;
  for (i = 0; i < nres; ++i) {
    printf("%d ", A[i]);
  }
  printf("\n");
  printf("  R[i]: ");
  for (i = 0; i < nres; ++i) {
    printf("%d ", R[proc_n][i]);
  }
  printf("\n");
  printf("  C[i]: ");
  for (i = 0; i < nres; ++i) {
    printf("%d ", C[proc_n][i]);
  }
  printf("\n");
}

int main(int argc, char const* argv[]) {
  FILE* input = fopen(INPUT_FILE, "rt");
  size_t i;

  for (i = 0; i < nres; ++i) {
    fscanf(input, "%d", &E[i]);
  }
  for (i = 0; i < nres; ++i) {
    fscanf(input, "%d", &A[i]);
  }

  size_t j;
  for (i = 0; i < nproc; ++i) {
    for (j = 0; j < nres; ++j) {
      fscanf(input, "%d", &C[i][j]);
    }
  }
  for (i = 0; i < nproc; ++i) {
    for (j = 0; j < nres; ++j) {
      fscanf(input, "%d", &R[i][j]);
    }
  }

  int flags[nproc];
  for (i = 0; i < nproc; ++i) flags[i] = 0;

  while (!all(flags, nproc)) {
    for (i = 0; i < nproc; ++i) {
      if (!flags[i]) {
        printf("Checking process %d {\n", i);
        int sched = check_res(i);
        print_feedback(sched, i);

        if (sched) {
          // running a process
          for (j = 0; j < nres; ++j) {
            // giving the resources
            A[j] -= R[i][j];
            C[i][j] += R[i][j];
            R[i][j] = 0;
            // using the resources

            // freeing the resources
            A[j] += C[i][j];
            C[i][j] = 0;
          }
          flags[i] = 1;

          i = -1;  // will be 0 at the next iteration
        }
        printf("}\n");
        if (sched) continue;
      }
    }

    if (!all(flags, nproc)) {
      printf(
          "OOOPS: the process are not schedulable and will cause a "
          "deadlock!\n");
      printf("The problematic ones: ");
      for (i = 0; i < nproc; ++i) {
        if (!flags[i]) {
          printf("%d ", i);
        }
      }
      printf("\n");
      return 0;
    }
  }

  printf("OK\n");
  return 0;
}
