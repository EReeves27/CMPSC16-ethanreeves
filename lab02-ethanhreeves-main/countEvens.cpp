#include "arrayFuncs.h"
#include <cstdlib>
#include <iostream>

int countEvens(int a[], int size) {
  int counter = 0;

  for (int i = 0; i < size; ++i)
  {
    if (a[i] % 2 == 0)
      ++counter;
  }
  return counter;
}
