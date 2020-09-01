#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

void quicksort(int array[], size_t n) {
  if (n == 0) return;

  int* lt = malloc(sizeof(int) * n);
  size_t lt_n = 0;
  int* eq = malloc(sizeof(int) * n);
  size_t eq_n = 0;
  int* gt = malloc(sizeof(int) * n);
  size_t gt_n = 0;

  int pivot = array[n / 2];

  for (size_t i = 0; i < n; ++i) {
    if (array[i] < pivot) {
      lt[lt_n] = array[i];
      ++lt_n;
    } else if (array[i] == pivot) {
      eq[eq_n] = array[i];
      ++eq_n;
    } else {
      gt[gt_n] = array[i];
      ++gt_n;
    }
  }

  quicksort(lt, lt_n);
  quicksort(gt, gt_n);

  size_t k = 0;
  for (size_t i = 0; i < lt_n; ++i) {
    array[k] = lt[i];
    ++k;
  }
  for (size_t i = 0; i < eq_n; ++i) {
    array[k] = eq[i];
    ++k;
  }
  for (size_t i = 0; i < gt_n; ++i) {
    array[k] = gt[i];
    ++k;
  }
}

int main(int argc, char const* argv[]) {
  int n = 8;
  int a[] = {5, 4, 3, 1, 1, 2, 4, 5};
  quicksort(a, n);
  for (size_t i = 0; i < n; ++i) {
    printf("%d\n", a[i]);
  }
  return 0;
}
