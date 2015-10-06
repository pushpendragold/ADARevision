#include <stdio.h>
#include <string.h>
#include <climits>
#include <cstdlib>

#include <map>

#include "10Sorting.h"
#include "11Searching.h"

using namespace std;

/************************************************************
 * Que 1. check if there are any repeated numbers in given 
 * array.
 * 
 * Comment : Use hash table
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * 
 * *********************************************************/
bool CheckDuplicatesNumbers(int A[], int n)
{
      map<int,int> hash;
      for(int i=0;i<n;i++)
      {
	 if(hash[A[i]] == 0)
	    hash[A[i]] = 1;
	 else
	   return true;
      }
      return false;
}
/************************************************************
 * Que 2. Given an array of n numbers, give an algorithm for 
 * finding the first element in the array which is repeated. 
 * For example, in the array, A = {3,2,1,2,2,3} the first 
 * repeated number is 3(not 2). This means we are required 
 * to return the first element among the repeated numbers.
 * 
 * Comment : 	1) Use hash table, Maintain hash table with indices
 * -(ve) for repeated numbers. Ex. if first time 2 comes with
 * index 3 on second occurance 3 will became -3.
 * 		2) After completing hashing return the biggest
 * -(ve) number.
 * 
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * 
 * *********************************************************/
int FindFirstRepeatedNumber(int A[], int n)
{
    map<int,int> hash;
    map<int,int>::iterator itr;
    
    for(int i=0;i<n;i++)
    {
      if(hash[A[i]] == 0)
	hash[A[i]] = i + 1;
      else if(hash[A[i]] > 0)
	  hash[A[i]] = (-1)*hash[A[i]];
    }
    int num = -1, index = -999;
    for(itr=hash.begin();itr != hash.end(); itr++)
    {
       if((*itr).second < 0 && index < (*itr).second)
       {
	 index = (*itr).second;
	 num = (*itr).first;
       }
    }
    return num;
}
/************************************************************
 * Que 3. Find the number which occurs odd number of times in
 * given array.
 * 
 * Comment : 1) XOR all the numbers the result is the number
 * .occurs odd number of times.
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * 
 * *********************************************************/
int FindOddNumbers(int A[], int n)
{
   int returnInt = 0;
   for(int i=0;i<n;i++)
     returnInt ^= A[i];
   return returnInt;
}
/************************************************************
 * Que 4. Find a and b in given array A[] such that a + b = k.
 * 
 * Comment : Use hash table to reach solution in O(n)
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * 
 * *********************************************************/
void FindElementsSumK(int A[], int n, int k)
{
   map<int,int> hash;
   for(int i=0;i<n;i++)
   {
       int t = k - A[i];
       if(hash[t])
	 printf("%d + %d = %d\n",A[i],t,k);
       if(hash[A[i]] == 0)
	  hash[A[i]] = 1;
   }
}
/************************************************************
 * Que 5. Find a and b in given array A[] such that a + b = k.
 * 
 * Comment : Use hash table to reach solution in O(n)
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(N)
 * 
 * *********************************************************/
void FindElementSquareSum(int A[], int n)
{
   for(int i=0;i<n;i++)
     A[i] = A[i]*A[i];
   
   for(int i=0;i<n;i++)
    FindElementsSumK(A,n,A[i]);
}
/************************************************************
 * Que 6. Find two numbers in given array whose sum is 
 * closest to zero (both -ve and +ve numbers)
 * 
 * Comments : 
 * 
 * Time Complexity : O(nlog(N))
 * Space Complexity: O(1)
 * 
 * *********************************************************/
int FindClosestToZero(int A[], int n)
{
   SortingArray sort;
   sort.init(A,n);
   sort.QuickSort(0,n-1);
   
   int min_positive = INT_MAX;
   int min_negative = INT_MIN;
   
   int low = 0,high = n-1;
   int temp = 0;
   
   while(low < high)
   {
      temp = A[low] + A[high];
      if(temp > 0)
      {
	 if(min_positive > temp)
	   min_positive = temp;
	 high--;
      }
      else if(temp < 0)
      {
	 if(min_negative < temp)
	   min_negative = temp;
	 low++;
      }
      else
      {
	 printf("%d + %d = 0\n",A[low],A[high]);
	 return 0;
      }
   }
   return abs(min_negative) > min_positive ? min_positive : min_negative;
}
/*************************************************************************
 * Que 7. Find three elements from given array such that a + b + c = k?
 * 
 * Comments : 1) Sort the elements.
 * 
 * Time  Complexity : O(nlog(N)) + O(N^2) = O(N^2)
 * Space Complexity : O(1)
 * 
 * **********************************************************************/
void Find3ElementsOfSumK(int A[], int n,int K)
{
    SortingArray sort;
    sort.init(A,n);
    sort.QuickSort(0,n-1);
    sort.PrintArray();
    
    for(int i=0;i<n;i++)
    {
      for(int k=i+1,j=n-1;k<j;)
      {
	int temp = A[i] + A[k] + A[j];
	if(temp == K)
	{
	  printf("%d + %d + %d = %d\n",A[i],A[j],A[k],K);
	  return;
	}
	else if(temp > k)
	  j--;
	else
	  k++;
      }
    }
}
/*********************************************************************************************
 * Que 8. array A[] of n distinct integers. Suppose A has the following property, there
 * exists an index 1<= k <= n such that A[1],...A[k] is an increasing sequence and A[k+1]
 * ...A[n] is a decreasing sequence. Design and analyze an efficient algorithm for finding k.
 * 
 * Comment  : 	1) Can be used modified Binary search
 * 
 * Time  Complexity  : O(N) 
 * Space Complexity  : O(1)
 * 
 * ******************************************************************************************/
