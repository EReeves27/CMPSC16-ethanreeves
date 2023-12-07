#include <cassert>
#include "moreArrayFuncs.h"

// a: an array of ints.  size is how many ints in array
// Return the index of largest value.  
// If more than one element has largest value, 
// break tie by returning the smallest index that
// corresponds to an element with the largest value.
// You may assume size >= 1

int indexOfMax(int *a, int size) {
  assert(size >= 1);

  int maxVal = a[0];
  int maxValLocation = 0;
  for (int i = 1; i < size; ++i)
  {
    if (a[i] > maxVal)
    {
      maxVal = a[i];
      maxValLocation = i;
    }
  }
  return maxValLocation;
}

// a: an array of ints.  size is how many ints in array
// Return the index of smallest value.  
// If more than one element has largest value, 
// break tie by returning the smallest index that
// corresponds to an element with the largest value.
// You may assume size >= 1
int indexOfMin(int *a, int size) {
  assert(size >= 1);
  int minVal = a[0];
  int minValLocation = 0;
  for (int i = 1; i < size; ++i)
  {
    if (a[i] < minVal)
    {
      minVal = a[i];
      minValLocation = i;
    }
  }
  return minValLocation;
}

// a: an array of ints.  size is how many ints in array
// Return the largest value in the list.
// This value may be unique, or may occur more than once
// You may assume size >= 1
int largestValue(int *a, int size) {
  assert(size >= 1);
  int maxVal = a[0];
  //int maxValLocation = 0;
  for (int i = 1; i < size; ++i)
  {
    if (a[i] > maxVal)
    {
      maxVal = a[i];
      //maxValLocation = i;
    }
  }
  return maxVal;
}

// a: an array of ints.  size is how many ints in array
// Return the smallest value in the list.
// This value may be unique, or may occur more than once
// You may assume size >= 1

int smallestValue(int *a, int size) {
  assert(size >= 1);
  int minVal = a[0];
  //int minValLocation = 0;
  for (int i = 1; i < size; ++i)
  {
    if (a[i] < minVal)
    {
      minVal = a[i];
      //minValLocation = i;
    }
  }
  return minVal;
}


// a: an array of ints.  size is how many ints in array
// Return the sum of all the elements in the array
// size may be 0 in this case, or non-zero.

int sum(int *a, int size) {
  int sum = 0;
  
  for (int i = 0; i < size; ++i)
  {
    sum += a[i];
  }
  return sum;
}


// dest is an array of int that has capacity at LEAST of size n
// (whatever is in dest will be written over, so is irrelevant)
// src is an array of int of at least size n
// n is number of elements in src to be copied
// copy n elements from src to dest.

void copyElements(int *dest, int *src, int n) {
  for (int i = 0; i < n; ++i)
  {
    dest[i] = src[i];
  }
}

// dest is an array of int that has capacity at LEAST of size n
// (whatever is in dest will be written over, so is irrelevant)
// src is an array of int of at least size n
// n is number of elements in src to be copied
// copy ONLY the elements with odd values from src to dest.
// return the number of elements that were copied

int copyOddOnly(int *dest, int *src, int n) {
  int destValLoc = 0;
  for (int i = 0; i < n; ++i)
  {
    if (src[i] % 2 != 0)
    {
      dest[destValLoc] = src[i];
      ++destValLoc;
    }
  }
  return destValLoc; // stub @@@ FIX THIS 
}

// a, b and product are all arrays of size n (or greater)
// in each case, only the first n elements of a, b and product are used
// a and b have their values read, and are unchanged
// the old values in product are ignored, and overwritten.
// After this function, each element of product should
// contain the product of the corresponding elements of 
// a and b.
// Example if a is {1,2,3,4} b is {3,5,7,9} and n=4,
// then after a call to multiplePairwise(a,b,product,4), 
// product will be {3,10,21,36}.

void multiplyPairwise(int *a, int *b, int *product, int n) {
  for (int i = 0; i < n; ++i)
  {
    product[i] = a[i] * b[i];
  }
}

// len is the number of elements the array you create should contain
// you should return a pointer to the new integer array of size len
// with all of the elements in it set to 0
int* createArray(int len) {
  int* arr = new int[len];
  for (int i = 0; i < len; ++i)
  {
    arr[i] = 0;
  }
  return arr;
}
