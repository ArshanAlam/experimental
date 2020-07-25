/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 1.4 Palindrome Permutation
 *
 * Given a string, write a function to check if it is a permutation of a
 * palindrome. A palindrome is a word or phrase that is the same forwards
 * and backwards. A permutation is a rearrangement of letters. The
 * palindrome does not need to be limited to just dictionary words.
 *
 */

#include <iostream>

const int NUM_STANDARD_ASCII_CHAR = 128;
const int SPACE_ASCII_NUM = ' ';

/**
 *  An array that contains the number of occurences of a character
 *  in the given input string.
 */
int charCount[NUM_STANDARD_ASCII_CHAR] = {0};

/**
 *  Process the given input string and determine the number
 *  of occurences of a character.
 */
void calcCharCount(std::string s) {
  unsigned N = s.length();
  const char * charStr = s.c_str();
  for (unsigned i = 0; i < N; i++) {
    if(charStr[i] != SPACE_ASCII_NUM) {
      charCount[charStr[i]]++;
    }
  }
}


/**
 *  Check if the given string 's' is a palindrome permutation.
 */
bool isPalindromePermutation(std::string s) {
  calcCharCount(s);
  bool foundOdd = false;
  for (unsigned i = 0; i < NUM_STANDARD_ASCII_CHAR; i++) {
    if ((charCount[i] % 2) == 1) {
      if (foundOdd == true) {
        return false;
      } else {
        foundOdd = true;
      }
    }
  }
  return true;
}


int main() {
  std::string s;
  std::getline(std::cin, s);
  if (isPalindromePermutation(s) == true) {
    std::cout << "true";
  } else {
    std::cout << "false";
  }
  std::cout << std::endl;
  return 0;
}
