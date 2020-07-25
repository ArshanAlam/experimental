/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 2.2 Return Kth to Last
 *
 * Implement an algorithm to find the Kth to last element of a
 * singly linked list.
 *
 */

#include <iostream>

struct node {
 int data;
 struct node * next;
};


/**
 *  Find the Kth to last element.
 */
int kToLast(unsigned k, struct node * head) {
  struct node * curNode = head;
  unsigned n = 0;
  unsigned numNodesToElem = 0;
  while(curNode != NULL) {
    n++;
    curNode = curNode->next;
  }
  numNodesToElem = n-k;
  curNode = head;
  while(numNodesToElem > 0) {
    numNodesToElem--;
    curNode = curNode->next;
  }
  return curNode->data;
}


int main() {
  unsigned k;
  std::cin >> k;

  struct node * head = new node();

  // Read the input
  struct node * curNode = head;
  struct node * prev = NULL;
  while(std::cin >> curNode->data) {
    curNode->next = new node();
    prev = curNode;
    curNode = curNode->next;
  }
  // The last node does not contain any data
  prev->next = NULL;
  delete curNode;

  // output result
  std::cout << kToLast(k, head) << std::endl;

  // Clean up
  curNode = head;
  prev = NULL;
  while(curNode != NULL) {
    prev = curNode;
    curNode = curNode->next;
    delete prev;
  }

  return 0;
}
