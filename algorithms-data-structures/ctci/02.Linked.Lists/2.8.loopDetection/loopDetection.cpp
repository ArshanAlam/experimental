/**
 * Arshan Alam
 *
 * Cracking the Coding Interview 6th Edition
 *
 * Problem 2.8 Loop Detection
 *
 * Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.
 *
 * Defintion:
 * Circular linked list: A (corrupt) linked list in which a node's next pointer
 * points to an earlier node, so as to make a loop in the linked list.
 *
 *
 */

#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <utility>

struct node {
  char data;
  struct node * next;
};

/**
 *  findLoop
 *
 *  Find the node that results in a loop.
 *  If no such node, then return NULL.
 *
 * @return node | NULL
 */
node * findLoop(node * A) {
  node * curNode = A;
  std::unordered_map<node *, bool> map;
  while(curNode != NULL) {
    if (map.find(curNode) != map.end()) {
      return curNode;
    } else {
      map.insert(std::make_pair(curNode, true));
      curNode = curNode->next;
    }
  }
  return NULL;
}

bool testLoop() {
  node * A = new node();
  node * B = new node();
  node * C = new node();
  node * D = new node();
  node * E = new node();
  A->next = B;
  B->next = C;
  C->next = D;
  D->next = E;
  E->next = C;

  bool status = (findLoop(A) == C);

  delete A;
  delete B;
  delete C;
  delete D;
  delete E;

  return status;
}

/**
 *  testNonLoop
 *
 *  Test case that does not have a loop.
 */
bool testNonLoop() {
  node * A = new node();
  node * B = new node();
  node * C = new node();
  A->next = B;
  B->next = C;
  C->next = NULL;

  bool status = (findLoop(A) == NULL);

  delete A;
  delete B;
  delete C;

  return status;
}

int main() {
  std::cout << testNonLoop() << std::endl;
  std::cout << testLoop() << std::endl;
  return EXIT_SUCCESS;
}
