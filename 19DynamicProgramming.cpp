#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

#define DEBUG 1

#include "06Trees.h"
#include "19DynamicProgramming.h"

#include "tools.h"

/**************************************************************************************************
 * Que 1. 0-1 Knapsack Problem
 * 
 * Given weights and values of n items, put these items in a knapsack of capacity W to 
 * get the maximum total value in the knapsack. In other words, given two integer arrays 
 * val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items 
 * respectively. Also given an integer W which represents knapsack capacity, find out the 
 * maximum value subset of val[] such that sum of the weights of this subset is smaller 
 * than or equal to W. You cannot break an item, either pick the complete item, or don’t 
 * pick it (0-1 property).
 * 
 * Comments : A simple solution is to consider all subsets of items and calculate the 
 * total weight and value of all subsets. Consider the only subsets whose total weight 
 * is smaller than W. From all such subsets, pick the maximum value subset.
 * 
 * 1) Optimal Substructure:
*  To consider all subsets of items, there can be two cases for every item: 
*  		(1) the item is included in the optimal subset, 
* 		(2) not included in the optimal set.
*  Therefore, the maximum value that can be obtained from n items is max of following two values.
* 	1) Maximum value obtained by n-1 items and W weight (excluding nth item).
*	2) Value of nth item plus maximum value obtained by n-1 items and W minus 
* 	   weight of the nth item (including nth item).
* 
*  If weight of nth item is greater than W, then the nth item cannot be included and case 
*  1 is the only possibility.
* 
* 2) Overlapping Subproblems ( Searching for all possible solutions)
* Following is recursive implementation that simply follows the recursive structure mentioned above.
* 
* ****************************************************************************************************/
/* Recursion Solution 
   Time Complexity : O(2^n)
 */
int KnapsackRecursion(int WeightAllowed,int weight[],int value[],int n)
{
    if(n == 0 || WeightAllowed == 0)
      return 0;
    
    // If weight of the nth item is more than Knapsack capacity W, then
    // this item cannot be included in the optimal solution
    if(weight[n-1] > WeightAllowed)
      return KnapsackRecursion(WeightAllowed,weight,value,n-1);
      
    // Return the maximum of two cases: 
    // (1) Nth item included 
    // (2) Nth item not included
    return maxInteger(  value[n-1] + 
	   KnapsackRecursion(WeightAllowed - weight[n-1],weight,value,n-1) , 
       KnapsackRecursion(WeightAllowed,weight,value,n-1)
    ); 
}
int maxInteger(int a, int b)
{
    return a > b ? a : b;
}
/* Dynamic Programming
   Time Complexity : O(nW)
 */
int KnapsackDP(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i == 0 || w == 0)
               K[i][w] = 0;
           else if ( wt[i-1] <= w )
                 K[i][w] = maxInteger( val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w] );
           else
                 K[i][w] = K[i-1][w];
       }
   }
   for(i = 0; i<=n; i++)
   {
      for( w=0 ; w<=W; w++)
		  printf("%d\t",K[i][w]);
      printf("\n");
   }
 
   return K[n][W];
}
/**************************************************************************************************
 * Que 2. Maximize profit for stock data given for n number of days.
 * 
 * Constrants : 1) Each days stock prices are given.
 * 		2) Required to purchase before selling.
 * 		3) n days may involve any number of transaction.
 * 
 * 
 *  
 * ****************************************************************************************************/
/* Recursion approach */
int MaxProfit(int A[], int n,int low,int high)
{
      if(high == n-1)
		  return A[high] - A[low];
      
      if(low == high)
      {
		  return MaxProfit(A,n,low,low+1);
      }
      else if(A[high] > A[low])
      {
		  int purchased = A[high] - A[low] + MaxProfit(A,n,high+1,high+1);
		  int notPurchased = MaxProfit(A,n,low,high+1);
		  if(purchased > notPurchased)
		  {
			  printf("%d %d :: %d %d\n",low,high,A[low],A[high]);
			  return purchased;
		  }
		  return notPurchased;
      }
	  return MaxProfit(A,n,low+1,low+1);
}
/*********************************************************************************************
 * Que 3. Given a rope of length n meters, cut the rope in different parts of integer lengths 
 * in a way that maximizes product of lengths of all parts. You must make at least one cut. 
 * Assume that the length of rope is more than 2 meters.
 * Examples:
 * 
 * Input: n = 2
 * Output: 1 (Maximum obtainable product is 1*1)
 * 
 * Input: n = 3
 * Output: 2 (Maximum obtainable product is 1*2)
 * 
 * Input: n = 4
 * Output: 4 (Maximum obtainable product is 2*2)
 * 
 * Input: n = 5
 * Output: 6 (Maximum obtainable product is 2*3)
 * 
 * Input: n = 10
 * Output: 36 (Maximum obtainable product is 3*3*4)
 * 
 * *******************************************************************************************/
