#ifndef _H_HEAP_
#define _H_HEAP_

#define NL printf("\n")

enum HEAPTYPE{
  MIN_HEAP,
  MAX_HEAP
};

class PriorityQueue{

private:
  int capacity;
  int count;
  int * A;
  int heap_type;

  int LeftChild(int i);
  int RightChild(int i);
  int Parent(int i);
  
  void PercolateDown(int data);
  void PercolateUp(int data);
  
public:
  PriorityQueue(int _capacity,int _heap_type);
  virtual ~PriorityQueue();
  int Size(){ return count ? count : -1;}
  int Top();
  int DeleteTop();
  void InsertElement(int data);
  void DeleteElement(int data);
  void Heapify(int A[],int n);
  void HeapSort(int array[],int n);
};

// Que 5. Given two arrays A and B each with n elements. Give an algorithm for finding largest n pairs (A[i],B[j])
void FindLargestPairs(int A[],int B[],int n);

// Que 6. Min-Max heap: Give an algorithm that supports min and max in O(1) time, insert, delete min, and
// delete max in O(logn) time. That means, design a data structure which supports following operations.
// Operations    :   Complexity
// Init			O(N)
// Insert		O(log(n))
// FindMin		O(1)
// FindMax		O(1)
// DeleteMin		O(log(n))
// DeleteMax		O(log(n))
class MinMaxQueue 
{
private :
  PriorityQueue * minHeap;
  PriorityQueue * maxHeap;
public:
   MinMaxQueue():minHeap(NULL),maxHeap(NULL){}
  ~MinMaxQueue(){delete minHeap; delete maxHeap;}
  
  void InIt();
  void Insert(int _data);
  int  FindMin();
  int  FindMax();
  int  DeleteMin();
  int  DeleteMax();
};

// Que 7. Dynamic median finding. Design a heap data structure that supports finding the medians.
int FindMedian(int val,int &median, PriorityQueue &max, PriorityQueue &min);
int Average(int a, int b);

#endif