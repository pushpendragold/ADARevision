#ifndef _H_SEARCHING_H_
#define _H_SEARCHING_H_

//Que 1. check if there are any repeated numbers in given array.
bool CheckDuplicatesNumbers(int A[],int n);

//Que 2. Given an array of n numbers, give an algorithm for finding the first element in the
//array which is repeated. For example, in the array, A = {3,2,1,2,2,3} the first repeated 
//number is 3(not 2). This means we are required to return the first element among the 
//repeated numbers.
int FindFirstRepeatedNumber(int A[],int n);

//Que 3. Find the number occurs odd number of times in given array.
//all other numbers occurs even number of times.
int FindOddNumbers(int A[],int n);

//Que 4. Find a and b in given array A[] such that a + b = k.
void FindElementsSumK(int A[],int n,int k);

//Que 5. Find a and b such that A[a]^2 + A[b]^2 = A[k]^2
void FindElementSquareSum(int A[],int n);

//Que 6. Find two numbers in given array whose sum is closest to zero (both -ve and +ve numbers)
int FindClosestToZero(int A[],int n);

//Que 7. Find three elements from given array such that a + b + c = k?
void Find3ElementsOfSumK(int A[],int n,int k);

//Que 8. array A[] of n distinct integers. Suppose A has the following property, there
//exists an index 1<= k <= n such that A[1],...A[k] is an increasing sequence and A[k+1]
//...A[n] is a decreasing sequence. Design and analyze an efficient algorithm for finding k.
int FindMaxElementInMonotonicArray(int A[],int n);

//Que 9. Given a sorted array of n integers that has been rotated unknown number of times
//give an O(log(N)) algorithm to find an element in the array.
int BinarySearchArray(int A[],int low,int high,int data);
int FindElementInRoatedArray(int A[],int n,int data);


//Que 10. Given a sorted array A of n elements, possiby with duplicates, find the index of the first 
//occurrence of a number in O(log(N))
int BinarySearchArrayFirstOccurance(int A[],int n,int data);

//Que 11. Given a sorted array with repeated numbers find the last occurance of the given number.
int BinarySearchArrayLastOccurance(int A[],int n,int data);

//Que 12. Find the number of occurance of a given element. 
int FindOccurences(int A[],int n,int data);

//Que 13. Seperate Odd and even numbers from a given array.
void SeperateOddEven(int A[],int n);

#endif