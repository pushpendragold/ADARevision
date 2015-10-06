#ifndef _H_DYNAMIC_PROGRAMMING_H_
#define _H_DYNAMIC_PROGRAMMING_H_

// Que 1. 0-1 Knapsack Problem

/* Recursion solution */
int KnapsackRecursion(int WeightAllowed,int input[],int value[], int n);
int maxInteger(int a,int b);

/*Dynamic programming */
int KnapsackDP(int W, int wt[], int val[], int n);


//Que 2. Stock market maximize profit algorithm (incomplete)
/* Recursion solution */
int MaxProfit(int A[],int n,int low,int high);


//Que 3. Rope cutting problem
/* Recursion solution */
int RopeCuttingProblem_recursion(int n,int current_product);

/* Dynamic programming */
int RopeCuttingProblem_DP(int n);
int RopeCuttingProblem_DP_Until(int n,int current_product,int A[],int number_of_elements);

//Que 4. Longest length of airthmetic progression
bool CheckifAP(int set[],int n); //Assumption set is sorted.
int  LongestLengthAP_DP(int set[],int n);
void Print2DArray(int ** L,int n);

//Que 5. Find if a given string is interleaved of two other strings
bool CheckIfInterleaving(char * A, char * B, char * C);
bool CheckIfInterleaving_DP(char * A, char * B, char * C);
void Print2DArray(bool **A,int i,int j);

//Que 6. Coin Change problem
int FindMinChange(int change[],int cSize,int n);
int FindMinChange_Recursion(int change[],int cSize,int currentDenom,int n);
int FindMinChange_DP(int change[],int cSize,int n);
int FindMinChange_DP_until(int change[],int cSize,int currentDenom,int n,int DP[]);

//Que 7. Longest palindrome in given string
int lcs( char *X, char *Y, int m, int n );

// Que 8. Maximum continuous sum subsequnce
int MaxContinuousSubSequenceSum(int A[],int n);

// Que 9. catalan number : number of binary trees possible with n nodes
int CatalanNumber(int n,int table[]);
int CatalanNumber(int n);

// Que 10. Number of ways player can reach from 1,1 to n,m  if only moving horizontal or verically down is allowed. 
int FindNumberOfWays(int n,int m);

// Que 11. Largest common subsequence
int FindLargestCommonSubsequence(int A[],int nA,int B[],int nB);

#endif