#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

/* Chapters */
#include "02Recursion.h"
#include "03LinkedLists.h"
#include "04Stacks.h"
#include "05Queues.h"
#include "06Trees.h"
#include "07Heap.h"
#include "08DisjointSets.h"
#include "09GraphAlgorithms.h"
#include "10Sorting.h"
#include "11Searching.h"
#include "12Selection.h"
#include "14Hashing.h"
#include "15StringAlgo.h"
#include "17Greedy.h"
#include "18SegmentTree.h"


#include "19DynamicProgramming.h"

/* Questions */
#include "22Questions.h"

/* Questions from Element of programming Interview */
#include "23QuestionEOP.h"

/* Utility Functions */
#include "tools.h"
#include "BigInt.h"

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define NL printf("\n")

using namespace std;

/* Chapters */
void Chapter_23(int Que); // Element of programming Interview Book

void Chapter_17(int Que); // Segment Tree
void Chapter_16(int Que); // Hashing
void Chapter_15(int Que); // String Algorithms
void Chapter_14(int Que); // Graph Algorithms
void Chapter_13(int Que); // Dynamic Programming
void Chapter_12(int Que); // Recurssion (Back Tracking)
void Chapter_11(int Que); // Greedy Algorithm
void Chapter_10(int Que); // Selection Algorithm
void Chapter_09(int Que); // Searching
void Chapter_08(int Que); // Sorting
void Chapter_07(int Que); // Priority Queue & Heaps
void Chapter_06(int Que); // Trees
void Chapter_05(int Que); // Queue
void Chapter_04(int Que); // Stack
void Chapter_03(int Que); // Linked List
void Chapter_02(int Que); // Recursion and Backtracking

//chapter count
int chapter = 17;
int Que = 1;

int main()
{      
	   if(chapter == 17) Chapter_17(Que);
  else if(chapter == 16) Chapter_16(Que);
  else if(chapter == 15) Chapter_15(Que);
  else if(chapter == 14) Chapter_14(Que);
  else if(chapter == 13) Chapter_13(Que);
  else if(chapter == 12) Chapter_12(Que);
  else if(chapter == 11) Chapter_11(Que);
  else if(chapter == 10) Chapter_10(Que);
  else if(chapter == 9)  Chapter_09(Que);
  else if(chapter == 8)  Chapter_08(Que);
  else if(chapter == 7)  Chapter_07(Que);
  else if(chapter == 6)  Chapter_06(Que);
  else if(chapter == 5)  Chapter_05(Que);
  else if(chapter == 4)  Chapter_04(Que);
  else if(chapter == 3)  Chapter_03(Que);
  else if(chapter == 2)  Chapter_02(Que);
  else if(chapter == 23) Chapter_23(Que);

  return 0;
}

// Chapter : 23 Questions for Programming Interview Book
void Chapter_23(int Que)
{
	 if(Que == 11) 
     {
		 // Stock market buy sell problem
		 int A[] = { 40, 180, 260, 310, 100, 535, 695 };
		 stockBuySell(A,sizeof(A)/sizeof(A[0]));
	 }
	 else if(Que == 10) 
	 {
		 int arr[] = {3,0,1,2};
		 Que10_RearrangeArray(arr,4);
	 }
     else if(Que == 9)
     {
         //Find the starting petrol pump
         int A[] = {-2,1,4,-1};
         int n = ARRAY_SIZE(A);
         printf("starting petrol pump : %d\n",GetStartingPetrolPump(A,n));
         
     }
     if(Que == 8)
     {
         //Que 8. Find the next permutation for a given permutation.
         vector<int> A;
         A.push_back(1);
         A.push_back(2);
         A.push_back(3);
         A.push_back(5);
         A.push_back(4);
         vector<int> B = Find_next_permutation(A);
         for(int i=0; i < B.size(); i++)
         {
             printf("%d ",B[i]);
         }
         cout<<endl;
         
     }
     else if(Que == 7)
     {
         //Que 7. Implement BigInt class and calculate factorial of large numbers
         BigInt A("1");
         BigInt B("200");
         BigInt C("1");

         for(; A < B ;)
         {
             ++A;
             C = C * A;
             A.PrintNumber();
         }
         C.PrintNumber();
     }
     else if(Que == 6)
     { 
        	//Que 6. Design and implement an algorithm that takes as input an array A of n elements,
        	//and returns the begnning and ending indices of a largest increasing subarray of A.
            int A[] = {17,16,18,1,2,3,4,5,50,40};
        	int n = ARRAY_SIZE(A);
        	int low = 0;
        	int high = 0;
        	int count = Find_Max_increasing_Sub_Array(A,n,0,n-1);
        	printf("Max increasing subarray count : %d\n",count);
     }
     else if(Que == 5)
     {
            //Que 5. Subset Summing to 0 mod n
            // Design an efiicient algorithm for the 0 mod n-sum subset problem.
            
           int A[] = {1,2,3,4,5,6,7,8,9,10};
           int n = ARRAY_SIZE(A);
           printf("Total number of sets : %d\n",Subset_Sum_0_mod_n(A,n,10));
     }
     else if(Que == 4)
     {
            //Que 4. For each of the following, A is an integer array of length n.
        	//	1) Compute the maximum value of (A[j0] - A[i0]) + (A[j1] - A[i1])
        	//		subject to i0<j0<i1<j1
        	//	2) Compute the maximum value of sum of ((A[Jj] - A[Ii])) where,
        	//		i0 < j0 < i1 < j1 < ... in < jn
        	//	3) Repeat problem 2 where k can be chosen to be any value from 0
        	//		to n/2.
        	// Another way of asking Stock market multiple purchase problem
               
            int A[] = {5,4,6,2,7,1,9};
        	int n = ARRAY_SIZE(A);
        	PrintArray(A,n);
        	printf("Max diff : %d\n",Find_Max_Sum(A,n,0,0));
     }
     else if(Que == 3)
     {
        	//Que 3. Max difference problem 
        	//Design an algorithm that takes a sequence of n three-dimensional 
        	//coordinates to be traversed and returns the minimum battery capacity
        	//needed to complete the journey. The robot begins with a fully 
        	//charged battery.  
                
            int A[] = {5,4,6,2,7,1,9};
        	int n = ARRAY_SIZE(A);
        	PrintArray(A,n);
        	printf("Max diff : %d\n",Find_Battery_Capacity(A,n));
     }
     else if(Que == 2)
     {
            // Que 2. Design a deterministic scheme by which reads and writes to an 
        	// uninitialized array can be made in O(1) time. you may use O(n) additional
        	// storage reads to uninitialized entry should return false.
    
            int read;
            Array<int,10> array;
        	array.Read(3,read) ? printf("Readable : %d\n",read) : printf("Not readable\n");
        	array.Write(3,13);
        	array.Read(3,read) ? printf("Readable : %d\n",read) : printf("Not readable\n");
     }
     else if(Que == 1)
     {
        	//Que 1. Write a function that takes an array A and an index i into A,
        	//and rearranges the elements such that all elements less than A[i] appear
        	//first, followed by elements equal to A[i], followed by elements greater
        	//than A[i]. Algo should have O(1) space complexity and O(|A|) time complexity.
                
            int A[] = {5,1,3,8,2,33,2,1};
            int n   =  8;
            PrintArray(A,n);
            RearrangeArray_Dutch_Flag_Partitioning(A,8,0);
            PrintArray(A,n);
     }
}

