/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 2.5 sumList
 *
 * You have two numbers represented by linked list, where each node contains a
 * single digit. The digits are stored in reverse order, such that 1's digit is at
 * the head of the list. Write a function that adds the two numbers and returns the
 * sum as a linked list.
 *
 */

#include <iostream>

struct node {
int data;
struct node * next;
};



/**
 *  Sum the linked lists in reverse order.
 */
struct node * sumBackward(struct node * one, struct node * two) {
  int carry = 0;
  struct node * sum = new node();
  struct node * sumCurrentNode = sum;
  struct node * sumCurrentPrev = NULL;
  struct node * curNodeOne = one;
  struct node * curNodeTwo = two;

  while (curNodeOne != NULL && curNodeTwo != NULL) {
    if (curNodeOne != NULL) {
      carry += curNodeOne->data;
      curNodeOne = curNodeOne->next;
    }
    if (curNodeTwo != NULL) {
      carry += curNodeTwo->data;
      curNodeTwo = curNodeTwo->next;
    }

    sumCurrentNode->data = carry % 10;
    sumCurrentNode->next = new node();
    sumCurrentPrev = sumCurrentNode;
    sumCurrentNode = sumCurrentNode->next;

    carry = carry / 10;
  }

  if (carry != 0) {
    sumCurrentNode->data = carry;
    sumCurrentNode->next = NULL;
  } else {
    sumCurrentPrev->next = NULL;
    delete sumCurrentNode;
  }

  return sum;
}



int main() {
  unsigned numDigitsOne, numDigitsTwo;
  std::cin >> numDigitsOne >> numDigitsTwo;
  struct node * headOne = new node();
  struct node * headTwo = new node();
  struct node * curNode = NULL;
  struct node * prevNode = NULL;

  // read number one
  curNode = headOne;
  prevNode = NULL;
  for(unsigned i = 0; i < numDigitsOne; i++) {
    std::cin >> curNode->data;
    curNode->next = new node();
    prevNode = curNode;
    curNode = curNode->next;
  }
  // The last node does not contain any input data, thus delete it!
  prevNode->next = NULL;
  delete curNode;

  // read number two
  curNode = headTwo;
  prevNode = NULL;
  for(unsigned i = 0; i < numDigitsTwo; i++) {
    std::cin >> curNode->data;
    curNode->next = new node();
    prevNode = curNode;
    curNode = curNode->next;
  }
  // The last node does not contain any input data, thus delete it!
  prevNode->next = NULL;
  delete curNode;


  // print the sum and apply cleanup
  struct node * sum = sumBackward(headOne, headTwo);
  prevNode = NULL;
  curNode = sum;
  while(curNode != NULL) {
    std::cout << curNode->data << " ";
    prevNode = curNode;
    curNode = curNode->next;
    delete prevNode;
  }
  std::cout << std::endl;


  // apply cleanup
  prevNode = NULL;
  curNode = headOne;
  while(curNode != NULL) {
    prevNode = curNode;
    curNode = curNode->next;
    delete prevNode;
  }
  prevNode = NULL;
  curNode = headTwo;
  while(curNode != NULL) {
    prevNode = curNode;
    curNode = curNode->next;
    delete prevNode;
  }


  return 0;
}
