#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

#include "03LinkedLists.h" 
#include "tools.h"

#include "22Questions.h"

using namespace std;

/**************************************************************************************
 * Que 1. Find all the perumation of a given string.
 * 
 * Comments : Using back tracking
 * 
 * Time Complexity : O(N * N!)
 * Space Complexity: O(N) Recursion
 * 
 * ***********************************************************************************/
void Permute(char A[])
{
    Permute(A,0,strlen(A) - 1);
}
void Permute(char A[], int i, int n)
{
    if(i == n)
      printf("%s\n",A);
    else
    {
      for(int k=i;k<=n;k++)
      {
		  SwapElement(A[i],A[k]);
		  Permute(A,i+1,n);
		  SwapElement(A[i],A[k]);
      }
    }
}
void SwapElement(char& a, char& b)
{
   char temp = a;
   a = b;
   b = temp;
}
void print_all_perm4(string s)
{
  int num_perm = 1, i, j, len = s.length();
 
  for (i = 1; i <= len; i++) num_perm *=i;
   
  for (i = 0; i < num_perm; i++){
    string p = s;
    string one_perm;
 
    int dv = num_perm;
    int num = i;
    for (j = len; j > 0;  j--){
      int index = num % j;
      one_perm.push_back( p[index] );
      p.erase(index, 1);
      num /= j;       
    }
    cout << one_perm << endl;
  }
}
/***********************************************************************************
 * Que 2. Find the first non-repeating character from a stream of characters 
 * Given a stream of characters, find the first non-repeating character from 
 * stream. You need to tell the first non-repeating character in O(1) time 
 * at any moment.
 * 
 * Algo type : Adhoc
 * 
 * Comments  : 
 * 1) Create an empty DLL. Also create two arrays inDLL[] and repeated[] of 
 * size 256.inDLL is an array of pointers to DLL nodes. repeated[] is a 
 * boolean array,repeated[x] is true if x is repeated two or more times, 
 * otherwise false.inDLL[x] contains pointer to a DLL node if character x 
 * is present in DLL,otherwise NULL. 
 * 2) Initialize all entries of inDLL[] as NULL and repeated[] as false.
 * 3) To get the first non-repeating character, return character at head of DLL.
 * 4) Following are steps to process a new character 'x' in stream.
 *   a) If repeated[x] is true, ignore this character (x is already repeated two
 *      or more times in the stream) 
 *   b) If repeated[x] is false and inDLL[x] is NULL (x is seen first time)
 *      Append x to DLL and store address of new DLL node in inDLL[x].
 *   c) If repeated[x] is false and inDLL[x] is not NULL (x is seen second time)
 *      Get DLL node of x using inDLL[x] and remove the node. Also, mark inDLL[x] 
 *      as NULL and repeated[x] as true.
 * 
 * ***********************************************************************************/
// A utility function to append a character x at the end of DLL.
// Note that the function may change head and tail pointers, that
// is why pointers to these pointers are passed.
void appendNode(struct node **head_ref, struct node **tail_ref, char x)
{
    struct node *temp = new node;
    temp->a = x;
    temp->prev = temp->next = NULL;
 
    if (*head_ref == NULL)
    {
        *head_ref = *tail_ref = temp;
        return;
    }
    (*tail_ref)->next = temp;
    temp->prev = *tail_ref;
    *tail_ref = temp;
}
 
// A utility function to remove a node 'temp' fromt DLL. Note that the
// function may change head and tail pointers, that is why pointers to
// these pointers are passed.
void removeNode(struct node **head_ref, struct node **tail_ref,struct node *temp)
{
    if (*head_ref == NULL)
        return;
 
    if (*head_ref == temp)
        *head_ref = (*head_ref)->next;
    if (*tail_ref == temp)
        *tail_ref = (*tail_ref)->prev;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
 
    delete(temp);
}
 
void findFirstNonRepeating()
{
    // inDLL[x] contains pointer to a DLL node if x is present in DLL.
    // If x is not present, then inDLL[x] is NULL
    struct node *inDLL[MAX_CHAR];
 
    // repeated[x] is true if x is repeated two or more times. If x is
    // not seen so far or x is seen only once. then repeated[x] is false
    bool repeated[MAX_CHAR];
 
    // Initialize the above two arrays
    struct node *head = NULL, *tail = NULL;
    for (int i = 0; i < MAX_CHAR; i++)
    {
        inDLL[i] = NULL;
        repeated[i] = false;
    }
 
    // Let us consider following stream and see the process
    char stream[] = "geeksforgeeksandgeeksquizfor";
    for (int i = 0; stream[i]; i++)
    {
        char x = stream[i];
        cout << "Reading " << x << " from stream \n";
 
        // We process this character only if it has not occurred or occurred
        // only once. repeated[x] is true if x is repeated twice or more.s
        if (!repeated[x])
        {
            // If the character is not in DLL, then add this at the end of DLL.
            if (inDLL[x] == NULL)
            {
                appendNode(&head, &tail, stream[i]);
                inDLL[x] = tail;
            }
            else // Otherwise remove this caharacter from DLL
            {
                removeNode(&head, &tail, inDLL[x]);
                inDLL[x] = NULL;
                repeated[x] = true;  // Also mark it as repeated
            }
        }
 
        // Print the current first non-repeating character from stream
        if (head != NULL)
            cout << "First non-repeating character so far is " << head->a << endl;
    }
}
/*********************************************************************
 * Que 3. Find all the sets with the sum K.
 * 
 * Algo Type : BackTracking
 * 
 *********************************************************************/
