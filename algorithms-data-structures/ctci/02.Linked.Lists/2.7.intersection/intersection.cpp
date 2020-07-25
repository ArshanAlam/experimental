/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 2.7 intersection
 *
 *  Given two (singly) linked lists, determine if the two lists intersect.
 *  Return the intersecting node. Note, that the intersection is defined based on
 *  reference, not value. This is, if the Kth node of the first linked list is the
 *  exact same node (by reference) as the jth node of the second linked list, then
 *  they are intersecting.
 *
 *
 */

#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <utility>

// the list can be atmost 64 nodes
#define MAX_LIST_SIZE 64

struct node {
  char data;
  struct node * next;
};

/**
 *  findIntersection
 *
 *  Find the intersecting node between list A and B. If the list do not intersect
 *  then return NULL.
 *
 * @return node | NULL
 */
node * findIntersection(node * A, node * B) {
  std::unordered_map<node *, node *> map;
  node * curNode = B;
  while (curNode != NULL) {
    map.insert(std::make_pair(curNode, curNode));
    curNode = curNode->next;
  }

  curNode = A;
  while (curNode != NULL) {
    if (map.find(curNode) != map.end()) {
      return curNode;
    } else {
      curNode = curNode->next;
    }
  }
  return NULL;
}

/**
 *  testFalseIntersection
 *
 *  Test for non-intersection.
 *
 *  @return true when test is passed, else false.
 */
bool testFalseIntersection() {
  unsigned listASize = rand() % MAX_LIST_SIZE;
  unsigned listBSize = rand() % MAX_LIST_SIZE;

  node * A = new node();
  node * B = new node();
  node * curA = A;
  node * curB = B;

  for (int i = 1; i < listASize; i++) {
    curA->next = new node();
    curA = curA->next;
  }

  for (int i = 1; i < listBSize; i++) {
    curB->next = new node();
    curB = curB->next;
  }

  bool status = (NULL == findIntersection(A, B));

  // apply cleanup
  curA = A;
  curB = B;

  while(curA != NULL) {
    node * old = curA;
    curA = curA->next;
    delete old;
  }

  while(curB != NULL) {
    node * old = curB;
    curB = curB->next;
    delete old;
  }

  return status;
}


/**
 *  testTrueIntersection
 *
 *  Test for intersection.
 *
 *  @return true when test is passed, else false.
 */
bool testTrueIntersection() {
  unsigned listASize = rand() % MAX_LIST_SIZE;
  unsigned insertIndexA = rand() % listASize;
  unsigned listBSize = rand() % MAX_LIST_SIZE;
  unsigned insertIndexB = rand() % listBSize;

  node * commonNode = new node();
  node * A = new node();
  node * B = new node();
  node * curA = A;
  node * curB = B;


  for(unsigned i = 0; i < listASize; i++) {
    curA->next = new node();
    curA = curA->next;
  }
  curA = A;
  for(unsigned i = 0; i < listASize; i++) {
    if (i == insertIndexA) {
      commonNode->next = curA->next;
      curA->next = commonNode;
      break;
    } else {
      curA = curA->next;
    }
  }

  for(unsigned i = 0; i < listBSize; i++) {
    if (i == insertIndexB) {
      curB->next = commonNode;
      break;
    }
    curB->next = new node();
    curB = curB->next;
  }

  bool status = (commonNode == findIntersection(A, B));

  curA = A;
  while(curA != NULL) {
    node * delNode = curA;
    curA = curA->next;
    if (delNode != commonNode) {
      delete delNode;
    }
  }

  curB = B;
  while(curB != NULL) {
    node * delNode = curB;
    curB = curB->next;
    if (delNode != commonNode) {
      delete delNode;
    } else {
      break;
    }
  }

  delete commonNode;
  return status;
}

int main() {
  std::cout << testFalseIntersection() << std::endl;
  std::cout << testTrueIntersection() << std::endl;
  return EXIT_SUCCESS;
}
