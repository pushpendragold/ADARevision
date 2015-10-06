/* Question from book Element of Programming interviews */

#ifndef _H_QUESTIONS_H_EOP_H_
#define _H_QUESTIONS_H_EOP_H_

#include <vector>
using namespace std;

/* Chapter .6 (Arrays and Strings) */

//Que 1. Write a function that takes an array A and an index i into A,
//and rearranges the elements such that all elements less than A[i] appear
//first, followed by elements equal to A[i], followed by elements greater
//than A[i]. Algo should have O(1) space complexity and O(|A|) time complexity.
void RearrangeArray_Dutch_Flag_Partitioning(int A[],int n,int index);

//Que 2. Design a deterministic scheme by which reads and writes to an 
//uninitialized array can be made in O(1) time. you may use O(n) additional
//storage reads to uninitialized entry should return false.
template <typename ValueType, size_t n> 
class Array{

private : 
    ValueType A[n];
    int P[n],S[n], t;
  
  const bool isValid(const size_t &i) const {
    return (0 <= P[i] && P[i] <= t && S[P[i]] == i);
  };

public : 
    Array(void) : t(0) {};
    const bool Read(const size_t &i, ValueType &v) const
    {
      if(isValid(i))
      {
	  v = A[i];
	  return true;
      }
      return false;
    }
    const void Write(const size_t &i,const ValueType &v)
    {
        if(!isValid(i))
	{
	    S[t] = i;
	    P[i] = t++;
	}
	A[i] = v;
    }
};

//Que 3. Max difference problem 
//Design an algorithm that takes a sequence of n three-dimensional 
//coordinates to be traversed and returns the minimum battery capacity
//needed to complete the journey. The robot begins with a fully 
//charged battery.
int Find_Battery_Capacity(int A[],int n);

//Que 4. For each of the following, A is an integer array of length n.
//	1) Compute the maximum value of (A[j0] - A[i0]) + (A[j1] - A[i1])
//		subject to i0<j0<i1<j1
//	2) Compute the maximum value of sum of ((A[Jj] - A[Ii])) where,
//		i0 < j0 < i1 < j1 < ... in < jn
//	3) Repeat problem 2 where k can be chosen to be any value from 0
//		to n/2.
// Another way of asking Stock market multiple purchase problem
int Find_Max_Sum(int A[],int n,int low,int high);


//Que 5. Subset Summing to 0 mod n
// Design an efiicient algorithm for the 0 mod n-sum subset problem.
int Subset_Sum_0_mod_n(int A[],int n,int k);
int Subset_Sum_0_mod_n(int A[], int n,int current_index, int k, int solutions[], int current_sum, int sIndex);


//Que 6. Design and implement an algorithm that takes as input an array A of n elements,
//and returns the begnning and ending indices of a largest increasing subarray of A.
int Find_Max_increasing_Sub_Array(int A[], int n,int low,int high);
int CheckArrayLeftToRight(int A[],int low,int high);
int CheckArrayRightToLeft(int A[],int low,int high);


//Que 7. Write a program to compute given string multiplications and return answer array
void ProductBigInt();

//Que 8. Find next permuatation for a given permutation in lexicographic order.
vector<int> Find_next_permutation(vector<int> p);

//Que 9. Find the starting petrol punm for given conditions.
int GetStartingPetrolPump(int A[],int n);

// Que 10 . Rearrange arr[i] such that arr[arr[i]] given elements are from 0 to n - 1. 
void Que10_RearrangeArray(int arr[],int n);

// Que 11. Stock market problem
void stockBuySell( int A[],int n );

#endif