int FindMaxElementInMonotonicArray(int A[], int n)
{
    int mid, low = 0,high = n-1;
    while(low <= high)
    {
		if(low == high)
			return low;
		if(high - low == 1)
		{
			return A[high] > A[low] ? high : low;
		}
	
		/* Elements count more than 2 */
		mid = low + (high - low)/2; //To avoid overflow
		if(A[mid-1] < A[mid] && A[mid] > A[mid+1])
			return mid;
		if(A[mid-1] < A[mid] && A[mid] < A[mid+1])
			low = mid + 1;
		else if(A[mid-1] > A[mid] && A[mid] > A[mid + 1])
			high = mid - 1;
		else if(A[mid-1] > A[mid] && A[mid] < A[mid+1])
			return mid-1;
		else
			return -1;
    }
    printf("ERROR !!!\n");
    return -1;
}
/**********************************************************************************************
 * Que 9. Given a sorted array of n integers that has been rotated unknown number of times
 * give an O(log(N)) algorithm to find an element in the array.
 * 
 * Comments  : 	1) Find the pivot element.
 * 		2) Break Array in two sub array
 * 		3) perform binary search for the data element.
 * 
 * Time Complexity  : O(log(N))
 * Space Complexity : O(N)  .. Recursion
 * 
 * ********************************************************************************************/
int FindElementInRoatedArray(int A[],int n, int data)
{
    int pivot = FindMaxElementInMonotonicArray(A,n);
    if(A[pivot] == data)
      return pivot;
    if(A[pivot] < data) //Element not present in Array
      return -1;
    int left = BinarySearchArray(A,0,pivot,data);
    if(left != -1)
      return left;
    return BinarySearchArray(A,pivot+1,n-1,data);
}
int BinarySearchArray(int A[], int low, int high, int data)
{
    if(low == high)
      return data == A[low] ? low : -1;
    if(low > high)
      return -1;
    int mid = low + (high - low) / 2;
    if(A[mid] == data)
      return mid;
    if(data > A[mid])
      return BinarySearchArray(A,mid+1,high,data);
    return BinarySearchArray(A,low,mid - 1,data);
}
/************************************************************************************************
 * Que 10. Given a sorted array A of n elements, possiby with duplicates, find the index of the 
 * first occurrence of a number in O(log(N))
 * 
 * Comemnts :
 * 
 * Time complexity : O(log(N))
 * Space complexity: O(1)
 * 
 * ************************************************************************************************/
int BinarySearchArrayFirstOccurance(int A[], int n,int data)
{
    int low = 0,high = n - 1, mid = -1;
    while(low <= high)
    {
        if(low == high)
			return A[low] == data ? low : -1;
		mid = low + (high - low)/2;
		if((mid == low && A[mid] == data) || (A[mid-1] < data && A[mid] == data ))
			return mid;
		else if( A[mid] < data )
			low = mid + 1;
		else
			high = mid - 1;
    }
    return -1;
}
/***************************************************************************************************
 * Que 11. Given a sorted array with repeated numbers find the last occurance of the given number
 * 
 * Comments :
 * 
 * Time  Complexity  : O(N)
 * Space Complexity  : O(1)
 * 
 * **************************************************************************************************/
int BinarySearchArrayLastOccurance(int A[], int n, int data)
{
    int low = 0,high = n-1,mid = -1;
    while(low <= high)
    {
       mid = low + (high - low) / 2;
		if(A[mid] == data && mid == high || A[mid] == data && A[mid + 1] > data)
			return mid;
	   if(data < A[mid])
		   high = mid - 1;
       else 
		   low = mid + 1;
    }
}
/*****************************************************************************************************
 * Que 12. Find the number of occurance of a given element. 
 * 
 * Comemnts : Use solution from Que 10 and 11.
 * 
 * Time Complexity : O(log(n) + log(n)) = O(log(N))
 * Space Complexity: O(1)
 * 
 * ****************************************************************************************************/
int FindOccurences(int A[], int n, int data)
{
    int low = BinarySearchArrayFirstOccurance(A,n,data);
    int high = BinarySearchArrayLastOccurance(A,n,data);
    if(low != -1)
      return high - low + 1;
    return -1;
}
/*****************************************************************************************************
 * Que 13. Seperate Odd and even numbers from a given array.
 * 
 * Comments :
 * 
 * Time Complexity : O(N)
 * Space Complexity: O(1)
 * 
 * **************************************************************************************************/
void SeperateOddEven(int A[], int n)
{
    int low = 0;
    int high = n-1;
    while(low < high)
    {
       while(A[low] % 2 == 0)
	 low++;
       
       while(A[high]%2 == 1)
	 high--;
       
       if(low < high)
       {
	    int temp = A[low];
	    A[low] = A[high];
	    A[high] = temp;
       }
    }
}






