// Chapter : 17 (Segment Tree)
void Chapter_17(int Que)
{
	if(Que == 1) 
	{
		// Find the minimum number from given range
		int A[] = { 2,3,1,2,3,2,3,3 };
		SegmentTree s(A,8);
		printf("%d\n",s.RMQ(7,0,2));
	}
}

// Chapter : 15 ( String Algorithms )
void Chapter_15(int Que)
{
	if( Que == 1 ) 
	{
		 // KPM algorithm
		 string txt("AABAACAADAABAAABAA");
		 string pat("AA");
		 KMPSearch(pat, txt);
	}
	else if( Que == 2 ) 
	{
		// Tries Search Algorithm
		// Input keys (use only 'a' through 'z' and lower case)
#if 0
		char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
		trie_t trie;
 
		char output[][32] = {"Not present in trie", "Present in trie"};
 
		initialize(&trie);
 
		// Construct trie
		for(int i = 0; i < ARRAY_SIZE(keys); i++)
			insert(&trie, keys[i]);
 
		// Search for different keys
		printf("%s --- %s\n", "the", output[search(&trie, "the")] );
		printf("%s --- %s\n", "these", output[search(&trie, "these")] );
		printf("%s --- %s\n", "their", output[search(&trie, "their")] );
		printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")] );
#endif
	}
	else if( Que == 3 ) 
	{
		// Ternary Search Tree
#if 0
		struct Node *root = NULL;
 
		insert(&root, "cat");
		insert(&root, "cats");
		insert(&root, "up");
		insert(&root, "bug");
		insert(&root, "dog");
 
		printf("Following is traversal of ternary search tree\n");
		traverseTST(root);
 
		printf("\nFollowing are search results for cats, bu and cat respectively\n");
		searchTST(root, "cats")? printf("Found\n"): printf("Not Found\n");
		searchTST(root, "bu")?   printf("Found\n"): printf("Not Found\n");
		searchTST(root, "cat")?  printf("Found\n"): printf("Not Found\n");
#endif 
	}
	else if( Que == 4 ) 
	{
		// Que 4. Find pattern in a given string with wild card.
		char A[] = "thisiswar";
		char p[] = "*war";

		printf(" %s\n",FindPatternWithWildCard(p,A) ? "found" : "Not Found");
	}
	else if(Que == 5) 
	{
		char A[] = "bat";
		Perm(A,3,0);
	}
}

// Chapter : 13 ( Dynamic Programming )
void Chapter_13(int Que)
{
	   if(Que == 10) 
	   {
			// find number of ways to reach bottom most point
		   printf("%d\n",FindNumberOfWays(8,8));
	   }
	   else if(Que == 9) 
	   {
		   // Catalan number : number of binary trees possible with n nodes
		   printf("%d\n",CatalanNumber(2));
		   printf("%d\n",CatalanNumber(3));
		   printf("%d\n",CatalanNumber(4));
		   
	   }
	   else if(Que == 8) 
	   {
		   int A[] = { -2, 11, -4, 13, -5, 2};
		   printf("Max Sum : %d\n",MaxContinuousSubSequenceSum(A,6));
	   }
	   else if(Que == 7) 
	   {
		    // Longest common subsequence
		    char X[] = "AGGTAB";
		    char Y[] = "GXTXAYB";
  
			int m = strlen(X);
			int n = strlen(Y);
  
			printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );
	   }
	   else if(Que == 6)
      {
    	 //Coin Change problem
    	 int change[] = {1,5,10,20,25};
    	 int n  = 100;
    	 printf("Number of Change : %d\n",FindMinChange(change,5,n));
    	 printf("Number of Change : %d\n",FindMinChange_DP(change,5,n));
      }
      else if(Que == 5)
      {
    	 // Check if given string is interleaved between two other strings
    	 char A[] = "ABC";
    	 char B[] = "CEF";
    	 char C[] = "ACEBCF";
    	 CheckIfInterleaving_DP(A,B,C) ? 
    	 printf("%s %s %s are interleaved\n",A,B,C) :
    	 printf("%s %s %s are not interleaved\n",A,B,C) ;

      }
      else if(Que == 4)
      {
    	 //Longest AP length in given set
    	 int set1[] = {1, 7, 10, 13, 14, 19};
    	 int n1 = sizeof(set1)/sizeof(set1[0]);
    	 cout <<   LongestLengthAP_DP(set1, n1) << endl;
          
    	 int set2[] = {1, 7, 10, 15, 27, 29};
    	 int n2 = sizeof(set2)/sizeof(set2[0]);
    	 cout <<   LongestLengthAP_DP(set2, n2) << endl;
          
    	 int set3[] = {2, 4, 6, 8, 10};
    	 int n3 = sizeof(set3)/sizeof(set3[0]);
    	 cout <<   LongestLengthAP_DP(set3, n3) << endl;
      
      }
      else if(Que == 3)
      {
    	//Cutting Rope problem
    	printf("for %d : %d\n",10,RopeCuttingProblem_recursion(10,1));
    	//Cutting Rope problem
    	printf("for %d : %d\n",10,RopeCuttingProblem_DP(10));
      }
      else if(Que == 2)
      {
          //Stock problem to maximize profit
          int A[] = {10,20,5,75,65,80};

          printf("%d\n",MaxProfit(A,6,0,0));
      }
      else if(Que == 1)
      {
        //0-1 Knapsack problem
        int value[]  = {60,100,120};
        int weight[] = {10, 20, 30};
        int WeightAlloweed = 50;
        
        printf("%d\n",KnapsackDP(WeightAlloweed,weight,value,3));
      }
}
void Chapter_12(int Que)
{
	if(Que == 6)
     {
        //Que 6. Largest sum continous sub array.
        int A[] = {5,-1,-2,3,5,-1,-2,-3};
        int n = ARRAY_SIZE(A);
        printf("Maximum subarray : %d\n",FindContinousLargestSum(A,n));
     }
     else if(Que == 5)
     {
         //Find all possible subset of given set.
         int A[] = {1,2,3,4,5};
         printf("Find all sets : %d\n",FindSubSet(A,3));
     }
     else if(Que == 4)
     {	
       //Print B such that B is product of all elemnts except A[i]th element.
       int A[] = {1,2,3,4,5};
       PrintBFromA(A,5);
     }
     if(Que == 3)
     {
		 //Find all the sets with the sum K.
        int n = 10;
        printf("Total number of sets with sum (%d) is %d\n",n,FindAllSet(n));
     }
     else if(Que == 2)
     {
        findFirstNonRepeating();
	
     }
     else if(Que == 1)
     {
		 // Permutaion
        char A[] = "ABC";
		print_all_perm4(A);
     }
}