int FindAllSet(int K)
{
    int A[100];
    int iA = 0;
    
    return FindAllSet_until(A,iA,K);
}
int FindAllSet_until(int A[],int iA,int K)
{
   if(K == 0)
   {
     for(int i=0;i<iA;i++)
       printf("%d ",A[i]);
     printf("\n");
     return 1;
   }
   else
   {
       int temp = 0;
       for(int i=1;i<=K;i++)
       {
	  if(iA > 0) //To avoid repeated sets
	  {
	    if(A[iA - 1] > i) 
	      continue;
	  }
	  A[iA] = i;
	  if(K - i >= 0)
	    temp += FindAllSet_until(A,iA+1,K-i); 
       }
       return temp;
   }
}
/**********************************************************************************
 * Que 4. Form an array B[] from elements of A[] such that A[i] is product of all 
 * other elements except ith element
 * 
 * Algo Type : Adhoc
 * 
 * ********************************************************************************/
void PrintBFromA(int A[], int n)
{
    int B[n];
    for(int i = 0;i<n;i++)
    {
      B[i] = ValueOf(A,i,n);
      printf("%d ",B[i]);
    }
    printf("\n");
}
int ValueOf(int A[], int i,int n)
{
    int pro = 1;
    for(int j=0;j<n; j++)
      if(i != j) pro *= A[j];
    return pro;
}
/*******************************************************************************************
 * Que 5. Print all the subsets of a given set and count subsets.
 * 
 * Comments : Assumption all elements are not identical.
 * Algo Type : Exhaustic search (BackTracking)
 *  
 * Time Complexity : O(2^n)
 * 
 * *****************************************************************************************/
int FindSubSet(int A[], int n)
{
    int solution[n];
    return FindSubSet_until(A,n,solution,0,0,false);
}
int FindSubSet_until(int A[], int n, int solution[], int indexS,int startIndex,bool found)
{
    if(indexS > n) return 0;
    
    int tCount = 0;
    
    if(found)
    {
       for(int i=0;i<indexS;i++)
           printf("%d ",solution[i]);
       printf("\n");
       tCount++;
    }
    
    for(int i=startIndex;i<n;i++)
    {
        //Element selected
      	solution[indexS] = A[i];
        tCount += FindSubSet_until(A,n,solution,indexS + 1,i+1,true);
    }
    return tCount;
}
/*******************************************************************************************
 * Que 6. Largest sum continous sub array.
 * 
 * 
 * *****************************************************************************************/
int FindContinousLargestSum(int A[], int n)
{
    if(n <= 0) return -1;
    return FindContinousLargestSum_until(A,n,A[0],0,n-1,0);
}
int FindContinousLargestSum_until(int A[], int n, int currentSum, 
				  int low, int high,int current_index)
{
   
}
/***************************************************************************************************************************************************
 * Que 7. Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data. 
 *  
 * 1. The amount of petrol that petrol pump will give.
 * 2. Distance from that petrol pump to the next petrol pump.
 * Calculate the first point from where a truck will be able to complete the circle (The truck will stop at 
 * each petrol pump and it has infinite capacity). Expected time complexity is O(n). Assume for 1 litre petrol, the truck can go 1 unit of distance.
 * For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}. 
 * The first point from where truck can make a circular tour is 2nd petrol pump. Output should be start = 1 (index of 2nd petrol pump). 
 *  
 ****************************************************************************************************************************************************/
int FindStartPoint(circlePos A[],int n)
{
    //Boundary condition
    if (n <= 0) return 0;

    return 0;
    
}

// Que 8. Maximum value contiguous subsequnce
int MaxSumRec(int A[],int left,int right)
{
	int maxLeftBorderSum = 0;
	int maxRightBorderSum = 0;
	int LeftBorderSum = 0;
	int RightBorderSum = 0;

	int mid = left + (right - left)/ 2;
	if(left == right) 
	{
		//  Base Case
		return A[left] > 0 ? A[left] : 0;
	}

	int MaxLeftSum  = MaxSumRec(A,left,mid);
	int MaxRightSum = MaxSumRec(A,mid+1,right);

	for(int i = 0; i >= left; i++) 
	{
		LeftBorderSum += A[i];
		if( LeftBorderSum > maxLeftBorderSum ) 
		{
			maxLeftBorderSum = LeftBorderSum;
		}
	}
	for(int j = mid + 1; j <= right; j++) 
	{
		RightBorderSum += A[j];
		if( RightBorderSum < maxRightBorderSum ) 
			maxRightBorderSum = RightBorderSum;
	}
	return max( MaxLeftSum, max(MaxRightSum, maxLeftBorderSum + maxRightBorderSum ));
}
int MaxSubsequnceSum(int A[],int n)
{
	return n > 0 ? MaxSumRec(A,0,n-1) : 0;
}
