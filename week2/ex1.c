#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int int_v;
  float float_v;
  double double_v;

  int_v = INT_MAX;
  float_v = FLT_MAX;
  double_v = DBL_MAX;

  printf("int_v: %d %zu\n", int_v, sizeof(int_v));
  printf("float_v: %f %zu\n", float_v, sizeof(float_v));
  printf("double_v: %lf %zu\n", double_v, sizeof(double_v));
  return 0;
}
