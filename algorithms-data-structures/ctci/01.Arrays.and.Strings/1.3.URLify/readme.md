
# URLify
### Cracking the Coding Interview 6th Ed.

Chapter 1: Arrays and Strings

Interview Question 1.3

Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.

**NOTE:** If implementing in Java, please use a character array so that you can perform this operation in place.

EXAMPLE:

Input: &nbsp;&nbsp; `"Mr John Smith____", 13`

Output:             `"Mr%20John%20Smith"`


### Solution

Iterate through the input string in reverse beginning from the last character in the true length of the string. For each character that is not a space, swap that character with the last available spot in the string. If the character is a space, then insert characters '0', '2', '%', in that order, to the last available spots.

**NOTE:** No need to worry about SEGFAULT because the *given* string has enough space towards the end; to account for the extra characters.