/* Recursion Solution */
int RopeCuttingProblem_recursion(int n,int current_product)
{
   //in case
   if(n <= 0) return 1;
   
   //Boundary condition
   if(n == 2)
   {
      if(current_product == 1) return 1;
      return 2;
   }
   
   printf("Recursion : %d\n",n);
   int maxProduct = current_product;
   int temp;
   for(int i=2;i<n;i++)
   {
      temp = maxInteger(current_product * i *(n-i),RopeCuttingProblem_recursion(n-i,current_product * i));

      if(maxProduct < temp)
	maxProduct = temp;
   }
   return maxProduct;
}
/* Dynamic Programming approach */
int RopeCuttingProblem_DP(int n)
{
   int A[n];
   for(int i=0;i<n;i++) A[i] = 0;
   return RopeCuttingProblem_DP_Until(n,1,A,n);
}
int RopeCuttingProblem_DP_Until(int n,int current_product,int A[],int number_of_elements)
{
   if(n <= 1) return 1;
   if(n == 2)
   {
      if(current_product == 1) return 1;
      return 2;
   }
    
   if(A[n-1] != 0) return A[n-1];
    
   printf("DP : %d\n",n);
   int maxProduct = current_product;
   int temp; int tempA;
   for(int i=2;i<n;i++)
   {
      temp = maxInteger(current_product * i *(n-i),RopeCuttingProblem_DP_Until(n-i,current_product * i,A,number_of_elements));
      
      if(A[i-1] == 0) A[i-1] = temp;
      
      if(maxProduct < temp)
	maxProduct = temp;
   }
   return maxProduct;
}
/**********************************************************************************************
 * Que 4. Find the longest length of AP in given set of elements.
 * 
 * Given a set of numbers, find the Length of the Longest Arithmetic Progression (LLAP) in it.
 * 
 * Examples:
 * 
 * set[] = {1, 7, 10, 15, 27, 29}
 * output = 3
 * The longest arithmetic progression is {1, 15, 29}
 * 
 * set[] = {5, 10, 15, 20, 25, 30}
 * output = 6
 * The whole set is in AP
 * 
 * Time Complexity : O(N^2)
 * 
 *********************************************************************************************/ 
/* Recursion Approach */
bool CheckifAP(int set[], int n)
{
   for(int i=1;i<n;i++)
   {
      int low  = i-1;
      int high = i+1;
      
      //Binary search
      while(low >= 0 && high <= n-1)
      {
		  if(set[low] + set[high] == 2*set[i])
			  return true;
		  set[low] + set[high] > 2 * set[i] ? high -- : low ++;
      }
   }
   return false;
}
/* Dynamic programming */
int LongestLengthAP_DP(int set[], int n)
{
    //Breaking condition
    if(n <= 2) return n;
    
    int * L[n];
    for(int i=0;i<n;i++)
      L[i] = new int[n];
    
    int llap = 2;	//any two given numbers are always in AP
    
    //Initialize last row by 2
    for(int i=0;i<n;i++)
      L[i][n-1] = 2;
    
    Print2DArray(L,n);
    
    //Consider every element as second element of the AP
    for(int j=n-2; j>=1; j--)
    {
	int low  = j - 1;
	int high = j + 1;
	
	while(low >= 0 && high <= n-1)
	{
	   if(set[low] + set[high] < 2*set[j])
	   {
	      high++;
	   }
	   else if(set[low] + set[high] > 2*set[j])
	   {
	      L[low][j] = 2;
	      Print2DArray(L,n);
	      low--;
	   }
	   else
	   {
	      //found 
	      L[low][j] = L[j][high] + 1;
	      Print2DArray(L,n);
	      llap = maxInteger(llap,L[low][j]);
	      low--;
	      high++;
	   }
	}
	
	while(low >= 0)
	  L[low--][j] = 2;
    }
    
    return llap;
}
void Print2DArray(int ** L,int n)
{
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
	printf("%d ",L[i][j]);
      printf("\n");
   }
   printf("\n");
}
/*********************************************************************************************
 * Que 5. Find if a given string is interleaved of two other strings
 * 
 * Given three strings A, B and C. Write a function that checks whether C is an interleaving 
 * of A and B. C is said to be interleaving A and B, if it contains all characters of A and B 
 * and order of all characters in individual strings is preserved.
 * 
 * For example A = “XXY”, string B = “XXZ” and string C = “XXZXXXY”.
 * function should return true otherwise false.
 * 
 * For recursive solution : Time complexity : O(2^n) (worst case)
 * For Dynamic solution   : Time Complexity : O(M*N) 
 * 
 *********************************************************************************************/
