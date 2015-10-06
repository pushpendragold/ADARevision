#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#include "12Selection.h"
#include "tools.h"

//Que 1. Find the smallest and largest key in the given array A[].
void FindLargestAndSmallest(int A[], int n)
{
   int small = A[0];
   int large = A[0];
   for(int i=1;i<n;i++)
   {
      if(small > A[i]) small = A[i];
      if(large < A[i]) large = A[i];
   }
   printf("Smallest : %d\nLargest : %d\n",small,large);
}

//Que 2. Find the kth smallest number in given array A[].
int KthSmallestElement(int A[],int n,int k)
{
      return SelectionInt(A,0,n-1,k);
}
int SelectionInt(int A[], int low, int high, int k)
{
    if(low >  high) return -1;
    if(low == high) return A[low];
    
    int pivot = PartitionInt(A,low,high);
    
    if(k == pivot)
      return A[pivot];
    
    else if(k < pivot)
      return SelectionInt(A,low,pivot-1,k);
    
    return SelectionInt(A,pivot+1,high,k);
}
int PartitionInt(int A[], int low, int high)
{
   int pivotItem = A[low];
   int j = low;
   int i;
   for(i = low + 1; i<=high; i++)
   {
     if(A[i] < pivotItem)
     {
		 j++;
		 SwapInt(A[j],A[i]);
     }
  }
  int pivotPoint = j;
  SwapInt(A[low],A[pivotPoint]);
  return pivotPoint;
}
void SwapInt(int& a, int& b)
{
   int temp = a;
   a = b;
   b = temp;
}

//Que 3. Given two arrays each containing two sorted elements. Give an O(log(N))
//time algorithm to find the median of all 2n elements.
int FindMediansTwoArrays(int A[],int alow,int ahigh,int B[],int blow,int bhigh)
{
  int amid = alow + (ahigh - alow)/2;
  int aMedian = A[amid];
  
  int bmid = blow + (bhigh - blow)/2;
  int bMedian = B[bmid];
  
  int numberOfElements  = ahigh - alow + bhigh - blow + 2;
  int numberOfElementsA = ahigh - alow + 1;
  int numberOfElementsB = bhigh - blow + 1;
  
  if(numberOfElements <= 4) // Boundary condition
  {
    int temp[4]; // temp array
    int ai = alow;
    int bi = blow;
    int ti = 0;
    
    printf("ai = %d, bi = %d, ti = %d\n",ai,bi,ti);
    
    while(ai <= ahigh && bi <= bhigh)
    {
      if(A[ai] < B[bi])
		  temp[ti++] = A[ai++];
      else
		  temp[ti++] = B[bi++];
    }
    
    printf("ai = %d, bi = %d, ti = %d\n",ai,bi,ti);
    PrintArray(temp,ti);
    
    while(ai <= ahigh && temp[ti - 1] < A[ai])
		temp[ti++] = A[ai++];
    
    while(bi <= bhigh && temp[ti - 1] < B[bi])
      temp[ti++] = B[bi++];
    
    int mid = ti / 2;
    
    printf("temp array mid %d\n",mid);
    PrintArray(temp,ti);
    
    return temp[mid];
  }
  else if(aMedian == bMedian) 
  {
	  return aMedian;
  }
  else if(aMedian < bMedian)
  {
	  return FindMediansTwoArrays(A, amid, ahigh, B, blow, bmid);
  }
  else
  {
	  return FindMediansTwoArrays(A,alow,amid,B, bmid,bhigh);
  }
}
