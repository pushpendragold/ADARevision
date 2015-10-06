#ifndef _H_TOOLS_
#define _H_TOOLS_

#include "03LinkedLists.h"

/* Array Utility */
void PrintArray(char A[],int n,bool rightToLeft=true);
void PrintArray(int  A[],int n,bool rightToLeft=true);

/* Linked List */
int  GetNumberOfNodes(LL *root);
LL * FindLastNode(LL *root);
void PrintLL(LL *root);
LL * FindKthNode(LL * root,int k);

/* SWAP */
void SwapChars(char &a,char &b);
void SwapIntergers(int &a,int &b);

/* Min Integer */
int minInteger(int a,int b);
int MAXINT(int a,int b);

#endif