#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include NODE_H

template<typename T>
class LinkedList {

public:
   LinkedList();
   ~LinkedList();
   void appendNode(const T &);
   void addFront(const T);
   bool empty();
   void print();
   int nodeCount();

private:
   Node<T> * first;
   // Node<T> * last;
   Node<T> * newNode (const T &);

};

template <typename T>
LinkedList<T>::LinkedList() : first(NULL) {}

template <typename T>
LinkedList::~LinkedList() {
   if (!empty()) {
      NOde<T> * p = first;
      while (p != NULL) {
         Node<T> * next = p -> next;
         delete p;
         p = next;
      }
   }
}

#endif
