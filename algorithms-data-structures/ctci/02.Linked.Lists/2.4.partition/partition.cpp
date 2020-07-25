/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 2.4 partition
 *
 * Write code to parition a linked list around a value x, such that all nodes less
 * than x come before all nodes greater than or equal to x. If x is contained within
 * the list, the values of x only need to after the elements less than x (see below).
 * The partition element x can appear anywhere in the "right partition"; it does not
 * need to appear between the left and right partitions.
 *
 */
#include <iostream>

struct node {
int data;
struct node * next;
};


/**
 *  Partition the given linked list around the given 'partionNum'
 */
struct node * partition(int partitionNum, struct node * head) {
  struct node * curHead = head;
  struct node * curNode = curHead;
  struct node * prevNode = NULL;
  struct node * insertionNode = NULL;
  bool foundInsertionNode = false;

  while(curNode != NULL) {
    if ((curNode->data >= partitionNum)
        && (foundInsertionNode == false)) {
      insertionNode = prevNode;
      foundInsertionNode = true;
      prevNode = curNode;
      curNode = curNode->next;
      continue;
    }

    // insert curNode after insertionNode
    if ((curNode->data < partitionNum) && (foundInsertionNode == true)) {

      prevNode->next = curNode->next;

      if(insertionNode != NULL) {
        curNode->next = insertionNode->next;
        insertionNode->next = curNode;
        insertionNode = curNode;
      } else {
        // If the insertionNodes is found but it is null, then
        // the insertion happens in the front of the linked list
        curHead = curNode;
        curNode->next = head;
        insertionNode = curHead;
      }

      curNode = prevNode->next;

    } else {
      prevNode = curNode;
      curNode = curNode->next;
    }
  }
  return curHead;
}

int main() {
  int paritionNum;
  std::cin >> paritionNum;
  struct node * head = new node();
  struct node * curNode = head;
  struct node * prevNode = NULL;

  // Read the input linked list
  while(std::cin >> curNode->data) {
    curNode->next = new node();
    prevNode = curNode;
    curNode = curNode->next;
  }
  // The last node does not contain any input data, thus delete it!
  prevNode->next = NULL;
  delete curNode;

  // Print the linked list after partitioning
  prevNode = NULL;
  curNode = partition(paritionNum, head);
  while(curNode != NULL) {
    std::cout << curNode->data << " ";
    prevNode = curNode;
    curNode = curNode->next;
    delete prevNode;
  }
  std::cout << std::endl;

  return 0;
}
