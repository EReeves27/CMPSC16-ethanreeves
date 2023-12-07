#include "arrayFuncs.h"
#include <cstdlib>
#include <iostream>
#include "utility.h"

#include "utility.h"

int countPrimes(int a[], int size) {
  int counter = 0;
  bool check;

  for (int i = 0; i < size; ++i)
  {
    check = isPrime(a[i]);

    if (check)
      ++counter;
  }
  return counter;
}
