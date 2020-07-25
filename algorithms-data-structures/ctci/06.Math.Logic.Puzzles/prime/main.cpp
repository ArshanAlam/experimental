/**
 * Testing Prime Lib.
 */
#include <primelib.h>
#include <iostream>
using namespace std;

int main() {
  cout << gcd(3209312, 4230992) << endl; // should be 16
  cout << isPrimeNaive(776531418) << endl; // false
  cout << isPrimeNaive(776531419) << endl; // true
  cout << isPrimeSlightlyBetter(776531419) << endl; // true

  // get a list of flags, for numbers <= 10, of primes
  int max = 10;
  bool * flags = sieveOfEratosthenesPrimes(max);
  for(int i = 0; i < (max + 1); i++) cout << i << " " << flags[i] << endl;
  delete[] flags;

  return 0;
}
