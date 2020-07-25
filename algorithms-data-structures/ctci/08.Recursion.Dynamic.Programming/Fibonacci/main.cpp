/**
 * Calling Fibonacci
 */

#include <fibonacci.h>
#include <iostream>
using namespace std;

int main() {
  int N = 32;
  cout << fibonacciRecursive(N) << endl;
  cout << fibonacciMemoization(N) << endl;
  cout << fibonacciMemoBottomUp(N) << endl;
  cout << fib(N) << endl;

  return 0;  
}
