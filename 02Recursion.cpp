#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <iostream>

#include "02Recursion.h"
#include "tools.h"

using namespace std;

/* *************************************************************
 * Que 1. Tower Of Hanoi
 * 
 * Algo Type : Recursion
 * 
 * Parameters : Number of disks,
 * 		Source Tower
 * 		Destination Tower
 * 		Auxillary Tower
 * 		bool to start counting number of steps
 * 
 * Return     : None
 * 
 * Time  Complexity : O(n^2)
 * Space Complexity :
 * *************************************************************/
void TowerOfHanoi(int n,char from,char to,char aux,bool _set)
{
  static int nSteps = 0;
  if(_set) nSteps = 0;
  
  if(n == 1)
  {
      nSteps++;
      printf("%d\tMove Disk %d from Tower %c To Tower %c\n",nSteps,n,from,to);
      return;
  }
  
  TowerOfHanoi(n-1,from,aux,to,false);
  
  nSteps++;
  printf("%d\tMove Disk %d from Tower %c To Tower %c\n",nSteps,n,from,to);
  
  TowerOfHanoi(n-1,aux,to,from,false);
  
}
/* *************************************************************
 * Que 2. Generate all the strings of n bits. for Binary number.
 * 
 * Algo Type : BackTracking
 * 
 * Parameters : number of bits
 * Return     : None
 * 
 * Time Complexity : 
 * 
 *        c             if n < 0
 * T(n) = 
 * 	  2T(n-1) + d   otherwise
 * Substraction and Conquer Master Theorem
 * O(2^n)
 * 
 * *************************************************************/
void BinaryNumber(int n, int size, char A[],bool _set)
{
  static int nCount = 0;
  if(_set) nCount = 0;
  
  if(n < 1)
  {
    printf("%d\t",++nCount);
    PrintArray(A,size,false);
    return;
  }
  else
  {
      A[n-1] = 0 + '0';
      BinaryNumber(n-1,size,A);
      A[n-1] = 1 + '0';
      BinaryNumber(n-1,size,A);
  }
}
/* *************************************************************
 * Que 3. Generate all the strings of n bits. for n-array
 * 
 * Algo Type : BackTracking
 * 
 * Parameters : number of bits
 * Return     : None
 * 
 * Time Complexity : 
 * 
 *        c             if n < 0
 * T(n) = 
 * 	  kT(n-1) + d   otherwise
 * Substraction and Conquer Master Theorem
 * O(k^n)
 *
 *************************************************************/
void BaseKNumber(int n, int base,int size, char A[],bool _set)
{
  static int nCount = 0;
  if(_set) nCount = 0;
  
  if(n < 1)
  {
    printf("%d\t",++nCount);
    PrintArray(A,size,false);
    return;
  }
  else
  {
     for(int i=0;i<base;i++)
     {
	A[n-1] = i + '0';
	BaseKNumber(n-1,base,size,A);
     }
  }
}
/*************************************************************
 * Que 4. Print all the permutations of a given string
 * 
 * Algo type : BackTracking
 * 
 * Time Complexity : n*n!
 * 
 * *************************************************************/
void PrintAllPermutationsOf(char A[], int n,int i)
{
    if(i == n-1)
    {
      static int count = 0;
      printf("%d %s\n",++count,A);
    }
    else
    {
       for(int k=i;k<n;k++)
       {
		  SwapChars(A[i],A[k]);
		  PrintAllPermutationsOf(A,n,i+1);
		  SwapChars(A[i],A[k]);
       }
    }
}
/*************************************************************
 * Que 5. Tug Of War
 * 
 * Given a set of n integers, divide the set in two subsets of 
 * n/2 sizes each such that the difference of the sum of two 
 * subsets is as minimum as possible. If n is even, then sizes 
 * of two subsets must be strictly n/2 and if n is odd, then 
 * size of one subset must be (n-1)/2 and size of other subset 
 * must be (n+1)/2.
 *  For example, let given set be 
 *  {3, 4, 5, -3, 100, 1, 89, 54, 23, 20}, 
 * the size of set is 10. 
 * Output for this set should be 
 * {4, 100, 1, 23, 20} and {3, 5, -3, 89, 54}. 
 * Both output subsets are of size 5 and sum of elements in 
 * both subsets is same (148 and 148).
 * Let us consider another example where n is odd. 
 * Let given set be {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}. 
 * The output subsets should be 
 * {45, -34, 12, 98, -1} and {23, 0, -99, 4, 189, 4}. 
 * The sums of elements in two subsets are 120 and 121 respectively.
 * 
 * 
 * *************************************************************/
