#ifndef _H_QUEUES_
#define _H_QUEUES_

#include "04Stacks.h"

class ArrayQueue{
  
private:
  int capacity;
  int * A;
  int rear,front;
public:
  ArrayQueue(int _capacity);
 ~ArrayQueue();
  void EnQueue(int data);
  bool IsEmpty();
  bool IsFull();
  int  DeQueue();
  int  QueueSize();
};

class LinkedListQueue{
private:
  
  class LNode{
  public:
    int data;
    LNode * next;
    LNode(int data)
    {
      this->data = data;
      this->next = NULL;
    }
   ~LNode(){}
  };
  
LNode * front;
LNode * rear;

public:
  LinkedListQueue():front(NULL),rear(NULL){}
 ~LinkedListQueue(){}
  bool IsEmpty(){return front == NULL || rear == NULL;}
  void EnQueue(int data);
  int  DeQueue();
  int  QueueSize();
  void PrintQueue();
};

//Que 3. Reverse Queue using Queue ADT methods.
void ReverseQueue(LinkedListQueue &queue);

//Que 4. Implement Queue using Two stacks.
class QueueUsingTwoStacks{
private : 
  LinkedListStack EnQueueStack;
  LinkedListStack DeQueueStack;
public:
  void EnQueue(int data);
  int  DeQueue();
  bool IsEmpty();
};
//Que 5. Implement Stack using two Queue
class StackUsingTwoQueues{
private :
  LinkedListQueue Q1;
  LinkedListQueue Q2;
  int count;
public :
  StackUsingTwoQueues():count(0){}
 ~StackUsingTwoQueues(){}
  void Push(int data);
  int  Pop();
  bool IsEmpty();
};

//Que 6. Maximum in sliding window. For a given A[] with sliding window size w,
//which is moving from left to right. 
//Assume that we can only see w elements in the window.
int MaxSlidingWindow(int A[],int size,int w);

//Que 7. Given a Queue Q containing n elements, transfer these items on to a stack S(initially empty) 
//so that front element of Q appears at the top of the stack and the order of all other items is 
//preserved. Using enQueue and DeQueue operations for the queue and push and pop operations for the 
//stack, outline an efficient O(n) algorithm to accomplish the above task,
//Using the constant amout of additional storage.
LinkedListStack * StoreQueueElementInStack(LinkedListQueue &queue);


#endif