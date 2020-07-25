/**
 *  LinkedList
 *
 *  A template for a linked list implementation.
 *
 */

#include <LinkedList.h>

#include <iostream>
using namespace std;

int main() {
  LinkedList<int> list;
  // 5 4 2 1 0 -1
  //
  // 1
  list.addFront(1);
  // 4 1
  list.addFront(4);
  // 4 1 0
  list.addBack(0);
  // 5 4 1 0
  list.insertBefore(-100, 5);
  // 5 4 1 0 -1
  list.insertAfter(100, -1);
  // 5 4 2 1 0 -1
  list.insertBefore(2, 2);
  // 5 4 3 2 1 0 -1 
  list.insertAfter(1, 3);
  
  int result = -200;
  list.getHead(&result);
  cout << result << endl;
  list.getTail(&result);
  cout << result << endl;
  list.get(3, &result);
  cout << result << endl;

  list.rmHead();
  list.rmTail();
  list.rm(3);

  return 0;
}