void Chapter_11(int Que)
{
	if(Que == 1)
     {
		//Time scheduling problem
        TimeSchedule();
     }
}
void Chapter_10(int Que)
{
	 if(Que == 3)
     {
		 //Que 3. Given two arrays each containing two sorted elements. Give an O(log(N))
		 //time algorithm to find the median of all 2n elements.
        //int A[] = {1,3,5,7,9,11,13};
		//int B[] = {2,4,6,8,10,12,14};
		
		int A[] = {1,2,3,4,5,6,7,20};
		int B[] = {8,9,10,11,12,13,14};
        int val = FindMediansTwoArrays(A,0,7,B,0,6);
		printf("%d\n",val);
     }
     else if(Que == 2)
     {
		 //Find kth smallest element
        int A[] = {5,10,15,20,11,8};
		int n = 6;
		PrintArray(A,n);
		printf("kth smallest element is %d\n",KthSmallestElement(A,n,3));
     }
     if(Que == 1)
     {
		 //Que 1. Find the smallest and largest key in the given array A[].
        int A[] = {1,3,4,5,5,5,5,5,5,5,5,7,10,14};
		int n = 14;
		FindLargestAndSmallest(A,n);
     }
}
void Chapter_09(int Que)
{
      if(Que == 13)
      {
		  //Que 13. Seperate Odd and even numbers from a given array.
		  int A[] = {1,3,4,5,5,5,5,5,5,5,5,7,10,14};
		  int n = 14;
		  PrintArray(A,n);
		  SeperateOddEven(A,n);
		  PrintArray(A,n);
      }
      else if(Que == 12)
      {
		  //Que 12. Find the number of occurance of a given element. 
		  int A[] = {1,3,4,5,5,5,5,5,5,5,5,7,10,14};
		  int n = 14;
		  int element = 5;
		  PrintArray(A,n);
		  int index = FindOccurences(A,n,element);
		  if(index != -1)
			  printf("Element found %d at %d\n",A[index],index);
		  else
			  printf("Element not found %d\n",element);
      }
      else if(Que == 11)
      {
		  //Que 11. Find the last occurence of the given data in array with repeacted numbers.
		  int A[] = {1,3,4,5,5,5,5,5,5,5,5,7,10,14};
		  int n = 14;
		  int element = 5;
		  PrintArray(A,n);
		  int index = BinarySearchArrayLastOccurance(A,n,element);
		  if(index != -1)
			  printf("Element found %d at %d\n",A[index],index);
		  else
			  printf("Element not found %d\n",element);
      }
      else if(Que == 10)
      {
		  //Que 10. Find the first occurence of the given data in array with repeacted numbers.
		  int A[] = {1,3,4,5,5,5,5,5,5,5,5,7,10,14};
		  int n = 14;
		  int element = 5;
		  PrintArray(A,n);
		  int index = BinarySearchArrayFirstOccurance(A,n,element);
		  if(index != -1)
			  printf("Element found %d at %d\n",A[index],index);
		  else
		  printf("Element not found %d\n",element);
      }
      else if(Que == 9)
      {
		  //Que 9. Given a sorted array of n integers that has been rotated unknown number of times
		  //give an O(log(N)) algorithm to find an element in the array.
		  int A[] = {15,16,19,20,25,1,3,4,5,7,10,14};
		  int n = 12;
		  int element = 4;
		  PrintArray(A,n);
		  int index = FindElementInRoatedArray(A,n,element);
		  if(index != -1)
			  printf("Element found %d at %d\n",A[index],index);
		  else
			  printf("Element not found %d\n",element);
      }
	  else if(Que == 8)
      {
		  //Que 8. array A[] of n distinct integers. Suppose A has the following property, there
		  //exists an index 1<= k <= n such that A[1],...A[k] is an increasing sequence and A[k+1]
		  //...A[n] is a decreasing sequence. Design and analyze an efficient algorithm for finding k.
		  int A[] = {5,10,15,20,11,8};
		  printf("Max element is : %d\n",A[FindMaxElementInMonotonicArray(A,6)]);
      }
      else if(Que == 7)
      {
		  //Que 7. Find three elements from given array such that a + b + c = k?
		  int A[] = {1,2,3,4,5,6,7,8,9,10};
		  Find3ElementsOfSumK(A,10,12);
      }
      else if(Que == 6)
      {
		  //Que 6. Find two numbers in given array whose sum is closest to zero (both -ve and +ve numbers)
		  int A[] = {-2,-1,4,2,5,6,7,8};
		  printf("Sum closest to zero : %d\n",FindClosestToZero(A,7));
      }
      else if(Que == 5)
      {
		  //Que 5. Find a and b such that A[a]^2 + A[b]^2 = A[k]^2
		  int A[] = {1,2,3,4,5,6,7,8,9,10};
		  FindElementSquareSum(A,10);
      }
      else if(Que == 4)
      {
			//Que 4. Find a and b in given array A[] such that a + b = k.
			int A[] = {1,2,3,4,5,6,7,8,9,10};
			FindElementsSumK(A,10,7);
      }
      else if(Que == 3)
      {
		  //Que 3. Find the number occurs odd number of times in given array.
		  int A[] = {1,2,3,21,5,3,21,2,1,3,5};
		  printf("Number occurs odd number of times : %d\n",FindOddNumbers(A,11));
      }
      else if(Que == 2)
      {
			//Que 2. Given an array of n numbers, give an algorithm for finding the first element in the
			//array which is repeated. For example, in the array, A = {3,2,1,2,2,3} the first repeated 
			//number is 3(not 2). This means we are required to return the first element among the 
			//repeated numbers.
			
			int A[] = {3,2,1,2,2,3};
			printf("First Repeated number is : %d\n",FindFirstRepeatedNumber(A,6));
      }
      else if(Que == 1)
      {
			//Que 1. check if there are any repeated numbers in given array.
			int A[] = {1,2,3,4,5,6,7,8,9,10};
			CheckDuplicatesNumbers(A,10) ? printf("Duplicates found\n") : printf("Duplicates not present\n");
      }
}
void Chapter_08(int Que)
{
	//Sorting Elements
	if(Que == 8)
    {
		 //Que 9. Given two Array A[] and B[] find element a from A[] and b from B[] such that a + b = K
		 int A[] = {1,2,3,4,5,6,7,8,9,10};
		 int B[] = {1,2,3,4,5,6,7,8,9,10};
		 FindPair(A,B,10,10,10) ? printf("Found\n") : printf("Not found\n");
     }
     else if(Que == 7)
     {
		  //Que 8. Given an array A[] of n numbers containing repeatition of some numbers. 
		  //Give an algorithm for checking whether there are repeated elements or not.
		  //Assume we are not allowed to use additional space.
		  int A[] = {5,9,1,4,3,8,10,2,6};
		  CheckDuplicates(A,9) ? printf("Duplicates found\n") : printf("No Duplicates\n");
     }
     else if(Que == 6)
     {
		 //Quick Sort
		 int A[] = {5,9,1,4,3,8,10,2,6};
		 int n   = 9;
		 
		 SortingArray sort;
		 sort.init(A,n);
		 sort.PrintArray();
		 sort.QuickSort(0,8);
		 sort.PrintArray();
      }
      else if(Que == 5)
      {
		 //Heap sort
		 int A[] = {5,9,1,4,3,8,10,2,6};
		 int n   = 9;
		 
		 SortingArray sort;
		 sort.init(A,n);
		 sort.PrintArray();
		 sort.HeapSort();
		 sort.PrintArray();
      }
      else if(Que == 4)
      {
		 //Merge Sort
		 int A[] = {5,9,1,4,3,8,10,2,6};
		 int n   = 9;
		 
		 SortingArray sort;
		 sort.init(A,n);
		 sort.PrintArray();
		 sort.MergeSort(0,8);
		 sort.PrintArray();
      }
      else if(Que == 3)
      {
		 //Insertion Sort
		 int A[] = {5,9,1,4,3,8,10,2,6};
		 int n   = 9;
		 
		 SortingArray sort;
		 sort.init(A,n);
		 sort.PrintArray();
		 sort.InsertionSort();
		 sort.PrintArray();
      }
      else if(Que == 2)
      {
		 //Selection Sort
		 int A[] = {5,9,1,4,3,8,10,2,6};
		 int n   = 9;
		 
		 SortingArray sort;
		 sort.init(A,n);
		 sort.PrintArray();
		 sort.SelectionSort();
		 sort.PrintArray();
      }
      else if(Que == 1)
      {
		 //Bubble Sort
		 int A[] = {5,8,1,4,3,8,10,2,6};
		 int n   = 9;
		 
		 SortingArray sort;
		 sort.init(A,n);
		 sort.PrintArray();
		 sort.BubbleSortImproved();
		 sort.PrintArray();
      }
}

