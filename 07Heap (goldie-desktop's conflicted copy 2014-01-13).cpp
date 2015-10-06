#include <stdio.h>
#include <string.h>

#include "07Heap.h"

PriorityQueue::PriorityQueue(int _capacity, int _heap_type)
{
   capacity  = _capacity;
   heap_type = _heap_type;
   count = 0;
   A = new int[capacity];
   for(int i=0;i<capacity;i++)
     A[i] = 0;
}
PriorityQueue::~PriorityQueue()
{
  delete [] A;
}
int PriorityQueue::Parent(int i)
{
   if(i <= 0 || i >= count)
     return -1;
   return (i - 1)/2;
}
int PriorityQueue::LeftChild(int i)
{
   int left = 2*i + 1;
   if(left >= count || A[left] == 0) return -1;
   return left;
}
int PriorityQueue::RightChild(int i)
{
  int right = 2*i + 2;
  if(right >= count || A[right] == 0) return -1;
  return right;
}
int PriorityQueue::Top()
{
   if(count == 0) return -1;
   return A[0];
}
void PriorityQueue::PercolateDown(int i)
{
   int max = -1;
   int left  = LeftChild(i);
   int right = RightChild(i);
   
   if(left != -1 && heap_type == MAX_HEAP && A[left] > A[i]  ||
      left != -1 && heap_type == MIN_HEAP && A[left] < A[i])
    max = left;
   else
    max = i;
   
   if(right != -1 && heap_type == MAX_HEAP && A[right] > A[max] ||
      right != -1 && heap_type == MIN_HEAP && A[right] < A[max])
    max = right;
    
    if(max != i) //Swap with max index
    {
      int tmp = A[i];
      A[i] = A[max];
      A[max] = tmp;
      PercolateDown(max);
    }
}
void PriorityQueue::PercolateUp(int data)
{
   if(data == 0) return;
   int parent = Parent(data);
   if(parent != -1)
   {
      if(heap_type == MAX_HEAP && A[parent] < A[data] ||
	 heap_type == MIN_HEAP && A[parent] > A[data])
      {
	int temp = A[parent];
	A[parent] = A[data];
	A[data] = temp;
	PercolateUp(parent);
      }
   }
}
int PriorityQueue::DeleteTop()
{
   if(count != 0)
   {
     int data = A[0];
     A[0] = A[count - 1];
     A[count - 1] = 0;
     count--;
     PercolateDown(0);
     return data;
   }
   return -1;
}
void PriorityQueue::Heapify(int array[], int n)
{
    for(int i=0;i<n;i++)
      InsertElement(array[i]);
}
void PriorityQueue::InsertElement(int data)
{
    if(count == 0) 
    {
      A[0] = data;
      count++;
      return;
    }
    A[count] = data;
    count++;
    PercolateUp(count - 1);
}
void PriorityQueue::HeapSort(int array[], int n)
{
    for(int i=0;i<n;i++)
      InsertElement(array[i]);
    for(int i=n-1;i>=0;i--)
      array[i] = DeleteTop();
}
void PriorityQueue::DeleteElement(int data)
{
   int i = 0;
   for(;i<count;i++)
   {
      if(A[i] == data)
	break;
   }
   if(i == count) 
   {
     printf("Element not found in the heap. %d\n",data);
     return;
   }
   A[i] = A[count - 1];
   A[count - 1] = 0;
   count--;
   PercolateDown(i);
}
/* *************************************************************************
 * Que 5. Given two arrays A and B each with n elements. 
 * Give an algorithm for finding largest n pairs (A[i],B[j])
 * 
 * Comments - 	1) Heapify A and B - O(2*n) = O(N)
 * 		2) Keep on deleting the element from both the heaps (2log(n))
 * 
 * Time Complexity : O(nlog(N))
 * Space Complexity: O(N)
 * 
 * *************************************************************************/
void FindLargestPairs(int A[], int B[], int n)
{
   PriorityQueue queueA(n,MAX_HEAP),queueB(n,MAX_HEAP);
   queueA.Heapify(A,n);
   queueB.Heapify(B,n);
   for(int i=0;i<n;i++)
     printf("(%d,%d)\n",queueA.DeleteTop(),queueB.DeleteTop());
}
/****************************************************************************
* Que 6. Min-Max heap: Give an algorithm that supports min and max in O(1) 
* time, insert, delete min, and delete max in O(logn) time. That means, 
* design a data structure which supports following operations.
* Operations    :   Complexity
* Init			O(N)
* Insert		O(log(n))
* FindMin		O(1)
* FindMax		O(1)
* DeleteMin		O(log(n))
* DeleteMax		O(log(n))
* 
* ***************************************************************************/
void MinMaxQueue::InIt()
{
    minHeap = new PriorityQueue(20,MIN_HEAP);
    maxHeap = new PriorityQueue(20,MAX_HEAP);
}
void MinMaxQueue::Insert(int _data)
{
   minHeap->InsertElement(_data);
   maxHeap->InsertElement(_data);
}
int MinMaxQueue::FindMin()
{
   return minHeap->Top();
}
int MinMaxQueue::FindMax()
{
   return maxHeap->Top();
}
int MinMaxQueue::DeleteMax()
{
   int data = maxHeap->DeleteTop();
   minHeap->DeleteElement(data);
   return data;
}
int MinMaxQueue::DeleteMin()
{
   int data = minHeap->DeleteTop();
   maxHeap->DeleteElement(data);
   return data;
}
/***************************************************************************
 * Que 7. Find the median dynamically for given input array.
 * 
 * Comments : 
 *      1) A median heap can be implemented using two heaps each 
 * 		   containing half the elements.
 * 		2) One the max-heap containing the smallest elements, the
 * 		   other is a min-heap, containing the largest elements.
 * 		3) The size of the max-heap may be equal to the size of 
 * 		   the min-heap.
 * 		4) If the total number of elements are even, the median is
 * 		   the average of the maximum elements of the max-heap and
 * 		   the minimum element of the min heap.
 * 		5) if there are an odd number of elements, the max-heap will 
 * 		   contain one more element than the min-heap. The median in 
 * 		   this case is simply the maximum element of the max-heap.
 * 
 * **************************************************************************/
int FindMedian(int val, int& median, PriorityQueue& right, PriorityQueue& left)
{
  int lcount = left.Size();
  int rcount = right.Size();
  int returnVal = 0;
  
  // both same number of elements after adding one more element
  if(lcount == rcount) 
  {
    if(val < left.Top())
    {
      //Element will go to left
      left.InsertElement(val);
      returnVal = left.Top(); 
    }
    else
    {
      //Element will go to right
      right.InsertElement(val);
      returnVal = right.Top();
    }
  }
  else if( lcount > rcount ) //Left heap has more elements (max heap)
  {
     if(val < left.Top())
     {
       right.InsertElement(left.DeleteTop());
       left.InsertElement(val);
     }
     else
     {
	right.InsertElement(val);
    }
    returnVal = Average(left.Top(),right.Top());
  }
  else if( lcount < rcount ) //Right heap has more elements (min heap)
  {
      if(val < left.Top())
      {
	left.InsertElement(val);
      }
      else
      {
	left.InsertElement(right.DeleteTop());
	right.InsertElement(val);
      }
      returnVal = Average(left.Top(),right.Top());
  }
  return returnVal;
}
int Average(int a, int b)
{
    return (a + b) / 2;
}

































