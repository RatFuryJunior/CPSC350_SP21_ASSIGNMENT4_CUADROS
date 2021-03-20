#ifndef GENSTACK_H
#define GENSTACK_H
#include "ListNode.h"

template <typename T>
class GenStack{ //implemented form the one in class just to usse Linked list instead.
public:
  GenStack();
  ~GenStack();
  void push(T c);
  T pop();
  T peek();
  bool isEmpty();
  int size();

private:
  DoublyLinkedList<T> *stackLinked;
  int count; //number of items currently in stack
};

template <typename T>
GenStack<T>::GenStack(){//int iSize
  stackLinked = new DoublyLinkedList<T>();
}

template <typename T>
GenStack<T>::~GenStack(){
  delete stackLinked;
}

template <typename T>
bool GenStack<T>::isEmpty(){
  return (count==0);
}

template <typename T>
int GenStack<T>::size(){
  return count;
}

template <typename T>
void GenStack<T>::push(T c){
  stackLinked->insertFront(c);
  count++;
}

template <typename T>
T GenStack<T>::pop(){
  --count;
  return stackLinked->removeFront();
}

template <typename T>
T GenStack<T>::peek(){
T temp = stackLinked->removeFront();
stackLinked->insertFront(temp);
return temp;
}

#endif
