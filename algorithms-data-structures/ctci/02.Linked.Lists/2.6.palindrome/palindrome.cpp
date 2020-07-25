/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 2.6 palindrome
 *
 * Determine if a linked list is a palindrome.
 *
 * Assumptions:
 *
 * - Linked List consist of single digit data
 * - Data is in a doubly linked list
 *
 */

#include <iostream>

struct node {
  char data;
  struct node * prev;
  struct node * next;
};


/**
 * isPalindrome
 *
 * Check if the given linked list is a palindrome.
 */
bool isPalindrome(struct node * head) {
  // determine the tail node of this linked list
  node * tail = NULL;
  node * curNode = head;
  while(curNode->next != NULL) {
    curNode = curNode->next;
  }
  tail = curNode;

  // work inwards from both ends of the list to determine if it is a palindrome
  node * curHead = head;
  node * curTail = tail;
  while(true) {
    if (curHead->data != curTail->data) {
      return false;
    }
    if ((curHead->next == curTail->prev)
      || (curHead->next == curTail)
      || (curTail->prev == curHead)) {
      break;
    } else {
      curHead = curHead->next;
      curTail = curTail->prev;
    }
  }
  return true;
}

int main() {
  unsigned numDigits;
  std::cin >> numDigits;
  struct node * head = new node();
  struct node * curNode = head;
  struct node * prevNode = NULL;

  // read the digits into the linked list
  for(unsigned i = 0; i < numDigits; i++) {
    std::cin >> curNode->data;
    curNode->next = new node();
    curNode->prev = prevNode;
    prevNode = curNode;
    curNode = curNode->next;
  }

  // The last node does not contain any input data, thus delete it!
  prevNode->next = NULL;
  delete curNode;

  // print the result
  std::cout << isPalindrome(head) << std::endl;

  // apply cleanup
  prevNode = NULL;
  curNode = head;
  while(curNode != NULL) {
    prevNode = curNode;
    curNode = curNode->next;
    delete prevNode;
  }

  return 0;
}
