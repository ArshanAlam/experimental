# Is unique
### Cracking the Coding Interview 6th Ed.

Chapter 1: Arrays and Strings

Interview Question 1.1

Implement an algorithm to determine if a string has all unique characters.
What if you cannot use additional data structures?


**Assumptions**
- ASCII string

This assumption is important because if the array has more than 128 characters then it must contain duplicates.



### Solution 1
Sort the array (string) and iterate through checking for duplicates.

### Solution 2
Build a heap using *bottom-up heapify* and use *delete-min* until the first duplicate has been removed from the heap.