void Chapter_07(int Que)
{
    if(Que == 5)
    {
		int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
		   
		PriorityQueue minHeap(20,MIN_HEAP);
		PriorityQueue maxHeap(20,MAX_HEAP);
		
		int size = ARRAY_SIZE(A);
		int median = 0;
		
		for(int i=0;i<size;i++)
			printf("Median : %d\n",FindMedian(A[i],median,minHeap,maxHeap));
    }
    else if(Que == 4)
    {
       //Que 6 . Implement min-max heap
       MinMaxQueue queue;
       queue.InIt();
       queue.Insert(3);
       queue.Insert(5);
       queue.Insert(7);
       queue.Insert(9);
       queue.Insert(11);
       queue.Insert(1);
       
       printf("Max Element %d\n",queue.FindMax());
       printf("Min Element %d\n",queue.FindMin());
       printf("Delete Max %d\n",queue.DeleteMax());
       printf("Max Element %d\n",queue.FindMax());
       printf("Delete Min %d\n",queue.DeleteMin());
       printf("Min Element %d\n",queue.FindMin());
       
    }
    else if(Que == 3)
    {
      int A[] = {4,6,2,3,8,9,1};
      int B[] = {3,6,1,4,7,9,3};
      FindLargestPairs(A,B,7);
    }
    else if(Que == 2)
    {
      //Heap Sort
      PriorityQueue queue(20,MAX_HEAP);
      int A[] = {5,2,3,7,8,1};
      queue.HeapSort(A,6);
      PrintArray(A,6);
    }
    else if(Que == 1)
    {
       //Priority Queue
       PriorityQueue pQueue(20,MAX_HEAP);
       int A[] = {5,2,3,7,8,1};
       pQueue.Heapify(A,6);
       for(int i=0;i<6;i++)
	 printf("%d\n",pQueue.DeleteTop());
       
    }
}
void Chapter_06(int Que)
{
    /* AVL Tree */
    AVLTree avl;
    avl.InsertNode(10);
    avl.InsertNode(5);
    avl.InsertNode(15);
    avl.InsertNode(7);
    avl.InsertNode(2);
    avl.InsertNode(17);
    avl.InsertNode(12);
    
    if(Que == 46)
    {
      //Height of the avl tree
      avl.LevelOrderTraversal(avl.GetRoot());NL;
      printf("%d\n",avl.HeightOfTree());
    }
    
    /* Binary Search Tree */
    BinarySearchTree BST;
    BST.InsertNode(10);
    BST.InsertNode(5);
    BST.InsertNode(15);
    BST.InsertNode(7);
    BST.InsertNode(2);
    BST.InsertNode(17);
    BST.InsertNode(12);
    
    
    if(Que == 49)
    {
       //Convery Binary search tree in DLL
       BST.SetRoot(BST.ConvertTreeToDLL(BST.GetRoot()));
       BST.PrintDLL(BST.GetRoot());
    }
    if(Que == 48)
    {
      //Print Right view of the BST
      int max_level = -1;
      BST.PrintRightView(BST.GetRoot(),0,max_level);NL;
    }
    else if(Que == 47)
    {
      // Print left view of the BST1
      int max_level = -1;
      BST.PrintLeftView(BST.GetRoot(),0,max_level);NL;
    }
    else if(Que == 45)
    {
	//Compair two binary search tree if they have same set of elemnts
        BinarySearchTree BST1;
	BST1.InsertNode(10);
	BST1.InsertNode(5);
	BST1.InsertNode(15);
	BST1.InsertNode(7);
	BST1.InsertNode(2);
	BST1.InsertNode(17);
	BST1.InsertNode(12);
	BinarySearchTree::CompairBinaryTrees(BST,BST1) ? printf("Same Element sets\n") : printf("Not Same elements set\n");
    }
    else if(Que == 44)
    {
      //Print all element in given range
      BST.InOrderTraversal(BST.GetRoot());NL;
      BST.PrintInRange(BST.GetRoot(),7,15);NL;
      BST.PrintInRangeQueue(BST.GetRoot(),7,15);NL;
    }
    else if(Que == 43)
    {
      //Find the Ceiling for BST
      int pValue = -1;
      BST.InOrderTraversal(BST.GetRoot());NL;
      int A[] = {2,5,7,10,12,15,17};
      for(int i=0;i<7;i++)
      {
	int find = A[i] - 1;
	printf("Ceinling for %d is %d\n",find,BST.Ceiling(BST.GetRoot(),find,0));
      }
    }
    else if(Que == 42)
    {
      //Find the floor for BST
      int pValue = -1;
      BST.InOrderTraversal(BST.GetRoot());NL;
      int A[] = {2,5,7,10,12,15,17};
      for(int i=0;i<7;i++)
      {
	int find = A[i] - 1;
	printf("Floor for %d is %d\n",find,BST.Floor(BST.GetRoot(),find,0));
      }
      
    }
    else if(Que == 41)
    {
       // Find kth Smallest node in given BST
       BST.InOrderTraversal(BST.GetRoot());NL;
       int count = 0;
       printf("%dth node is : %d\n",5,BST.SearchKthMin(BST.GetRoot(),5,count));
    }
    else if(Que == 40)
    {
      //Create BST from sorted array of integer
      int A[] = {1,2,3,4,5,6,7,8,9};
      BinarySearchTree btree;
      btree.SetRoot(BinarySearchTree::CreateBSTFromSortedArray(A,0,8));
      btree.InOrderTraversal(btree.GetRoot());NL;
      btree.PreOrderTraversal(btree.GetRoot());NL;
      btree.PostOrderTraversal(btree.GetRoot());NL;
    }
    else if(Que == 39)
    {
      // Search if given binary tree is binary search tree
      BST.IsBST(BST.GetRoot(),false) ? printf("is BST\n") : printf("not BST\n");
    }
    else if(Que == 38)
    {
      // Find LCA for given nodes.
      printf("LCA of %d : %d %d\n",BST.FindLCA(BST.GetRoot(),12,17),12,17);
    }
    else if(Que == 37)
    {
      //Delete node
      BST.InOrderTraversal(BST.GetRoot());NL;
      BST.DeleteNode(BST.GetRoot(),10);
      BST.InOrderTraversal(BST.GetRoot());NL;
    }
    else if(Que == 36)
    {
      //Que 43. Find maximum element of the BST
      printf("Maximum element %d\n",BST.SearchMax(BST.GetRoot()));
    }
    else if(Que == 35)
    {
	//Que 42. Find minimum element of the BST
        printf("Minimum element : %d\n",BST.SearchMin(BST.GetRoot()));
    }
    else if(Que == 34)
    {
	//Binary search tree InsertNode
	BST.InOrderTraversal(BST.GetRoot());NL;
        //Binary search tree Search Element
	BST.SearchElement(BST.GetRoot(),7) ? printf("Found\n") : printf("Not Found\n");
    }
    
    //Prepare Tree
    BinaryTree tree;
    tree.InsertNode(1);
    tree.InsertNode(2);
    tree.InsertNode(3);
    tree.InsertNode(4);
    tree.InsertNode(5);
    tree.InsertNode(6);
    tree.InsertNode(7);
    tree.InsertNode(8);
    tree.InsertNode(9);
    tree.InsertNode(10);
    tree.InsertNode(11);
    tree.InsertNode(12);
    tree.InsertNode(13);
    tree.InsertNode(14);
    tree.InsertNode(15);
    
    if(Que == 33)
    {
      //Que 38. Find InOrder traversal of given node
      tree.InOrderTraversal(tree.GetRoot());NL;
      printf("InOrder Successor of 10 is %d\n",tree.FindInOrderSuccessor(tree.GetRoot(),10)->data);
      //Que 39. Find PreOrder traversal of given node
      tree.PreOrderTraversal(tree.GetRoot());NL;
      printf("PreOrder Successor of 8 is %d\n",tree.FindPreOrderSuccessor(tree.GetRoot(),8)->data);
      //Que 40. Find PostOrder successsor of the given node
      tree.PostOrderTraversal(tree.GetRoot());NL;
      printf("PostOrder Successor of 11 is %d\n",tree.FindPostOrderSuccessor(tree.GetRoot(),11)->data);
    }
    else if(Que == 32)
    {
	//Que 35. Given a tree with a special property where leaes are represented with '0' and internal nodes are represented as '2' 
	//Also assume each node can have one or two children. Given preorder traversal of this tree. Construct the binary tree.
        int preOrder[] = {2,0,2,0,0};
	BinaryTreeNode * root = BinaryTree::ConstructBinaryTreeFromPreOrder(preOrder,0,4,true);
	BinaryTree tree1;
	tree1.SetRoot(root);
	tree1.InOrderTraversal(tree1.GetRoot());
	NL;
	tree1.PreOrderTraversal(tree1.GetRoot());
	NL;
    }
    else if(Que == 31)
    {
       //ZigZag Traversal
       tree.LevelOrderTraversalZigZag(tree.GetRoot());
    }
    else if(Que == 30)
    {
       int path[128];
       int pathLen = 0;
       //Print all ancestor of given node
       tree.PrintAllAncestor(tree.GetRoot(),path,pathLen,12);
    }
    else if(Que == 29)
    {
      //Construct Binary Tree from inOrder and preOrder Traversal
      int inOrder[] = {1,2,4,5,6,7,9};
      int preOrder[]= {5,4,1,2,7,6,9};
      int postOrder[]={2,1,4,6,9,7,5};
      
      BinaryTree tree1;
      BinaryTreeNode * tNode = BinaryTree::ConstructBinaryTreeFromInOrderANDPreOrder(inOrder,preOrder,0,6,true);
      tree1.SetRoot(tNode);
      printf("InOrder  : ");
      tree1.InOrderTraversal(tree1.GetRoot());
      printf("\nPreOrder : ");
      tree1.PreOrderTraversal(tree1.GetRoot());
      printf("\n");
      
      BinaryTree tree2;
      BinaryTreeNode * tNode1 = BinaryTree::ConstructBinaryTreeFromInOrderANDPostOrder(inOrder,postOrder,0,6,true);
      tree2.SetRoot(tNode1);
      printf("InOrder  : ");
      tree2.InOrderTraversal(tree2.GetRoot());
      printf("\nPreOrder : ");
      tree2.PreOrderTraversal(tree2.GetRoot());
      printf("\n");
      
    }
    else if(Que == 28)
    {
      //Find the LCA
      printf("LCA : %d\n",tree.FindLCA(tree.GetRoot(),9,10));
    }
    else if(Que == 27)
    {
       //Find sum of all elements in binary tree
       printf("Sum : %d\n",tree.FindSumOfAllElement(tree.GetRoot()));
    }
    else if(Que == 26)
    {
      BinaryTree tree1;
      tree1.InsertNode(1);
      tree1.InsertNode(2);
      tree1.InsertNode(1);
      tree1.InsertNode(5);
      tree1.InsertNode(4);
      tree1.InsertNode(6);
      tree1.InsertNode(5);
      
      printf("Print all paths with sum 8 :\n");
      int Path[124];
      int pathlen = 0;
      bool result = tree1.PrintAllPathsWithSum(tree1.GetRoot(),Path,pathlen,7);
      if(result)
	printf("Path with given sum exists\n");
      else
	printf("Path with given sum does not exists\n");
    }
    else if(Que == 25)
    {
      printf("Print all the paths from root to leaves.\n");
      int Path[124];
      int pathlen = 0;
      tree.PrintAllPathsToLeaves(tree.GetRoot(),Path,pathlen);
    }
    else if(Que == 24)
    {
      printf("Level with maximum sum : %d\n",tree.FindMaxSumLevel(tree.GetRoot()));
    }
    else if(Que == 23)
    {
      printf("Height of tree : %d\n",tree.HeightOfTree(tree.GetRoot()));
      printf("Diameter of tree : %d\n",tree.DiameterOfTree(tree.GetRoot()));
    }
    else if(Que == 22)
    {
       BinaryTree tree1;
      tree1.InsertNode(1);
      tree1.InsertNode(2);
      tree1.InsertNode(3);
      tree1.InsertNode(4);
      tree1.InsertNode(5);
      tree1.InsertNode(6);
      tree1.InsertNode(7);
      BinaryTree::CompairTwoBinaryTrees(tree1.GetRoot(),tree.GetRoot()) ? printf("Identical\n") : printf("Different\n");
    }
    else if(Que == 21)
    {
      printf("Number of half nodes : %d\n",tree.FindHalfNodes(tree.GetRoot()));
    }
    else if(Que == 20)
    {
      printf("Number of full nodes : %d\n",tree.FindFullNodes(tree.GetRoot()));
    }
    else if(Que == 19)
    {
      printf("Number of leaves : %d\n",tree.FindLeaves(tree.GetRoot()));
    }
    else if(Que == 18)
    {
       tree.InOrderTraversal(tree.GetRoot()); printf("\n");
       tree.DeleteNode(tree.GetRoot(),4);
       tree.InOrderTraversal(tree.GetRoot());
    }
    else if(Que == 17)
    {
      //Find the deepest node
      printf("Deepest Node : %d\n",tree.FindDeepestNode(tree.GetRoot())->data);
    }
    else if(Que == 16)
    {
      printf("Height of tree is : %d\n",tree.FindHeightWORecursion(tree.GetRoot()));
    }
    else if(Que == 15)
    {
	printf("Height of tree is : %d\n",tree.FindHeight(tree.GetRoot()));
    }
    else if(Que == 14)
    {
      tree.LevelOrderTraversalReverse(tree.GetRoot());
    }
    else if(Que == 13)
    {
      printf("Size of binary tree WO(R) : %d\n",tree.FindSizeWORecursion(tree.GetRoot()));
    }
    else if(Que == 12)
    {
      printf("Size of binary tree : %d\n",tree.FindSize(tree.GetRoot()));
    }
    else if(Que == 11)
    {
      tree.FindElementWORecursion(tree.GetRoot(), 5) ? printf("Element found\n") : printf("Element not found\n");
      tree.FindElementWORecursion(tree.GetRoot(), 9) ? printf("Element found\n") : printf("Element not found\n");
    }
    else if(Que == 10)
    {
      tree.FindElement(tree.GetRoot(), 5) ? printf("Element found\n") : printf("Element not found\n");
      tree.FindElement(tree.GetRoot(), 9) ? printf("Element found\n") : printf("Element not found\n");
    }
    else if(Que == 9)
    {
      //Find Maximum element without recursion
      printf("Max : %d\n",tree.FindMaxWORecursion(tree.GetRoot()));
    }
    else if(Que == 8)
    {
      //Find max element in simple binary tree;
      printf("Max : %d\n",tree.FindMax(tree.GetRoot()));
    }
    else if(Que == 7)
    {
      //Level Order traversal
      tree.LevelOrderTraversal(tree.GetRoot());
    }
    else if(Que == 6)
    {
      //Post order traversal without recursion
      tree.PostOrderTraversalWORecursion(tree.GetRoot());
    }
    else if(Que == 5)
    {
      //Post Order traversal with recursion
      tree.PostOrderTraversal(tree.GetRoot());
    }
    else if(Que == 4)
    {
	//PreOrderTraversal non recursion
        tree.PreOrderTraversalWORecursion(tree.GetRoot());
    }
    else if(Que == 3)
    {
      //PreOrder traversal recursion
      tree.PreOrderTraversal(tree.GetRoot());
    }
    else if(Que == 2)
    {
       //InOrder Traversal without recursion
       tree.InOrderTraversalWORecursion(tree.GetRoot());
    }
    else if(Que == 1)
    {
       //InOrder Traversal With Recursion
       tree.InOrderTraversal(tree.GetRoot());
       printf("\n");
    }
}
void Chapter_05(int Que)
{
      if(Que = 7)
      {
			//Que 7. Given a Queue Q containing n elements, transfer these items on to a stack S(initially empty) 
			//so that front element of Q appears at the top of the stack and the order of all other items is 
			//preserved. Using enQueue and DeQueue operations for the queue and push and pop operations for the 
			//stack, outline an efficient O(n) algorithm to accomplish the above task,
			//Using the constant amout of additional storage.
			
			LinkedListQueue queue;
			queue.EnQueue(1);
			queue.EnQueue(2);
			queue.EnQueue(3);
			queue.EnQueue(4);
			queue.EnQueue(5);
			queue.PrintQueue();
			LinkedListStack * stack = StoreQueueElementInStack(queue);
			stack->PrintStack();
	
      }
      else if(Que == 6)
      {
			  //Que 6. Maximum in sliding window. For a given A[] with sliding window size w,
			  //which is moving from left to right. 
			  //Assume that we can only see w elements in the window.
			  int A[] = {1,3,-1,-3,5,3,6,7};
			  PrintArray(A,8);
			  printf("Max window : %d sum : %d\n",3,MaxSlidingWindow(A,8,3));
      }
      else if(Que == 5)
      {
			//Que 5. Implement of stack using two Queues.
			StackUsingTwoQueues stack;
			stack.Push(1);
			stack.Push(2);
			stack.Push(3);
			stack.Pop();
			stack.Push(4);
			stack.Pop();
			stack.Pop();
			stack.Pop();
			stack.Pop();
      }
      else if(Que == 4)
      {
			 //Que 4. Implement Queue using two Stacks.
			 QueueUsingTwoStacks queue;
			 queue.EnQueue(1);
			 queue.EnQueue(2);
			 queue.EnQueue(3);
			 queue.EnQueue(4);
			 queue.DeQueue();
			 queue.DeQueue();
			 queue.DeQueue();
			 queue.DeQueue();
			 queue.DeQueue();
      }
      else if(Que == 3)
      {
		  //Que. 3 Reverse Queue using Queue ADT methods
			LinkedListQueue queue;
			queue.EnQueue(1);
			queue.EnQueue(2);
			queue.EnQueue(3);
			queue.EnQueue(4);
			ReverseQueue(queue);
      }
      else if(Que == 2)
      {
			LinkedListQueue queue;
			queue.EnQueue(1);
			queue.EnQueue(2);
			queue.DeQueue();
			queue.EnQueue(3);
			queue.EnQueue(4);
			queue.DeQueue();
			queue.DeQueue();
			queue.DeQueue();
			queue.DeQueue();
      }
      else if(Que == 1)
      {
			ArrayQueue queue1(5);
			queue1.EnQueue(1);
			queue1.EnQueue(2);
			queue1.DeQueue();
			queue1.EnQueue(3);
			queue1.EnQueue(4);
			queue1.DeQueue();
			queue1.DeQueue();
			queue1.DeQueue();
			queue1.DeQueue();
      }
}

