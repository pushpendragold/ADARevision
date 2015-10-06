#ifndef _H_Sorting_
#define _H_Sorting_

class SortingArray{
  
private : 
  
  int * A;
  int count;
  
  // temp array for merge sort
  int temp[20];

public :
  
  SortingArray();
 ~SortingArray();
 
  void init(int * B,int n);
  void PrintArray();
  //Que 1. BubbleSort
  void BubbleSort();
  //Que 2. BubbleSortImproved
  void BubbleSortImproved();
  //Que 3. Selection Sort 
  void SelectionSort();
  //Que 4. Insertion Sort
  void InsertionSort();
  //Que 5. Merge Sort
  void MergeSort(int left,int right);
  void Merge(int left,int mid,int right);
  //Que 6. Heap Sort
  void HeapSort();
  //Que 7. Quick Sort
  void QuickSort(int low,int high);
  int  Partition(int low,int high);
  
  //Sort Swap
  void Swap(int &A,int &B);
};

//Que 8. Given an array A[] of n numbers containing repeatition of some numbers. 
//Give an algorithm for checking whether there are repeated elements or not.
//Assume we are not allowed to use additional space.
bool CheckDuplicates(int A[],int size);

//Que 9. Given two Array A[] and B[] find element a from A[] and b from B[] such that a + b = K
bool FindPair(int A[],int B[],int nA,int nB,int k);
bool BinarySearch(int A[],int nA,int c);

#endif