void TugOfWar(int A[], int n)
{
  int min_diff = INT_MAX;
   
  bool solution[n];
  bool selectedElements[n];
   
  int totalSum = 0;
  int current_sum = 0;
   
  for(int i=0;i<n;i++)
  {
     totalSum += A[i];
     solution[i] = selectedElements[i] = false;
  }
   
  TugOfWarElements(A,n,totalSum,solution,0,selectedElements,0,0,min_diff);
   
  /* Print Sets */
  int sumA=0;
  int sumB=0;
  for(int i=0;i<n;i++)
  {
     if(solution[i])
     {
       sumA += A[i];
       printf("%d ",A[i]);
     }
  }
  
  printf(": Sum : %d\n",sumA);
  
  for(int i=0;i<n;i++)
  {
     if(!solution[i])
     {
       sumB += A[i];
       printf("%d ",A[i]);
     }
  }
  printf(": Sum : %d\n",sumB);
  
}
void TugOfWarElements(int A[], int n, int totalSum, bool solution[], 
		      int current_element, bool selectedElements[], 
		      int count_of_selected_elements, int current_sum, int& min_diff)
{
    // Reached the end of the array
    if(current_element == n) return;
    
    // checks that the numbers of elements left are not less than the
    // number of elements required to form the solution
    if((n/2 - count_of_selected_elements) > (n - current_element)) return;
    
    //Consider the case when the current element is not selected.
    TugOfWarElements(A,n,totalSum,solution,current_element+1,selectedElements,count_of_selected_elements,current_sum,min_diff);
    
    //Add the element to the solution
    count_of_selected_elements++;
    current_sum += A[current_element];
    selectedElements[current_element] = true;
    
    if(count_of_selected_elements == n/2)
    {
	// checks if the solution formed is better than the best solution so far
        if(abs(totalSum/2 - current_sum) < min_diff)
	{
	    min_diff = abs(totalSum/2 - current_sum);
	    for(int i=0;i<n;i++)
	      solution[i] = selectedElements[i];
	}
    }
    else
    {
       //Still more elements to go
       TugOfWarElements(A,n,totalSum,solution,current_element+1,selectedElements,count_of_selected_elements,current_sum,min_diff);
    }
    
    //Unset the selected flag as a part of back tracking ;)
    selectedElements[current_element] = false;
}
/*************************************************************************
 * Que 6. Subset sum problem is to find subset of elements that are 
 * selected from a given set whose sum adds up to a given number K. 
 * We are considering the set contains non-negative values. It is 
 * assumed that the input set is unique (no duplicates are presented).
 * 
 * Algo Type : BackTracking
 * 
 * **********************************************************************/
void SubSetSum(int A[], int n, int required_sum)
{
    bool selected[n];
    for(int i=0;i<n;i++)
      selected[i] = false;
    int current_element = 0;
    int current_sum = 0;
    
    SubSetSumBackTracking(A,n,required_sum,selected,0,0);
}
void SubSetSumBackTracking(int A[], int n, int required_sum, bool selected[], 
			   int current_sum, int current_element)
{
   //Reached end of the input array
   if(current_element > n-1) return;
   
   //Not selected the element
   SubSetSumBackTracking(A,n,required_sum,selected,current_sum,current_element+1);
   
   //Selected the element
   if(required_sum >= current_sum + A[current_element])
   {
      //Add current element
      current_sum += A[current_element];
      selected[current_element] = true;
      if(current_sum == required_sum)
      {
	  PrintSetElements(A,n,selected);
      }
      else //if(current_sum < required_sum)
      {
	  SubSetSumBackTracking(A,n,required_sum,selected,current_sum,current_element+1);
      }
   }
   selected[current_element] = false;
}
void PrintSetElements(int A[], int n, bool selected[])
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
      if(selected[i])
      {
	sum += A[i];
	printf("%d ",A[i]);
      }
    }
    printf(" SUM(%d)\n",sum);
}
/*************************************************************************
 * Que 7. The N Queen is the problem of placing N chess queens on an N×N 
 * chessboard so that no two queens attack each other
 * 
 * Algo Type : BackTracking
 * 
 * **********************************************************************/

/* This function solves the N Queen problem using Backtracking.  It mainly uses
solveNQUtil() to solve the problem. It returns false if queens cannot be placed,
otherwise return true and prints placement of queens in the form of 1s. Please
note that there may be more than one solutions, this function prints one of the
feasible solutions.*/
bool solveNQ()
{
    int board[N][N] = 
    { 
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
 
    if ( solveNQUtil(board, 0) == false )
    {
      printf("Solution does not exist");
      return false;
    }
 
    printSolution(board);
    return true;
}
/* A utility function to print solution */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
 
/* A utility function to check if a queen can be placed on board[row][col]
   Note that this function is called when "col" queens are already placeed
   in columns from 0 to col -1. So we need to check only left side for
   attacking queens */
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }
 
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
 
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
            return false;
    }
 
    return true;
}
 