void Chapter_04(int Que)
{
	//Que 1. Discuss how stacks can be used for checking balancing of symbols.
    //char A[] = "(A+B)+(C+D)";
    //IsExpressionBalanced(A,strlen(A)) ? printf("Expression is balanced.\n") : printf("Expression is not balanced.\n");
    //
    //Que 2. Infix to postfix conversion
    char ex[] = "1+2*3";
    char ex1[] = "A*(B+C)*D";
    char ex2[] = "A*B-(C+D)+E";
    printf("infix : %s\npostfix : %s\n",ex,InfixToPostFix(ex));
    printf("infix : %s\npostfix : %s\n",ex1,InfixToPostFix(ex1));
    printf("infix : %s\npostfix : %s\n",ex2,InfixToPostFix(ex2));
    //Que 3. Eval postfix expression
    char ex4[] = "234+*5*";
    printf("postfix : %s\neval : %d\n",ex4,PostFixEval(ex4));
    // Que 4. Infix expression evaluation
    char ex5[]="(1+2)*3+4*4-3";
    printf("infix : %s\neval : %d\n",ex5,InfixEval(ex5));
    // Que 5. Minimum stack 
    int ex6[] = {7,3,2,6,10,1,0};
    GetMinimum(ex6,7);
    // Que 6. Reverse stack elements
    LinkedListStack stack;
    stack.Push(1);stack.Push(2);stack.Push(3);stack.Push(4);stack.Push(5);
    stack.PrintStack();
    ReveseStack(stack);
    stack.PrintStack();
    // Que 7. Find increasing span
    int exp7[] = {6,3,4,5,2,7};
    int * result = FindingSpans(exp7,6);
    printf("Find Increasing Span\n");
    for(int i=0;i<6;i++)
      printf("%d\t%d\n",exp7[i],result[i]);
    printf("\n");
    // Que 8. Find the maximum histogram area covered
    int exp8[] = {3,2,5,3,1,4,4};
    int n = 7;
    printf("Max Rectangle Area :: %d\n",MaxRectangleArea(exp8,n));
}