/* Recursion approach */
bool CheckIfInterleaving(char * A, char * B, char * C)
{
    //Boundary condition
    if(!(*A || *B || *C))
      return true;
    
    //Check if C is empty
    if(*C == '\0') return false;
    
    return (*C == * A) && CheckIfInterleaving(A+1,B,C+1) ||
	   (*C == * B) && CheckIfInterleaving(A,B+1,C+1);
}
/* Dynamic Programming */
bool CheckIfInterleaving_DP(char* A, char* B, char* C)
{
    int M = strlen(A);
    int N = strlen(B);
    
    int P = strlen(C);
    
    if(P != M+N) return false;
    
    
    bool ** flag = new bool * [M+1];
    for(int i=0;i<M+1;i++)
      flag[i] = new bool[N+1];
    
    for(int i=0;i<M+1;i++)
      for(int j=0;j<N+1;j++)
	flag[i][j] = false;
      
    for(int i=0;i<=M;i++)
    {
      for(int j=0;j<=N;j++)
      {
	 if(i == 0 && j == 0)
	   flag[i][j] = true;
	 
	 //if A is empty;
	 else if(i == 0 && B[j-1] == C[j-1])
	   flag[i][j] = flag[i][j-1];
	 
	 //if B is empty
	 else if(j == 0 && A[i-1] == C[i-1])
	   flag[i][j] = flag[i-1][j];
	 
	// Current character of C matches with current character of A,
	// but doesn't match with current character of B
	else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1])
	    flag[i][j] = flag[i-1][j];

	// Current character of C matches with current character of B,
	// but doesn't match with current character of A
	else if (A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1])
	    flag[i][j] = flag[i][j-1];

	// Current character of C matches with that of both A and B
	else if (A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1])
	    flag[i][j]=(flag[i-1][j] || flag[i][j-1]) ;
      }
    }
    Print2DArray(flag,M,N);
    return flag[M][N];
}
void Print2DArray(bool** A, int i, int j)
{
    for(int a=0;a<i;a++)
    {
      for(int b=0;b<j;b++)
      {
	printf("%d ",A[i][j]);
      }
      printf("\n");
    }
    printf("\n");
}
/*******************************************************************************************
 * Que 6. Find the minumum number of change required for a given amount.
 * 
 * Algo Type : Recursion (Exahaustive search)
 * Time Complexity : Recursion O()
 * 
 * 
 * Algo Type : DP (Bottom up approach)
 * Time Complexity : O(nk)
 * 
 * ****************************************************************************************/
int FindMinChange(int change[], int cSize, int n)
{
    if(n != 0)
    {
      int c = FindMinChange_Recursion(change,cSize,cSize - 1,n);
      return c;
    }
    return 0;
}
int FindMinChange_Recursion(int change[], int cSize,int currentDenom, int n)
{
   //Break Condition
   if(n <= 0) return 0;
   
   if(currentDenom < 0) return INT_MAX;
   
   printf("Recursion : %d %d \n",n,currentDenom);
   
   int denomSelected = INT_MAX;
   int denomNotSelected = INT_MAX;
   int k = 1;
   
   if(n - change[currentDenom] >= 0)
   {
      while(n - k*change[currentDenom] >= 0)
	k++;
      k--;
      
      denomSelected = k + FindMinChange_Recursion(change,cSize,currentDenom,n - k*change[currentDenom]);
   }  
   denomNotSelected = FindMinChange_Recursion(change,cSize,currentDenom-1,n);
   return minInteger(denomNotSelected,denomSelected);
}
/* Dynamic Programming */
int FindMinChange_DP(int change[], int cSize, int n)
{
    int DP_solution[n];
    memset(DP_solution,0,sizeof(DP_solution));
    DP_solution[0] = 1;
    return FindMinChange_DP_until(change,cSize,cSize - 1,n,DP_solution);
}
int FindMinChange_DP_until(int change[], int cSize, int currentDenom, int n, int DP[])
{
    if(n == 0) return 0;
 
    if(currentDenom < 0) return INT_MAX;
    
    if(DP[n - 1] != 0) return DP[n-1];
   
    printf("DP : %d %d \n",n,currentDenom);
    
    for(int i=1;i<=n;i++)
    {
      int min = INT_MAX;
      for(int j=0;j<cSize;j++)
      {
		  if(i >= change[j])
		  {
			  if(DP[i - change[j] - 1] + 1 < min)
			  {
				  min = DP[i - change[j] - 1] + 1;
			  }
		  }
      }
      DP[i  - 1] = min;
    }
   return DP[n-1];
}
/***************************************************
 * Que 7. Longest palindrome in given string 
 * 
 * Time complexity : O(m*n) 
 * Space complexity : O(m + n) 
 ***************************************************/
