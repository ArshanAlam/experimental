/**
 * Prime Lib
 *
 * Implementation of common Math operations
 * such as GCD, LCD, primality check, etc.
 */

#ifndef __PRIME_LIB_H__
#define __PRIME_LIB_H__

#include <cmath>

/**
 * gcd
 *
 * Calcuate the greatest common divisor using Euclid's Algorithm (iteratively)
 * GCD(a, b) = GCD(b, a mod b)
 */
int gcd(int a, int b) {
  while((a > 0) && (b > 0)) {
    int tmp = a % b;
    a = b;
    b = tmp;
  }

  if(a == 0) return b;
  return a;
}

/**
 * isPrimeNaive
 *
 * Check if the given number is prime using a naive approach of
 * checking for a factor for each number between 2 and n-1
 */
bool isPrimeNaive(int n) {
  if(n < 2) return false;
  for(int i = 2; i < n; i++) {
    if((n % i) == 0) return false;
  }
  return true;
}

/**
 * isPrimeSlightlyBetter
 *
 * Check if the given number is prime using a naive approach of
 * checking for a factor for each number between 2 and sqrt(n)
 */
bool isPrimeSlightlyBetter(int n) {
  if(n < 2) return false;
  double sqrt_n = sqrt(n);
  for(int i = 2; i < sqrt_n; i++) {
    if((n % i) == 0) return false;
  }
  return true;
}


/**
 * Find all the primes less than max.
 */
bool * sieveOfEratosthenesPrimes(int max) {
  // start off all numbers as prime and eliminate those that are not!
  bool * flags = new bool[max + 1];
  for(int i = 0; i < (max + 1); i++) flags[i] = true;

  flags[0] = flags[1] = false;
  int prime = 2;
  double sqrt_max = sqrt(max);
  while(prime < sqrt_max) {
    /**
     * cross off the multiples of prime.
     */
    for(int i = prime*prime; i < (max + 1); i += prime) {
      flags[i] = false;  
    }
    
    /**
     * determine the next prime.
     */
    while((++prime < (max + 1)) && (!flags[prime]));
  } // while
  return flags;
} // sieveOfErathosthenesPrimes

#endif
