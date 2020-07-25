/**
 *  LinkedList
 *
 *  A template for a doubly linked list.
 *
 */

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <cstddef>

template <typename T>
class LinkedList {
private:
  struct node {
    node * next;
    node * prev;
    T data;
  };

  node * head;
  node * tail;
  int size;
  
  /**
   *  getTarget
   *
   *  @param index
   *  
   *  Get the item in the linked list at the given index.
   *
   *  If the index is greater than the size of the linked list, then
   *  the tail is returned. Similarly, if the index < 0, then the head
   *  is returned.
   */
  node * getTarget(int index) {
    node * target = NULL;
    if(index <= 0) {
      target = this->head;
    } else if(index >= (size - 1)) {
      target = this->tail;
    } else {
      int numIteration = (index < (size - 1 - index))? index : size - 1 - index;
      bool isBackward = (index != numIteration);
      target = (isBackward)? this->tail : this->head;
      for(int i = 0; i < numIteration; i++) {
        if(!isBackward) {
          target = target->next;
        } else {
          target = target->prev;
        }
      }
    }
    return target;
  }

public:
  /**
   *  LinkedList
   *  Construct a linked list.
   */
  LinkedList() {
    this->size = 0;
    this->head = NULL;
    this->tail = NULL;
  }

  /**
   *  ~LinkedList
   *  Destroy a linked list.
   */

  ~LinkedList() {
    while(!this->isEmpty()) {
      this->rmHead();
    }
  }
  
  /**
   *  getSize
   *
   *  Get the size of this linked list.
   */
  int getSize() {
    return this->size;
  }
  
  /**
   *  isEmpty
   *
   *  Determine if this linked list is empty.
   */
  bool isEmpty() {
    return (this->size <= 0);
  }

  /**
   *  addFront
   *
   *  @param T data - The data to add to this linked list.
   *
   *  Add the given data to the front of the linked list.
   */
  void addFront(T data) {
    node * item = new node;

    item->next = NULL;
    item->prev = NULL;
    item->data = data;

    if (this->head == NULL) {
      this->tail = item;
    } else {
      this->head->prev = item;
      item->next = this->head;
    }
    this->head = item;
    this->size += 1;
  }

  /**
   *  addBack
   *
   *  @param T data - The data to add to this linked list.
   *
   *  Add the given data to the back of the linked list.
   */
  void addBack(T data) {
    node * item = new node;
    
    item->next = NULL;
    item->prev = NULL;
    item->data = data;

    if(this->tail == NULL) {
      this->head = item;
    } else {
      this->tail->next = item;
      item->prev = this->tail;
    }
    this->tail = item;
    this->size += 1;
  }

  /**
   *  insertBefore
   *
   *  @param int index - The index to insert before.
   *  @param T data - The data to add to this linked list.
   *
   *  Add the given data before the item at the given index.
   */
  void insertBefore(int index, T data) {
    node * target = getTarget(index);
    if(target == NULL) {
      return;
    } else if(target == this->head) {
      addFront(data);
    } else {
      node * item = new node;
      item->data = data;
      target->prev->next = item;
      item->prev = target->prev;
      item->next = target;
      target->prev = item;
      this->size += 1;
    }
  }

  /**
   *  insertAfter
   *
   *  @param int index - The index to insert after.
   *  @param T data - The data to add to this linked list.
   *
   *  Add the given data after the item at the given index.
   */
  void insertAfter(int index, T data) {
    node * target = getTarget(index);
    if(target == NULL) {
      return;
    } else if(target == tail) {
      addBack(data);
    } else {
      node * item = new node;
      item->data = data;
      target->next->prev = item;
      item->next = target->next;
      target->next = item;
      item->prev = target;
      this->size += 1;
    }
  }

  /**
   *  rmHead
   *
   *  Remove the current head of this linked list.
   */
  void rmHead() {
    if(this->head == NULL) {
      return;
    }
    
    node * curHead = this->head;
    node * newHead = curHead->next;
    
    if(newHead != NULL) {
      newHead->prev = NULL;
    } else {
      this->tail = NULL;
    }

    this->head = newHead;
    this->size -= 1;
    delete curHead;
  }
 
  /**
   *  rmTail
   *
   *  Remove the current tail of this linked list.
   */
  void rmTail() {
    if(this->tail == NULL) {
      return;
    }
    
    node * curTail = this->tail;
    node * newTail = curTail->prev;
    
    if(newTail != NULL) {
      newTail->next = NULL;
    } else {
      this->head = NULL;
    }

    this->tail = newTail;
    this->size -= 1;
    delete curTail;
  }

  /**
   *  rm
   *
   *  @param index - Index of the item to remove.
   *
   *  Remove the item at given index.
   */
  void rm(int index) {
    node * target = getTarget(index);
    if(target == NULL) {
      return;
    } else if(target == this->head) {
      rmHead();
    } else if(target == this->tail) {
      rmTail();
    } else {
      node * next = target->next;
      node * prev = target->prev;
      prev->next = next;
      next->prev = prev;
      delete target;
      this->size -= 1;
    }
  }
  
  /**
   *  getHead
   *
   *  @param T * result - A pointer to set the data.
   *
   *  Retrieve the data in the head of this linked list.
   */
  void getHead(T * result) {
    if(this->head != NULL) {
      *result = this->head->data;
    }
  }

  /**
   *  getTail
   *
   *  @param T * result - A pointer to set the data.
   *
   *  Retrieve the data in the tail of this linked list.
   */
  void getTail(T * result) {
    if(this->tail != NULL) {
      *result = this->tail->data;
    }
  }

  /**
   *  get
   *
   *  @param index - The index of the item to retrieve.
   *  @param T * result - A pointer to set the data.
   *
   *  Retrieve the data in the given location of this linked list.
   */
  void get(int index, T * result) {
    node * target = getTarget(index);
    if(target != NULL) {
      *result = target->data;
    }
  }
};

#endif
