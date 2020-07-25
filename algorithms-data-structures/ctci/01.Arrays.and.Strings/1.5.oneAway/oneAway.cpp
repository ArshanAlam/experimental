/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 1.5 One Away
 *
 *  There are three types of edits that can be performed on strings:
 *    - insert a character
 *    - remove a character, or
 *    - replace a character.
 *
 * Given two strings, write a function to check if they are
 * one edit (or zero edits) away.
 *
 */

#include <iostream>
#include <algorithm>
#include <cstdlib>

/**
 *  Check if string s1 and string s2 are AT MOST one away from each other.
 */
bool isOneAway(std::string s1, std::string s2) {
  /**
   *  Upfront checking
   */
  if (abs(s1.length() - s2.length()) > 1) {
    return false;
  }

  unsigned s1Len = s1.length();
  unsigned s2Len = s2.length();
  unsigned minLen = std::min(s1Len, s2Len);
  const char * s1Chars = s1.c_str();
  const char * s2Chars = s2.c_str();

  /**
   *  foundDiff is a boolean for indicating that a difference
   *  between s1 and s2 has been found.
   */
  bool foundDiff = false;
  unsigned index1 = 0;
  unsigned index2 = 0;
  while ((index1 < s1Len) &&  (index2 < s2Len)) {
    if (s1Chars[index1] == s2Chars[index2]) {
      index1++;
      index2++;
      continue;
    }

    if (foundDiff == true) { return false; }
    else if (s1Len == s2Len) {
      index1++;
      index2++;
    } else if (s1Len < s2Len) {
      if (s2Chars[index2+1] == s1Chars[index1]) {
          index2++;
      } else { return false; }
    } else {
      if (s2Chars[index2] == s1Chars[index1+1]) {
          index1++;
      } else { return false; }
    }

    foundDiff = true;
  }
  return true;
}

int main() {
  std::string s1;
  std::string s2;
  std::getline(std::cin, s1);
  std::getline(std::cin, s2);
  if(isOneAway(s1, s2) == true) {
    std::cout << "true";
  } else {
    std::cout << "false";
  }
  std::cout << std::endl;
}
