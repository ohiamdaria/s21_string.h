#include <stdio.h>
#include "s21_string.h"


int main() {
  char *one = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *two = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  // int status = s21_sscanf(arr, " %f %d %n %p", &p, &a, &n, &q);
  printf("result: %s!\n", s21_trim(one, two));
  return 0;
}
