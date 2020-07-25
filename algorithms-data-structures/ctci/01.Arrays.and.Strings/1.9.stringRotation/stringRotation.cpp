/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 1.9 String Rotation
 *
 * Assume you have a method 'isSubstring' which checks if one word is a
 * substring of another. Given two strings, s1 and s2, write code to
 * check if s2 is a rotation of s1 using only one call to 'isSubstring'.
 *
 */

#include <iostream>
#include <cstdlib>
#include <string>

/**
 *  Some hypothetical function
 */
bool isSubstring(std::string s1, std::string s2) {
  return
      (s1.find(s2) != std::string::npos)
  ||  (s2.find(s1) != std::string::npos);
}

/**
 *  Determine if s2 is a string rotation of s1.
 */
bool isStringRotation(std::string s1, std::string s2) {
  if(s1.length() != s2.length()) {
    return false;
  }
  int strLen = s1.length();
  const char * s1Chars = s1.c_str();
  const char * s2Chars = s2.c_str();
  unsigned diffIndexS1 = 0;
  unsigned diffIndexS2 = 0;

  for(int i = 0; i < strLen; i++) {
    if(s1Chars[i] == s2Chars[0]) {
      diffIndexS1 = i;
      diffIndexS2 = strLen-i;
      for(int j = 1; j < strLen-i; j++) {
        if(s1Chars[i+j] != s2Chars[j]) {
          diffIndexS2 = j;
          break;
        }
      }
      break;
    }
  }

  /**
   *  Get the portion of the strings in s1 and s2
   *  that have not been matched.
   */
  std::string s1Sub = s1.substr(0, diffIndexS1);
  std::string s2Sub = s2.substr(diffIndexS2);
  return isSubstring(s1Sub, s2Sub);
}

/**
 *  Cleaner solution; where whenever s2 is a rotation of s1, then
 *  s2 is a substring of s1s1.
 */
bool isStringRotationClean(std::string s1, std::string s2) {
  return isSubstring(s1 + s1, s2);
}


int main() {
  std::string s1, s2;
  std::getline(std::cin, s1);
  std::getline(std::cin, s2);
  if(isStringRotationClean(s1, s2) == true) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
  return 0;
}