int max(int a,int b) 
{
	   return a > b ? a : b;
}
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
   
   int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i = 0; i <= m; i++ )
   {
     for (j = 0; j <= n; j++)
     {
        if (i == 0 || j == 0)
			L[i][j] = 0;
		else if (X[i-1] == Y[j-1])
			L[i][j] = L[i-1][j-1] + 1;
		else
			L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

/***************************************************
 * Que 8. Maximum continuous sum subsequnce
 * 
 * Time complexity : O(n) 
 * Space complexity : O(n) 
 ***************************************************/
int MaxContinuousSubSequenceSum(int A[],int n)
{
	int M[n];
	M[0] = (A[0] > 0) ? A[0] : 0;
	for(int i = 1; i < n; i++) 
	{
		if( M[ i - 1 ] + A[i] > 0 ) 
			M[ i ] = M[ i - 1 ] + A[i];
		else
			M[i] = 0;
	}

	int maxSum = 0;
	for(int i =0; i < n; i++ ) 
	{
		if( maxSum < M[i] ) 
			maxSum = M[i];
	}
	return maxSum;
}
/***************************************************
 * Que 9. Catalan number
 * 
 * Time complexity : O(n) 
 * Space complexity : O(n) 
 ***************************************************/
int CatalanNumber(int n)
{
	int table[n + 1];
	for(int i = 0; i < n + 1; i++) 
		table[i] = 0;
	return CatalanNumber(n,table);
}
int CatalanNumber(int n,int table[])
{
	if( table[n] != 0 ) return table[n];
	if(n <= 0) return 1;
	
	for(int i = 1; i <= n; i++) 
		table[n] += CatalanNumber(i - 1,table) * CatalanNumber(n - i,table);

	return table[n];
}
/***********************************************************
 * Que 10. Number of ways player can reach from 1,1 	1to n,m 
 * if only moving horizontal or verically down is allowed. 
 * 
 * Time complexity : O(n*m) 
 * Space complexity : O(n*m) 
 ***************************************************/
int FindNumberOfWays(int n,int m)
{
	vector< vector<int> > A;
	A.resize(n);

	for(int i = 0; i < n; i++) 
		A[i].resize(m);

	for(int i = 0; i < n; i++) 
	{
		for(int j = 0; j < m; j++) 
		{
			if( i == 0 ) 
			{
				A[i][j] = 1;
			}
			else
			{
				if( j > 0 ) 
					A[i][j] = A[i-1][j] + A[i][j-1];
				else
					A[i][j] = A[i-1][j];
			}
		}
	}

	if( DEBUG )
	{
		for(int i = 0; i < n; i++) 
		{
			for(int j = 0; j < m; j++) 
				cout<<A[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	return A[n-1][m-1];
}
/***********************************************************
 * Que 11. Longest common subsequence
 * 
 * Time complexity : O(n*m) 
 * Space complexity : O(n*m) 
 ***************************************************/
int FindLargestCommonSubsequence(int A[],int nA,int B[],int nB)
{
	vector< vector<int> > Arr;
	Arr.resize(nA + 1);
	for(int i = 0; i < nA + 1; i++) 
		Arr[i].resize(nB + 1);

	for (int i=1; i<=nA; i++)
    {
		for (int j=1; j<=nB; j++)
		{
			if (A[i-1] == B[j-1])
				Arr[i][j] = Arr[i-1][j-1] + 1;
			else
				Arr[i][j] = max(Arr[i-1][j], Arr[i][j-1]);
        }
   }
   return Arr[nA][nB];
}
