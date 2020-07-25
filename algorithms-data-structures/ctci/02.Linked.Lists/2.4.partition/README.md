# Partition
### Cracking the Coding Interview 6th Ed.

Chapter 2: Linked Lists

Interview Question 2.4



Write code to parition a linked list around a value x, such that all nodes less
than x come before all nodes greater than or equal to x. If x is contained within
the list, the values of x only need to after the elements less than x (see below).
The partition element x can appear anywhere in the "right partition"; it does not
need to appear between the left and right partitions.


#### Example:

**Input:** 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
**Output:** 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
