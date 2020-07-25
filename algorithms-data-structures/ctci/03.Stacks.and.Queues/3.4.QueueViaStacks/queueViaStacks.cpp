/**
 *  Arshan Alam
 *
 *  CTCI 6e
 *
 *  Problem 3.4 Queue via Stacks
 *
 *  Implement a MyQueue class which implements a queue using two stacks.
 */

#include <LinkedList.h>
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
class MyQueue {
  private:
    LinkedList<T> listA;
    LinkedList<T> listB;

  public:
    MyQueue() {}
    ~MyQueue() {}

    void add(T data) {
      listA.addBack(data);
    }

    void remove(T * result) {
      if (listB.isEmpty()) {
        while(!listA.isEmpty()) {
          listA.getTail(result);
          listB.addBack(*result);
          listA.rmTail();
        }
      }
      listB.getTail(result);
      listB.rmTail();
    }

    void peek(T * result) {
      listB.getTail(result);
    }

    bool isEmpty() {
      return listA.isEmpty() && listB.isEmpty();
    }
};

int main() {
  int result;
  MyQueue<int> queue;
  
  queue.add(1);
  queue.add(2);
  
  queue.remove(&result);
  cout << result << endl;

  queue.add(3);
  
  queue.remove(&result);
  cout << result << endl;
  
  queue.add(4);
  queue.add(5);

  queue.remove(&result);
  cout << result << endl;

  queue.remove(&result);
  cout << result << endl;
  
  queue.remove(&result);
  cout << result << endl;
  
  

  return EXIT_SUCCESS;
}
