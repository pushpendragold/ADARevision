#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

//Stacks
#include "04Stacks.h"
//Queue
#include "05Queues.h"

int ShowPushed = 1;
int ShowPoped = 1;
int ShowEnQueue = 0;
int ShowDeQueue = 0;
/********************************************
 *  Array Implementation of Queue 
 *  (Circular Array)
 *******************************************/
ArrayQueue::ArrayQueue(int _capacity)
{
   capacity = _capacity;
   A = new  int[capacity];
   front = rear = -1;
}
ArrayQueue::~ArrayQueue()
{
  delete [] A;
}
bool ArrayQueue::IsEmpty()
{
  return front == -1;
}
bool ArrayQueue::IsFull()
{
  return ((rear + 1) % capacity == front);
}
int ArrayQueue::QueueSize()
{
  return (capacity + (rear - front) + 1) % capacity;
}
void ArrayQueue::EnQueue(int data)
{
  if(IsFull())
  {
    printf("Queue is full\n");
    return;
  }
  if(ShowEnQueue)
    printf("EnQueue : %d\n",data);
  rear = (rear + 1) % capacity;
  A[rear] = data;
  if(front == -1)
    front = rear;
}
int ArrayQueue::DeQueue()
{
   int data = -1;
   if(IsEmpty())
   {
     printf("Queue already empty\n");
   }
   else if(front == rear)
   {
     data = A[front];
     front = rear = -1;
   }
   else
   {
      data = A[front];
      front = (front + 1) % capacity;
   }
   if(ShowDeQueue)
     printf("DeQueue : %d\n",data);
   return data;
}
/********************************************
 *  Linked List Implementation of Queue 
 *  (Infinite size theoritically)
 *******************************************/
void LinkedListQueue::EnQueue(int data)
{
   if(IsEmpty())
   {
      front = rear = new LNode(data);
   }
   else
   {
      LNode * tNode = new LNode(data);
      front->next = tNode;
      front = tNode;
   }
   if(ShowEnQueue)
    printf("EnQueue : %d\n",data);
}
int LinkedListQueue::DeQueue()
{
  if(IsEmpty())
  {
    printf("Queue is already empty.\n");
    return -1;
  }
  int data;
  if(front == rear)
  {
     data = rear->data;
     delete rear;
     rear = front = NULL;
  }
  else
  {
    data = rear->data;
    LNode * temp = rear->next;
    delete rear;
    rear = temp;
  }
  if(ShowDeQueue)
     printf("DeQueue : %d\n",data);
  return data;
}
int LinkedListQueue::QueueSize()
{
  LNode *tNode = front;
  int count = 0;
  while(tNode != NULL)
  {
    count++;
    tNode = tNode->next;
  }
  return count;
}
void LinkedListQueue::PrintQueue()
{
  LNode *tNode = rear;
  while(tNode != NULL)
  {
    printf("%d ",tNode->data);
    tNode = tNode->next;
  }
  printf("\n");
}
/*************************************************************
 * Queu 3. Reverse Queue Content using Queue ADT methods only
 * 
 * Comments : Stacks can be used easily.
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * 
 * **********************************************************/
void ReverseQueue(LinkedListQueue& queue)
{
   LinkedListStack stack;
   queue.PrintQueue();
   while(!queue.IsEmpty())
     stack.Push(queue.DeQueue());
   while(!stack.IsEmpty())
     queue.EnQueue(stack.Pop());
   queue.PrintQueue();
}
/*************************************************************
 * Queu 4. Implement Queue using two stacks.
 * 
 * Comments : 1) Create two stacks one for enqueue and other
 *               for Dequeue.
 *            2) On Inserting EnQueue in Enqueue stack.
 *            3) On DeQueuing : if DeQueue has elements pop them
 * 		 Otherwise empty EnQueue Stack to DeQueue stack
 *               and pop one element.
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * 
 * **********************************************************/
