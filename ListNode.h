#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>

//ListNode.h
using namespace std;

template <typename T>
class ListNode{
  public:
    ListNode();
    ListNode(T d);
    ~ListNode();
    ListNode<T> *next;
    ListNode<T> *prev;
    T data;
};


//implementation .cpp unless we are working with template classes
template <typename T>
ListNode<T>::ListNode(){}

template <typename T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;//NULL or 0 or nullptr
  prev = NULL;
}

template <typename T>
ListNode<T>::~ListNode(){
  next = NULL;//NULL or 0 or nullptr
  prev = NULL;
}


template <typename D>
//DoublyLinkedList.h
class DoublyLinkedList{
  private:
    ListNode<D> *front;
    ListNode<D> *back;
    ListNode<D> *temp;
    size_t listsize;
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(D data);
    void insertBack(D data);
    D removeFront();
    D removeBack();
    D remove(int key);
    D find(D value);
    bool isEmpty();
    size_t getSize();

    void printList(bool printLink);
};

//implementation .cpp unless we are working with template classes

template <typename D>
DoublyLinkedList<D>::DoublyLinkedList(){
  listsize = 0;
  front = NULL;
  back = NULL;
}

template <typename D>
DoublyLinkedList<D>::~DoublyLinkedList(){
  //loop for deletion
  while(front!=nullptr){
    temp = new ListNode<D>();
    temp = front;
    front = front -> next;
    delete temp;
  }
}

template <typename D>
void DoublyLinkedList<D>::insertFront(D data){
  ListNode<D> *node = new ListNode<D>(data);
  if(listsize == 0){
      back = node;
  }
  else{
      front->prev = node;
      node->next = front;
  }
  front = node;
  listsize++;
}

template <typename D>
void DoublyLinkedList<D>::insertBack(D data){
  ListNode<D> *node = new ListNode<D>(data);
  if(listsize == 0){
      front = node;
  }
  else{
    back->next = node;
    node->prev = front;
  }
  back = node;
  listsize++;
}

template <typename D>
D DoublyLinkedList<D>::removeFront(){
  ListNode<D> *tp = front;
  if(isEmpty()){
    cout<< "Something went wrong, Linked List isEmpty"<<endl;
    return 0;
  }else{  //check if size == 1
    if(front->next == 0){
      back = 0;
    }else{
      //size > 1
      front -> next -> prev = NULL;
    }
    front = front->next;
    tp->next = 0;
    D temp = tp->data;
    listsize--;
    return temp;
  }

}

template <typename D>
D DoublyLinkedList<D>::removeBack(){
  ListNode<D> *tp = back;
  if(isEmpty()){
    cout<< "Something went wrong, Linked List isEmpty"<<endl;
    return 0;
  }else{  //check if size == 1
    if(back->prev ==  0){
      front = 0;
    }else{
      //size > 1
      back -> prev -> next = NULL;
    }
    back = back -> prev;
    tp-> prev = 0;
    D temp = tp->data;
    listsize--;
    return temp;
  }
}

template <typename D>
D DoublyLinkedList<D>::remove(int key){
  ListNode<D> *current = front;

  while(current->data != key){
    current = current -> next;
    if(current == NULL){
      return 0;
    }
  }

  //found it lets now remove it
  if(current == front){
    front = current -> next;
    front -> prev = NULL;
  }
  else if (current == back){
    back = current -> prev;
    back -> next = NULL;
  }
  else{
    current -> prev -> next = current -> next;
    current -> next -> prev = current -> prev;
  }
  current -> prev = NULL;
  current -> next = NULL;

  D temp  = current -> data;
  listsize --;
  delete current;
  return temp;


}

template <typename D>
D DoublyLinkedList<D>::find(D value){
  int idx = -1;
  ListNode<D> *current = front;

  while(current != NULL){
    ++idx;
    if(current -> data == value){
      break;
    }else{
      current = current -> next;
    }
  }

  if(current == NULL){
    idx = -1;
  }
  return idx;
}

template <typename D>
bool DoublyLinkedList<D>::isEmpty(){
  return listsize == 0;
}

template <typename D>
size_t DoublyLinkedList<D>::getSize(){
  return listsize;
}

template <typename D>
void DoublyLinkedList<D>::printList(bool printLink)
{
    ListNode<D> *curr = front;
    while(curr != 0){
       if(curr == front){
         cout << "{FRONT}: ";
       }
       else if(curr == back){
         cout << "{REAR}: ";
       }
       if(printLink)
        cout << "[ PREV: "<< curr->prev << " || " << curr->data << " || NEXT: "<< curr->next << " ] ";
      else
        cout << "[ " << curr->data << " ] ";

       curr = curr->next;
       if(curr != 0){
         cout << " ==> ";
       }
    }
    cout << endl;
}

#endif
