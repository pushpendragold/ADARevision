#ifndef _H_Recursion_
#define _H_Recursion_
#include <sys/select.h>

// Recursion and back tracking Questions

/* Que.1 Tower of hanoi problem */
void TowerOfHanoi(int n,char A,char B,char aux,bool _set);

/* Que.2 All combination of binary number */
void BinaryNumber(int n,int size,char A[],bool _set=false);
void PrintArray(char A,int size);

/* Que.3 All numbers of base k number for n bits */
void BaseKNumber(int n, int base,int size, char A[],bool _set=false);

/* Que 4. Find all the permutation of given string */
void PrintAllPermutationsOf(char A[],int n,int i);

/* Que 5. Tug Of war */
void TugOfWar(int A[],int n);
void TugOfWarElements(int A[],int n,int totalSum,bool solution[],int current_element,
		      bool selectedElements[],int count_of_selected_elements,int current_sum,
		      int & min_diff);

/* Que 6. Subset sum */
void SubSetSum(int A[],int n,int required_sum);
void SubSetSumBackTracking(int A[],int n,int required_sum, bool selected[],int current_sum,int current_element);
void PrintSetElements(int A[],int n,bool selected[]);

/* Que 7. N Queen Problem */
#define N 4
bool solveNQ();
void printSolution(int board[N][N]);
bool isSafe(int board[N][N], int row, int col);
bool solveNQUtil(int board[N][N], int col);

/* Que 8. Rat in a maze problem */
void SolveMazeProblem(int board[N][N]);
bool SolveMazeUntil(int board[N][N],int row,int col,int selected[N][N]);

/* Que 9. Knight's tour problem */
bool isSafeMove(int ** board,int row,int col,int n);
void SolveKnightProblem(int n);
bool SolveKnightUntil(int **board,int row,int col,int remainingBlocks,int n,int move);
void PrintBoard(int **board,int n);

/* Que 10. Recursively remove all adjacent duplicates */
bool RemoveAdjacentDuplicates(char A[]);
int  RemoveDuplicates(int i,char A[]);


#endif