bool QueueUsingTwoStacks::IsEmpty()
{
   return EnQueueStack.IsEmpty() && DeQueueStack.IsEmpty();
}
void QueueUsingTwoStacks::EnQueue(int data)
{
   if(ShowEnQueue)
    printf("EnQueue : %d\n",data);
   EnQueueStack.Push(data);
}
int QueueUsingTwoStacks::DeQueue()
{
  int data = -1;
  if(!DeQueueStack.IsEmpty())
    data = DeQueueStack.Pop();
  else if(!EnQueueStack.IsEmpty())
  {
    while(!EnQueueStack.IsEmpty())
      DeQueueStack.Push(EnQueueStack.Pop());
    data = DeQueueStack.Pop();
  }
  if(ShowDeQueue)
     printf("DeQueue : %d\n",data);
  return data;  
}
/* END OF QUE 4 */

/*************************************************************
 * Queu 5. Implement Stack using two Queues.
 * 
 * Comments : 1) Create two Queues 
 *            2) Push : always push in the queue which is already 
 * 			filled, not in the empty queue.
 *            3) Pop  : Transfer n-1 element from the filled queue
 * 			To Empty queue then DeQueue last element.
 * 
 * Time Complexity : Push : O(1) Pop : O(N)
 * Space Complexity: O(N)
 * 
 * **********************************************************/
bool StackUsingTwoQueues::IsEmpty()
{
  return Q1.IsEmpty() && Q2.IsEmpty();
}
void StackUsingTwoQueues::Push(int data)
{
  if(ShowPushed)
    printf("Push : %d\n",data);
  count++;
  if(Q1.IsEmpty())
    Q2.EnQueue(data);
  else
    Q1.EnQueue(data);
}
int StackUsingTwoQueues::Pop()
{
  int data;
  if(IsEmpty())
  {
    printf("Stack is already empty.\n");
    return -1;
  }
  if(Q1.IsEmpty())
  {
    for(int i=0;i<count - 1;i++)
     Q1.EnQueue(Q2.DeQueue()); 
    data = Q2.DeQueue();
  }
  else
  {
    for(int i=0;i<count - 1;i++)
     Q2.EnQueue(Q1.DeQueue()); 
    data = Q1.DeQueue();
  }
  if(ShowPoped)
    printf("Poped : %d\n",data);
  count--;
  return data;
}
/* END OF QUE 5 */
/******************************************************************
 * Queu 6. Maximum in sliding window. For a given A[] with sliding
 *         window size w which is moving from left to right. 
 *         Assume that we can only see w elements in the window.
 * 
 * Comments : 1) in single traversal find first w numbers sum.
 * 	      2) While moving from left to right 1 element at 
 * 		 at time.
 * 	      3) + new element - first element from sum. compair with
 * 		max value if more update max otherwise move on.
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(1)
 * 
 * ****************************************************************/
int MaxSlidingWindow(int A[],int size,int w)
{
   if(size < w) 
     return -1;
   
   int max = 0;
   int cSum = 0;
   
   for(int i=0;i<w;i++)
     cSum += A[i];
   max = cSum;
   for(int i = w; i < size;i++)
   {
     cSum = cSum + A[i] - A[i-w];
     if(cSum > max)
       max = cSum;
   }
   return cSum;
}
/* END OF QUE 6 */
/******************************************************************
 * Queu 7. Given a Queue Q containing n elements, transfer these items 
 * on to a stack S(initially empty) so that front element of Q appears 
 * at the top of the stack and the order of all other items is 
 * preserved. Using enQueue and DeQueue operations for the queue and 
 * push and pop operations for the stack, outline an efficient O(n) 
 * algorithm to accomplish the above task,
 * Using the constant amout of additional storage.
 * 
 * Comments : 1) Transfer all elements from queue to stack. O(N)
 * 	      2) Transfer all elements from stack to queue. O(N)
 * 	      3) Transfer all elements from queue to stack. O(N)
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(1)
 * 
 * ****************************************************************/
LinkedListStack * StoreQueueElementInStack(LinkedListQueue &queue)
{
   LinkedListStack * stack = new LinkedListStack();
   while(!queue.IsEmpty())
     stack->Push(queue.DeQueue());
   stack->PrintStack();
   
   while(!stack->IsEmpty())
     queue.EnQueue(stack->Pop());
   queue.PrintQueue();
   
   while(!queue.IsEmpty())
     stack->Push(queue.DeQueue());
   return stack;
}
/* END OF QUE 7 */




































