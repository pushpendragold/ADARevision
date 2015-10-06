#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

#include "23QuestionEOP.h"
#include "tools.h"
#include "BigInt.h" 

using namespace std;

/* Chapter .6 (Array and Strings) */

/**********************************************************************************
 * Que 1. Write a function that takes an array A and an index i into A,
 * and rearranges the elements such that all elements less than A[i] appear
 * first, followed by elements equal to A[i], followed by elements greater
 * than A[i]. Algo should have O(1) space complexity and O(|A|) time complexity.
 * 
 * Comments : Known as Dutch Flag Partitioning
 * 
 * Time Complexity : O(n)
 * Space Complexity: O(1)
 * 
 * *******************************************************************************/
void RearrangeArray_Dutch_Flag_Partitioning(int A[], int n, int index)
{
    int pivot = A[index];
    int low   = 0; 	//smaller elements index
    int equal = 0; 	//pivot elements index
    int high  = n - 1;  //larger elements index
    
    while(equal <= high)
    {
        //A[equal] is element under investigation
        if(A[equal] < pivot)
	{
	   //Move element to lower section
	   SwapIntergers(A[low++],A[equal++]);
	}
	else if(A[equal] == pivot)
	{
	  //Equal elements just increment the pointers
	  equal++;
	}
	else
	{
	  //Large elements
	  SwapIntergers(A[equal],A[high--]);
	}
    }
}
/******************************************************************************
 * Que 2. Design a deterministic scheme by which reads and writes to an 
 * uninitialized array can be made in O(1) time. you may use O(n) additional
 * storage reads to uninitialized entry should return false.
 * ****************************************************************************/

//All code in header itself

/******************************************************************************
 * Que 3. Max difference problem 
 * Design an algorithm that takes a sequence of n three-dimensional 
 * coordinates to be traversed and returns the minimum battery capacity
 * needed to complete the journey. The robot begins with a fully 
 * charged battery.
 * 
 * Time Complexity : O(N)
 * Comments : Array only contains h of the co-ordinates given
 * 
 * ***************************************************************************/
int Find_Battery_Capacity(int A[],int n)
{
     if(n <= 0) return 0;
     
     int min_height = A[0];
     int capacity   = 0;
     
     for(int i=1;i<n;i++)
     {
         capacity = MAXINT(A[i] - min_height,capacity);
         min_height = minInteger(A[i],min_height);
     }
     return capacity;
}
/********************************************************************************
 * Que 4. For each of the following, A is an integer array of length n.
 *	1) Compute the maximum value of (A[j0] - A[i0]) + (A[j1] - A[i1])
 *		subject to i0<j0<i1<j1
 *	2) Compute the maximum value of sum of ((A[Jj] - A[Ii])) where,
 *		i0 < j0 < i1 < j1 < ... in < jn
 *	3) Repeat problem 2 where k can be chosen to be any value from 0
 *		to n/2.
 * 
 * Comments : another way of asking Stock market problem.
 * Remark   : Exhaustic search for option(3)
 *******************************************************************************/
int Find_Max_Sum(int A[], int n, int low, int high)
{
     if(high == n-1)
		 return A[high] - A[low];
      
      if(low == high)
      {
		  return Find_Max_Sum(A,n,low,low+1);
      }
      else if(A[high] > A[low])
      {
		int purchased = A[high] - A[low] + Find_Max_Sum(A,n,high+1,high+1);
		int notPurchased = Find_Max_Sum(A,n,low,high+1);
		if(purchased > notPurchased)
		{
		  printf("%d %d :: %d %d\n",low,high,A[low],A[high]);
		  return purchased;
		}
		return notPurchased;
      }
      return Find_Max_Sum(A,n,low+1,low+1);
}
/********************************************************************************
 * Que 5. Subset Summing to 0 mod n
 * Design an efiicient algorithm for the 0 mod n-sum subset problem.
 * 
 * Algo Type : BackTracking (Exhaustic search)
 * 
 * Remark   : Exhaustic search for option(3)
 *******************************************************************************/
