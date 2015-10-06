#include <stdio.h>
#include <string.h>

#include <vector>
#include <algorithm>

#include "10Sorting.h"

SortingArray::SortingArray()
{
    A = NULL;
    count = 0;
}
SortingArray::~SortingArray() 
{
}
void SortingArray::init(int* B, int n)
{
  A = B;
  count = n;
}
void SortingArray::PrintArray()
{
  for(int i=0;i<count;i++)
    printf("%d ",A[i]);
  printf("\n");
}
void SortingArray::Swap(int& A, int& B)
{
   int t = A; A = B; B = t;
}
/********************************************************
 * Que 1. Bubble Sorting  (Inplace Sorting)
 * 
 * Comment :	1) All elements are sorted by checing 
 * 		each element with all other element
 * 		to find right position.
 * 
 * Space Complexity : O(1)
 * 
 * Worst case Complexity : O(n^2)
 * Best case Complexity (Improved version) : O(n)
 * Average case Complexity (Basic version) : O(n^2)
 * 		
 * *****************************************************/
void SortingArray::BubbleSort()
{
    for(int i = 0; i < count; i++)
    {
      for(int j = i+1; j < count; j++)
      {
		  if(A[i] > A[j])
			  Swap(A[i],A[j]);
      }
    }
}
/********************************************************
 * Que 2. Bubble Sorting  (Inplace Sorting)
 * 
 * Comment :	1) All elements are sorted by checing 
 * 		each element with all other element
 * 		to find right position.
 * 		2) Improved.
 * 
 * Space Complexity : O(1)
 * 
 * Worst case Complexity : O(n^2)
 * Best case Complexity (Improved version) : O(n)
 * Average case Complexity (Basic version) : O(n^2)
 * 		
 * *****************************************************/
void SortingArray::BubbleSortImproved()
{
    bool swapped = true;
    for(int i = 0; i < count && swapped; i++)
    {
      swapped = false;
      for(int j = i+1; j < count; j++)
      {
		  if(A[i] > A[j])
		  {
			  swapped = true;
			  Swap(A[i],A[j]);
		  }
      }
    }
}
/************************************************************
 * Que 3. Selection Sorting  (Inplace Sorting)
 * 
 * Comment :	1) Selection sort works well for small files.
 * it is used for sorting the files with very large values and
 * small keys. This is because of the fact that selection is 
 * made based on keys and swaps are made only when required.
 * 
 * Algo   : 
 *      1) Find the minimum value in the list.
 * 		2) Swap it with the value in the current position.
 * 		3) Repeat this process for all the elements
 * 		until the entire array is sorted.
 * 		
 * Space Complexity : O(1)
 * 
 * Worst case Complexity : O(n^2)
 * Best case Complexity (Improved version) : O(n)
 * Average case Complexity (Basic version) : O(n^2)
 * 		
 * *********************************************************/
void SortingArray::SelectionSort()
{
    for(int i=0; i < count-1; i++)
    {
      int min = i;
      for(int j = i+1; j < count; j++)
      {
		  if(A[j] < A[min])
			  min = j;
      }

      //Swap
      Swap(A[i],A[min]);
    }
}
/***********************************************************
 * Que 4. Insertion Sort (In-place sort)
 * 
 * Comment : Insertion sort is a simple and efficient 
 * comparison sort. In this algorithm each iteration 
 * removes an element from the input data and inserts 
 * it into the correct position in the list being sorted.
 * The choice of the element being removed from the input
 * is random and this process is repeated until all input
 * elements have been gone through.
 * 
 * 
 * Worst case Time Complexity : O(N^2)
 * Best  case Time Complexity : O(N^2)
 * Average case Time Complexity : O(N^2)
 * Worst case space Complexity : O(N^2) total, O(1) auxiliary
 * 
 * ********************************************************/
void SortingArray::InsertionSort()
{
    for(int i = 1; i < count; i++)
    {
      int v = A[i];
      int j = i - 1;
      
      while(j >= 0 && A[j] > v)
      {
		  A[j + 1] = A[j];
		  j--;
      }
      A[j + 1] = v;
    }
}
/***********************************************************
 * Que 5. Merge Sort
 * 
 * Comment : its an example of divide and conquer algorithm.
 * 
 * Performance :
 * 
 * Worst case complexity   : O(nlog(N))
 * Best case complexity    : O(nlog(N))
 * Average case complexity : O(nlog(N))
 * Worst case space complexity : O(N) auxiliary
 * 
 * ********************************************************/
