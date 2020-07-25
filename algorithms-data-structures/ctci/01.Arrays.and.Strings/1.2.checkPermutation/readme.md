
# Check Permutation
### Cracking the Coding Interview 6th Ed.

Chapter 1: Arrays and Strings

Interview Question 1.2

Given two strings, write a method to decide if one is a permutation of the other.


**Assumptions**
- ASCII string
- Both strings have the same length

If the strings have different lengths, then they cannot be permutations of each other.



### Solution
Sort the strings *s1* and *s2* then iterate through checking whether they are the same.