void Chapter_03(int Que)
{
	//Que 1. Implementatio of stack using link list
    //LLStack stack;
    //stack.Push(1);
    //stack.Push(2);
    //stack.Push(3);
    //stack.Push(4);
    //stack.Pop();
    //stack.Pop();
    //stack.Pop();
    //stack.Pop();
    //stack.Pop();
    LL * root = NULL;
    root = InsertNodeAtEnd(1,root);
    root = InsertNodeAtEnd(2,root);
    root = InsertNodeAtEnd(3,root);
    root = InsertNodeAtEnd(4,root);
    root = InsertNodeAtEnd(5,root);
    root = InsertNodeAtEnd(6,root);
    root = InsertNodeAtEnd(7,root);
    root = InsertNodeAtEnd(8,root);
    //root = InsertNodeAtEnd(1,root);
    //Que 3. Reverse Link List recursively
    //root = ReverseLL(root);
    //PrintLL(root);
    //Que 4. Print Link list reverse using recursion
    //PrintLLReverse(root);
    //Que 6. Find middle element of given link list
    //PrintLL(root);
    //printf("Middle Element : %d\n",FindMiddleNode(root)->data);
    //Que 7. Merge Two sorted link list in single scan
    //PrintLL(root);
    //PrintLL(root1);
    //root = MergeSortedLLists(root,root1);
    //PrintLL(root);
    //Que 8. Reverse Linked List in pairs
    //root = ReverseLLinPairs(root);
    //PrintLL(root);
    //Que 9. Sort Linked Lists using Merge sorts
    //root = MergeSorts(root);
    //PrintLL(root);
    //Que 10. Find if given Linked list is palindrome or not
    //IsPalindrome(root) ? printf("Given LL is palindrome\n") : printf("Given LL is not palindrome\n");
    PrintLL(root);
    //Que 11. Reverse given linked list in k-elements pairs
    root = ReverseLLinKthPairs(root,3);
    PrintLL(root);
    //Que 12. Josephus Circle problem
    printf("Elected leader : %d\n",JoshephusCircle(5,2));
}