void SortingArray::MergeSort(int left, int right)
{
    if(left < right)
    {
		int mid = left + ( right - left ) / 2;

		MergeSort(left,mid);
		MergeSort(mid+1,right);
		Merge(left,mid,right);
    }
}
void SortingArray::Merge(int left, int mid, int right)
{
   int left_start = left;
   int left_end = mid;
   int right_start = mid + 1;
   int right_end = right;
   int temp_pos = left;
   int size = right - left + 1;
   
   while(left_start <= left_end && right_start <= right_end)
   {
      if(A[left_start] < A[right_start])
		  temp[temp_pos++] = A[left_start++];
      else
		  temp[temp_pos++] = A[right_start++];
   }
   
   while(left_start <= left_end)
     temp[temp_pos++] = A[left_start++];
   
   while(right_start <= right_end)
     temp[temp_pos++] = A[right_start++];
   
   for(int i=0;i<=size;i++,right--)
     A[right] = temp[right];
}
/***********************************************************
 * Que 6. Heap Sort
 * 
 * Comment : its a comparison based sorting algorithm and is
 * part of the selection sort family. Although somewhat slower
 * in practice on most machines than a good implementation of
 * Quick Sort. it has the advantage of a more favorable
 * worst case : O(nlog(N)) runtime. HeapSort is in-place 
 * algorithm but is not a stable sort.
 * 
 * Performance :
 * 
 * Worst case complexity   : O(nlog(N))
 * Best case complexity    : O(nlog(N))
 * Average case complexity : O(nlog(N))
 * Worst case space complexity : O(N) total, O(1) auxiliary
 * 
 * ********************************************************/
void SortingArray::HeapSort()
{
   std::vector<int> v(A,A+count);
   for(int i=count - 1;i >= 0;i--)
   {
     std::make_heap(v.begin(),v.end());
     A[i] = v.front();
     std::pop_heap(v.begin(),v.end());
     v.pop_back();
   }
}
/***********************************************************
 * Que 6. Quick Sort
 * 
 * Comment : The quick sort is an example for divide and
 * conquer algorithm technique. It is also called partition
 * exchange sort. it uses recursive calls for sorting the 
 * elements. It is one of the famous algorithm among comparison
 * based sorting algorithm.
 * 
 * Algo : 
 * 	1) If there is one or no elements in the array to be 
 * 	sorted, return.
 * 	2) Pick an element in the array to serve as pivot point
 * 	(usually the left most element in the array is used)
 * 	3) Split the array into two parts - one with elements
 * 	larger than the pivot and the other with elements smaller
 * 	than the pivot.
 * 	4) Recursively repeat the algorithm for both halves of 
 * 	the original array.
 * 
 * Performance :
 * 
 * Worst case complexity       : O(n^2)
 * Best case complexity        : O(nlog(N))
 * Average case complexity     : O(nlog(N))
 * Worst case space complexity : O(1) 
 * 
 * ********************************************************/
void SortingArray::QuickSort(int low,int high)
{
    int pivot;
    if(high > low)
    {
        pivot = Partition(low,high);
        QuickSort(low,pivot - 1);
        QuickSort(pivot + 1,high);
    }
}
int SortingArray::Partition(int low, int high)
{
    int left,right;
	int pivot_item = A[low];
	bool bBreak = false;

    left = low;
    right = high;
	
    while(left < right)
    {
        bBreak = true;

		/* Move left while item < pivot */
        while(A[left] <= pivot_item && left <= high)
		{
			bBreak = false;
			left++;
		}

        /* Move right while item > pivot */
        while(A[right] > pivot_item && right>= low)
		{
			bBreak = false;
			right--;
		}

        if(bBreak) break;
        else if(left < right)
        {
            int temp = A[left];
            A[left] = A[right];
            A[right] = temp;
        }
        
    }

    /* right is final position for the pivot */
    A[low] = A[right];
    A[right] = pivot_item;
    return right;
}
/*****************************************************************
 * Que 8. Given an array A[] of n numbers containing repeatition 
 * of some numbers. Give an algorithm for checking whether there 
 * are repeated elements or not.Assume we are not allowed to use 
 * additional space.
 * 
 * Comemnts : Sort given array using Quick sort O(nlog(n))
 * 
 * Time Complexity : O(nLog(N))
 * Space Complexity : O(1)
 * 
 * ***************************************************************/
bool CheckDuplicates(int A[], int size)
{
    SortingArray sort;
    sort.init(A,size);
    sort.QuickSort(0,size-1);
    for(int i=0;i<size-1;i++)
      if(A[i] == A[i+1])
	return true;
    return false;
}
/****************************************************************
 * Que 9. Given two Array A[] and B[] find element a from A[] and 
 * b from B[] such that a + b = K.
 * 
 * Comments : 	1) Sort both the array and find a and b using
 * 		binary search.
 * 
 * Time Complexity : O(nlog(N)) + O(log(N)) = O(nlog(N))
 * Space Complexity: O(1)
 * 
 * **************************************************************/
bool FindPair(int A[], int B[], int nA, int nB, int k)
{
    //Sorting O(nLog(N))
  
    SortingArray sort;
    sort.init(A,nA);
    sort.QuickSort(0,nA - 1);
    sort.init(B,nB);
    sort.QuickSort(0,nB - 1);
    
    bool result = false;
    //Binary Search O(log(N))
    for(int i=0;i<nA;i++)
    {
      int c = k - A[i];
      if(BinarySearch(B,nB,c))
      {
		  result = true;
		  break;
      }
    }
    return result;
}
bool BinarySearch(int A[], int nA,int c)
{
    int low = 0;
    int high = nA - 1;
    
    int mid;
    while(low < high)
    {
       mid = (low + high)/2;
       if(A[mid] == c)
		   return true;
       else if(low >= high)
		   break;
       else if(A[mid] > c)
		   low = mid;
       else
		   high = mid;
    }
    return false;
}
