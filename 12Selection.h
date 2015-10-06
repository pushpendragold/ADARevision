#ifndef _H_SELECTION_H_
#define _H_SELECTION_H_


//Que 1. Find the smallest and largest key in the given array A[].
void FindLargestAndSmallest(int A[],int n);

//Que 2. Find the kth smallest number in given array A[].
int  KthSmallestElement(int A[],int n,int k);
int  SelectionInt(int A[],int low,int high,int k);
int  PartitionInt(int A[],int low,int high);
void SwapInt(int &a,int &b);

//Que 3. Given two arrays each containing two sorted elements. Give an O(log(N))
//time algorithm to find the median of all 2n elements.
int FindMediansTwoArrays(int A[],int alow,int ahigh,int B[],int blow,int bhigh);

#endif