/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 2.1 Remove Dups
 *
 * Write code to remove duplicates from an unsorted linked list.
 *
 * How would you solve this problem if a temporary buffer is not allowed?
 *
 */

#include <iostream>

struct node {
  int data;
  struct node * next;
};

/**
 *  Remove duplicates from the unsorted linked list.
 */
struct node * removeDups(struct node * head) {
  struct node * uniqueLimit = head->next;
  struct node * curPosPrev = head;

  while(uniqueLimit != NULL) {
      struct node * it = head;
      bool found = false;
      while (it != uniqueLimit) {
        if (uniqueLimit->data == it->data) {
          found = true;
          break;
        } else {
          it = it->next;
        }
      }
      if (found == true) {
        curPosPrev->next = uniqueLimit->next;
        delete uniqueLimit;
        uniqueLimit = curPosPrev->next;
      } else {
        curPosPrev = uniqueLimit;
        uniqueLimit = uniqueLimit->next;
      }
  }

  return head;
}

int main() {
  struct node * head = new node();
  struct node * curPos = head;
  struct node * prevNode = NULL;

  while (std::cin >> curPos->data) {
    curPos->next = new node();
    prevNode = curPos;
    curPos = curPos->next;
  }
  prevNode->next = NULL;
  delete curPos;  // the last node does not contain any data

  curPos = removeDups(head);
  prevNode = NULL;

  while(curPos != NULL) {
    std::cout << curPos->data << " ";
    prevNode = curPos;
    curPos = curPos->next;
    delete prevNode;
  }
  std::cout << std::endl;

  return 0;
}
