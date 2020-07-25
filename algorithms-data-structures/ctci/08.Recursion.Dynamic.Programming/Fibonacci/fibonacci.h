/**
 * A library for implementing different approaches
 * to calculating the fibonacci numbers.
 */

#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__

#include <algorithm>

int fibonacciRecursive(int);
int fibonacciMemoization(int);
int fibonacciMemo(int, int *);
int fibonacciMemoBottomUp(int);


int fibonacciRecursive(int n) {
  if(n <= 0) return 0;
  if(n == 1) return 1;
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}


int fibonacciMemoization(int n) {
  int * mem = new int[n + 1];
  std::fill(mem, mem + n + 1, 0);
  int result = fibonacciMemo(n, mem);
  delete[] mem;
  return result;
}


int fibonacciMemo(int n, int * mem) {
  if(n <= 0) return 0;
  if(n == 1) return 1;
  int result = mem[n];
  if(result == 0) {
    result = fibonacciMemo(n - 1, mem) + fibonacciMemo(n - 2, mem);
    mem[n] = result;
  }
  return result;
}


int fibonacciMemoBottomUp(int n) {
  if(n <= 0) return 0;
  if(n == 1) return 1;
  
  int result = 0;
  int * mem = new int[n + 1];
  std::fill(mem, mem + n + 1, 0);
  mem[1] = 1;

  for(int i = 2; i <= n; i++) {
    mem[i] = mem[i - 1] + mem[i - 2];
  }

  result = mem[n];
  delete[] mem;
  return result;
}

int fib(int n) {
  if(n <= 0) return 0;
  if(n == 1) return 1;
  int n_2 = 0;
  int n_1 = 1;
  int result = n_1 + n_2;
  for(int i = 3; i <= n; i++) {
    n_2 = n_1;
    n_1 = result;
    result = n_1 + n_2;
  }
  return result;
}

#endif
