/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 2.3 Delete Middle Node
 *
 * Implement an algorithm to delete a node in the middle
 * (i.e. any node but the first and last node, not necessarily the
 * exact middle) of a singly linked list, given only access to that node.
 *
 */

#include <iostream>

struct node {
 int data;
 struct node * next;
};


/**
 * Delete the given node from a linked list.
 *
 * It is assumed that input parameter 'midNode' is not the first or the last
 * element in the linked list.
 */
void deleteNode(struct node * midNode) {
  struct node * curNode = midNode;
  struct node * nextNode = curNode->next;
  curNode->data = nextNode->data;
  curNode->next = nextNode->next;
  delete nextNode;
}


int main() {
  unsigned delNodeIndex;
  unsigned index = 0;
  std::cin >> delNodeIndex;
  struct node * head = new node();
  struct node * curNode = head;
  struct node * prevNode = NULL;
  struct node * delNode = NULL;

  // Read the input linked list
  while(std::cin >> curNode->data) {
    if(++index == delNodeIndex) {
      delNode = curNode;
    }
    curNode->next = new node();
    prevNode = curNode;
    curNode = curNode->next;
  }
  // The last node does not contain any input data, thus delete it!
  prevNode->next = NULL;
  delete curNode;

  // remove delNode
  deleteNode(delNode);

  // Print the linked list after removing delNode and apply clean up
  prevNode = NULL;
  curNode = head;
  while(curNode != NULL) {
    std::cout << curNode->data << " ";
    prevNode = curNode;
    curNode = curNode->next;
    delete prevNode;
  }
  std::cout << std::endl;

  return 0;
}