void Chapter_02(int Que)
{
	  if(Que == 10)
      {
			 //Que 10. Remove the adjacent duplicate elements
			 char A[] = "caaabbbaacdddd";
			 printf("%s\n",A);
			 RemoveAdjacentDuplicates(A);
			 printf("%s\n",A);
      }
      else if(Que == 9)
      {
			//Que 9. Knight Tour problem
			SolveKnightProblem(8);
      }
      else if(Que == 8)
      {
			//Que 8. Find the path for rat in maze
			int maze[N][N]  =  
			{ 
			  {1, 0, 0, 0},
			  {1, 1, 0, 1},
			  {0, 1, 0, 0},
			  {1, 1, 1, 1}
			};
			SolveMazeProblem(maze);
      }
      else if(Que == 7)
      {
			//Que 7. N Queen problem
			solveNQ();
      }
      else if(Que == 6)
      {
			/* Que 6. Subset sum */
			int weights[] = {10, 7, 5, 18, 12, 20, 15};
			SubSetSum(weights,7,35);
      }
      else if(Que == 5)
      {
			 //Que 5. Tug Of War
			int A[] = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
			int n = sizeof(A)/sizeof(A[0]);
			TugOfWar(A,n);
      }
      else
      {
			//Que 1. Tower Of Hanoi problem
			printf("Tower Of Hanoi Problem\n");
			TowerOfHanoi(3,'A','B','C',true);
			
			//Que 2. All binary with given number of digits
			printf("Binary number problem\n");
			char A[5];
			BinaryNumber(5,5,A,true);
			
			//Que 3. All base k number with given number of digits
			printf("Base K array all elements\n");
			BaseKNumber(5,3,5,A,true);
			
			//Que 4. Print all permutations of a given string
			char str[] = "ABC";
			PrintAllPermutationsOf(str,3,0);
      }
}