int Subset_Sum_0_mod_n(int A[], int n, int k)
{
    int solutions[n];
    return Subset_Sum_0_mod_n(A,n,0,k,solutions,0,0);
}
int Subset_Sum_0_mod_n(int A[], int n,int current_index, int k, int solutions[], int current_sum, int sIndex)
{
    if(current_index >= n || current_index >= n)  return 0;
  
    int total_found = 0;
    if(current_sum % k == 0 && current_sum != 0)
    {
       for(int i=0;i<sIndex;i++)
	 printf("%d ",solutions[i]);
       printf("\tSum : %d \n",current_sum);
       
       total_found++;
    }
    
    for(int i=current_index;i<n;i++)
    {
       solutions[sIndex] = A[i];
       total_found += Subset_Sum_0_mod_n(A,n,i+1,k,solutions,current_sum + A[i],sIndex+1);
    }
    
    return total_found;
}
/********************************************************************************
 * Que 6. Design and implement an algorithm that takes as input an array A of n 
 * elements, and returns the begnning and ending indices of a largest increasing 
 * subarray of A.
 * 
 *  Algo Type : BackTracking O(N)
 * 
 *******************************************************************************/
int Find_Max_increasing_Sub_Array(int A[], int n,int low,int high)
{
   if(low == high) return 1;
   
   int tLow = CheckArrayLeftToRight(A,low,high);
   if(tLow == low)
      return high - low + 1;
   else
   {
       int leftCount = Find_Max_increasing_Sub_Array(A,n,tLow,high);
       int tHigh = CheckArrayRightToLeft(A,low,high);
       int rightCount = Find_Max_increasing_Sub_Array(A,n,low,tHigh);
       return rightCount > leftCount ? rightCount : leftCount;
   }
}
int CheckArrayLeftToRight(int A[],int low,int high)
{
    if(low == high) return low;
    for(int i=low;i<high;i++)
    {
        if(A[i] > A[i+1])
	  return i+1;
    }
    return low;
}
int CheckArrayRightToLeft(int A[],int low,int high)
{
    if(low == high) return low;
    for(int i=high;i>low;i--)
    {
	if(A[i] < A[i-1])
	  return i-1; 
    }
    return high;
}
/********************************************************************************
 * Que 7. Design and implement an algorithm that takes as input an array A of n 
 * elements, and returns the begnning and ending indices of a largest increasing 
 * subarray of A.
 * 
 *  Algo Type : Adhoc
 * 
 *******************************************************************************/
void ProductBigInt()
{
    BigInt A("-25");
    BigInt B("25");

    BigInt C("1");
    C = A * B;
    C.PrintNumber();
}
/********************************************************************************
 * Que 8. Given an permutation, return the vector corresponding to next 
 * permutation under lexicographic ordering. 
 * 
 *  Algo Type : Adhoc
 * 
 *******************************************************************************/
vector<int> Find_next_permutation(vector<int> p)
{
    int k = p.size() - 2;

    while(k >= 0 && p[k] >= p[k + 1])
     k--;

    if(k == -1)
    {
        printf("Given permutation is the last permutation\n");
        return p;
    }

    int l;
    for(int i = k + 1; i < p.size(); i++)
    {
        if(p[i] > p[k])
        {
            l = i;
        }
        else break;
    }

    swap(p[l],p[k]);

    //produce the lexicographically minimal permutation
    reverse(p.begin() + k + 1, p.end());
    return p;
}
/********************************************************************************
 * Que 9. Suppose there is a circle. There are n petrol pumps on that circle.
 * You are given two sets of data.
 * 1. The amount of petrol that petrol pump will give.
 * 2. Distance from that petrol pump to the next petrol pump.
 * Calculate the first point from where a truck will be able to complete the circle
 * (The truck will stop at each petrol pump and it has infinite capacity). Expected
 * time complexity is O(n). Assume for 1 litre petrol, the truck can go 1 unit of distance.
 * For example, let there be 4 petrol pumps with amount of petrol and distance to 
 * next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}. The first point 
 * from where truck can make a circular tour is 2nd petrol pump. Output should be 
 * start = 1 (index of 2nd petrol pump).
 * 
 *  Algo Type : Adhoc
 * 
 *******************************************************************************/
int GetStartingPetrolPump(int A[],int n)
{
    int B[n];
    B[0] = A[0];
    for(int i=1; i<n; i++)
    {
        if(B[i-1] + A[i] > A[i])
            B[i] = B[i - 1] + A[i];
        else
            B[i] = A[i];
    }
    
    for(int i = n - 1; i >= 1; i--)
    {
        if(B[i] >= 0 && B[i-1] < 0)
            return i + 1;
    }
    return -1;
}
























