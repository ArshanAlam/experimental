/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 1.6 String Compression
 *
 * Implement a method to perform basic string compression using
 * the counts of repeated characters. **For Example**, the string
 * aabcccccaaa would become a2b1c5a3. If the "compressed" string
 * would not become smaller than the original string, your method
 * should return the original string. You can assume the string has
 * only uppercase and lowercase letters (a-z and A-Z).
 *
 */

#include <iostream>
#include <sstream>
/**
 *  Compress the given string str and return the compressed result
 */
std::string strCompress(std::string str) {
  unsigned len = str.length();
  std::ostringstream comStr;
  const char * strChars = str.c_str();
  unsigned index = 0;
  unsigned count = 1;
  char curChar = strChars[index];
  /**
   * Process the compression
   */
  while (index++ < len) {
    if (strChars[index] == curChar) {
      count++;
    } else {
      comStr << curChar;
      comStr << count;
      curChar = strChars[index];
      count = 1;
    }
  }

  /**
   * return the smaller string
   */
  std::string result = comStr.str();
  if(result.length() < len) {
    return result;
  } else {
    return str;
  }
}

int main() {
  std::string str;
  std::cin >> str;
  std::cout << strCompress(str) << std::endl;
  return 0;
}
