#ifndef _H_QUESTIONS_H_
#define _H_QUESTIONS_H_

#include <string>
using namespace std;

// Que 1. Find all permutations of a given string.
void Permute(char A[]);
void Permute(char A[],int i,int n);
void SwapElement(char &a,char &b);
void print_all_perm4(string s);

//Que 2. Find the first non-repeating character from a stream of characters
// A Dobuly linked list node
#define MAX_CHAR 256
struct node
{
    char a;
    struct node *next, *prev;
};
void removeNode(struct node **head_ref, struct node **tail_ref,struct node *temp);
void appendNode(struct node **head_ref, struct node **tail_ref, char x);
void findFirstNonRepeating();

//Que 3. Find all set possible whose sum is K
int  FindAllSet(int K);
int  FindAllSet_until(int A[],int iA,int K);

//Que 4. Form an array B[] from elements of A[] such that A[i] is product of all 
//other elements except ith element
void PrintBFromA(int A[],int n);
int  ValueOf(int A[],int i,int n);

//Que 5. Print and count all possible subsets of a given set.
int FindSubSet(int A[],int n);
int FindSubSet_until(int A[],int n,int solution[],int indexS,int startIndex,bool found);

//Que 6. Largest sum continous sub array.
int FindContinousLargestSum(int A[],int n);
int FindContinousLargestSum_until(int A[], int n,int currentSum,int low,int high,int current_index);

// Que 7. Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.
// 1. The amount of petrol that petrol pump will give.
// 2. Distance from that petrol pump to the next petrol pump.
// Calculate the first point from where a truck will be able to complete the circle (The truck will stop at 
// each petrol pump and it has infinite capacity). Expected time complexity is O(n). Assume for 1 litre petrol, the truck can go 1 unit of distance.
// For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}. 
// The first point from where truck can make a circular tour is 2nd petrol pump. Output should be start = 1 (index of 2nd petrol pump).

struct circlePos {
    int petrol;
    int dist;
};

int FindStartPoint(circlePos A[],int n);

// Que 8. Maximum value contiguous subsequnce
int MaxSumRec(int A[],int left,int right);
int MaxSubsequnceSum(int A[],int n);

#endif