/* A recursive utility function to solve N Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
    /* base case: If all queens are placed then return true */
    if (col >= N)
        return true;
 
    /* Consider this column and try placing this queen in all rows
       one by one */
    for (int i = 0; i < N; i++)
    {
        /* Check if queen can be placed on board[i][col] */
        if ( isSafe(board, i, col) )
        {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
 
            /* recur to place rest of the queens */
            if ( solveNQUtil(board, col + 1) == true )
                return true;
 
            /* If placing queen in board[i][col] doesn't lead to a solution
               then remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
        }
    }
 
     /* If queen can not be place in any row in this colum col
        then return false */
    return false;
}
/**************************************************************************************
 * Que 8. A Maze is given as N*N binary matrix of blocks where source block is the 
 * upper left most block i.e., maze[0][0] and destination block is lower rightmost 
 * block i.e., maze[N-1][N-1]. A rat starts from source and has to reach destination. 
 * The rat can move only in two directions: forward and down. In the maze matrix, 0 
 * means the block is dead end and 1 means the block can be used in the path from 
 * source to destination. Note that this is a simple version of the typical Maze problem.
 * For example, a more complex version can be that the rat can move in 4 directions and 
 * a more complex version can be with limited number of moves.
 * 
 * Algo Type : BackTracking (Exhaustic search)
 * 
 * **************************************************************************************/
void SolveMazeProblem(int board[4][4])
{
    int selected[N][N];
    
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
	selected[i][j] = 0;
    
    selected[0][0] = 1;
    if(SolveMazeUntil(board,0,0,selected))
    {
      printSolution(selected);
      return;
    }
    printf("There is no path exists.\n");
}
bool SolveMazeUntil(int board[4][4], int row, int col,int selected[N][N])
{
   //Going outside the board
   if(row >= N-1 && col >= N-1) return true;
      
   //Select Possible Direction 
   //1) Forward move
   if(board[row][col + 1]) 
   {
      selected[row][col+1] = 1;
      
      if(SolveMazeUntil(board,row,col+1,selected))
	return true;
      
      selected[row][col+1] = 0;
   }
   if(board[row+1][col]) 
   {
      selected[row + 1][col] = 1;
      
      if(SolveMazeUntil(board,row+1,col,selected))
	return true;
      
      selected[row + 1][col] = 0;
   }
   
   //No solution exits
   return false;
}
/***********************************************************************************
 * Que 9. Knight’s Tour problem.
 * The knight is placed on the first block of an empty board and, moving according 
 * to the rules of chess, must visit each square exactly once.
 * 
 * Algo type : BackTracking
 * 
 * ********************************************************************************/
bool SolveKnightUntil(int** board, int row, int col, int remainingBlocks,int n,int move)
{
   if(remainingBlocks <= 0 || move >= n*n -1) return true;
   
   
    /* 
       xMove[] and yMove[] define next move of Knight.
       xMove[] is for next value of x coordinate
       yMove[] is for next value of y coordinate 
    */
    
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
   
    for(int i=0;i<8;i++)
    {
      int nRow = row + xMove[i];
      int nCol = col + yMove[i];
      
      if(isSafeMove(board,nRow,nCol,n))
      {
	board[nRow][nCol] = move + 1;
      	if(SolveKnightUntil(board,nRow,nCol,remainingBlocks - 1,n,move + 1))
	  return true;
	board[nRow][nCol] = -1;
      }
    }
   
   //No solution
   return false;
}
bool isSafeMove(int** board, int row, int col,int n)
{
    if(row >= 0 && row < n && col >= 0 && col < n && board[row][col] == -1)
      return true;
    return false;
}
void SolveKnightProblem(int n)
{
    int ** board = new int * [n];
    for(int i=0;i<n;i++)
      board[i] = new int[n];
    
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
	board[i][j] = -1;
   
   board[0][0] = 0;
      
   if(SolveKnightUntil(board,0,0,n*n,n,0))
   {
      PrintBoard(board,n);
      return;
   }
   printf("No solution exits.\n");
}
void PrintBoard(int** board, int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      printf("%d\t",board[i][j]);
    printf("\n");
  }
}
/*******************************************************************************************
 * Que 10. Recursively remove all adjacent duplicates
 * 
 * Given a string, recursively remove adjacent duplicate characters from string. 
 * The output string should not have any adjacent duplicates. See following examples.
 * 
 * Input:  azxxzy 
 * Output: ay
 * First "azxxzy" is reduced to "azzy". The string "azzy" contains duplicates, 
 * so it is further reduced to "ay".
 * 
 * Input: geeksforgeeg
 * Output: gksfor
 * 
 * First "geeksforgeeg" is reduced to "gksforgg". The string "gksforgg" contains 
 * duplicates, so it is further reduced to "gksfor".
 * 
 * Input: caaabbbaacdddd
 * Output: Empty String
 * 
 * Input: acaaabbbacdddd
 * Output: acac
 *******************************************************************************************/
bool RemoveAdjacentDuplicates(char A[])
{
    int len = strlen(A);
    bool returnFlag = false;
    char a,b;
    a = A[0];
    for(int i=1;i<len;i++)
    {
        b = A[i];
        if(a == b)
	{
	   //Remove a and b
	  len = RemoveDuplicates(i-1,A);
	  returnFlag = true;
	  break;
	}
	a = b;
    }
    
    if(returnFlag)
      return RemoveAdjacentDuplicates(A);
    return false;
}
int RemoveDuplicates(int i, char A[])
{
   int len = strlen(A);
   int c = A[i];
   if(i+1 == len-1)
   {
      A[i] = '\0';
   }
   else
   {
      int k;
      for(k=i;A[k] == c && k < len;k++);
      
      for(int j=k; j<len; j++,i++)
      {
		  A[i] = A[j];
      }
	  A[i] = '\0';
   }
}



