// Chapter : 14 ( Graph Algorithms )
void Chapter_14(int Que)
{
	if( Que == 1 || Que == 5 || Que == 6 || Que == 7 || Que == 8 || Que == 9) 
	{
		// DFS search
		Graph g(8);
		g.AddEdge(1,2);
		g.AddEdge(2,3);
		g.AddEdge(2,5);
		g.AddEdge(3,4);
		g.AddEdge(3,6);
		g.AddEdge(4,7);
		g.AddEdge(6,5);
		g.AddEdge(6,8);
		g.AddEdge(6,7);
		
		// DFS
		g.DFSTraversal();
		// BFS
		g.BFSTraversal();
		// Sortest path for unweighted
		g.UnWeightedSorted_Path(0);
		// Find total number of paths between two nodes
		cout<<"Total Number of paths : "<<g.CountNumberOfPaths(0,7)<<endl;
		// Articulation points
		g.AP();
		// Bridge in Graph
		g.bridge();
		cout<<"Is Eulerian : "<<g.isEulerian()<<endl;
		cout<<"Is Cyclic : "<<(g.isCyclic() ? "yes" : "no")<<endl;
	}
	else if( Que == 2 ) 
	{
		// Topological Sort
		Graph g(6,true);
		g.AddEdge(6, 3);
		g.AddEdge(6, 1);
		g.AddEdge(5, 1);
		g.AddEdge(5, 2);
		g.AddEdge(3, 4);
		g.AddEdge(4, 2);

		g.TopologicalSort();
	}
	else if( Que == 3 || Que == 10 || Que == 11) 
	{
		//Djkstra Algo & BellmanFord
		GraphWeighted g(5,true);

		g.AddEdge(1,3,1);
		g.AddEdge(1,2,4);
		g.AddEdge(3,2,2);
		g.AddEdge(3,4,4);
		g.AddEdge(4,5,4);
		g.AddEdge(2,5,4);

		// to check hamilton cycle
		if(Que == 11) 
		{
			g.AddEdge(5,3,4);
			g.AddEdge(2,1,4);
			g.AddEdge(5,2,4);
		}

		g.Dijkstra(0);
		g.BellmanFord(0);
		cout<<"Is Cyclic : "<<(g.isCyclic() ? "yes" : "no")<<endl;
		g.HamiltonCycle();
	}
	else if(Que == 4) 
	{
		Graph g(8);
		g.AddEdge(6, 3);
		g.AddEdge(6, 1);
		g.AddEdge(5, 1);
		g.AddEdge(5, 2);
		g.AddEdge(3, 4);
		g.AddEdge(4, 2);
		g.AddEdge(5, 8);

		printf("\nIsConnected : %s\n",g.IsConnected(0,5)?"true":"false");
	}
	else if(Que == 5 ) 
	{
		// See Que 1
	}
	else if(Que == 6) 
	{
		// See Que 1
	}
	else if(Que == 7 ) 
	{
		// See Que 1
	}
	else if(Que == 8) 
	{
		// See Que 1
	}
	else if(Que == 9 ) 
	{
		// See Que 1
		// Check if given graph is cyclic
	}
	else if(Que == 10) 
	{
		// See Que 3
		// Check if given directed graph has cycle 
	}
	else if(Que == 11) 
	{
		// See Que 3
		// Check if given graph have hamilton cycle
	}
}
// Hashing
void Chapter_16(int Que)
{
	if( Que == 1 ) 
	{
		ChainingHash();
	}
}
