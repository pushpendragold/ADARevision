#include <stdio.h>
#include <string.h>
#include "tools.h"

#include "03LinkedLists.h"

void PrintArray(char A[], int n, bool rightToLeft)
{
  if(rightToLeft)
  {
      for(int i=0;i<n;i++)
	printf("%c",A[i]);
      printf("\n");
  }
  else
  {
      for(int i=n-1;i>=0;i--)
	printf("%c",A[i]);
      printf("\n");
  }
}
void PrintArray(int A[], int n, bool rightToLeft)
{
  if(rightToLeft)
  {
      for(int i=0;i<n;i++)
	printf("%d ",A[i]);
      printf("\n");
  }
  else
  {
      for(int i=n-1;i>=0;i--)
	printf("%d",A[i]);
      printf("\n");
  }
}
int GetNumberOfNodes(LL* root)
{
   int cNodes = 0;
   while(root)
   {
      cNodes++;
      root = root->next;
   }
   return cNodes;
}
void PrintLL(LL *root)
{
  LL * nNode = root;
  while(nNode != NULL)
  {
    printf("%d ",nNode->data);
    nNode = nNode->next;
  }
  printf("\n");
}
LL * FindLastNode(LL *root)
{
   LL * nNode = root;
   while(nNode->next != NULL)
     nNode = nNode->next;
   return nNode;
}
LL* FindKthNode(LL* root, int k)
{
  k--;
  while(root && k != 0)
  {
    root  = root->next;
    k--;
  }
  return root;
}
void SwapChars(char& a, char& b)
{
   char t = a;
   a = b;
   b = t;
}
void SwapIntergers(int& a, int& b)
{
   int temp = a;
   a = b;
   b = temp;
}

int minInteger(int a,int b)
{
  return a < b ? a : b;
}
int MAXINT(int a, int b)
{
  return a < b  ? b : a;
}
