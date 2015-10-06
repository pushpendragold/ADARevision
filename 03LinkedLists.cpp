#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

#include "03LinkedLists.h"
#include "tools.h"

/* Linked List
 * Complexity : O(n)
 */
LL* CreateNode(int data)
{
  LL * temp = (LL *)malloc(sizeof (LL));
  if(temp)
  {
     temp->data = data;
     temp->next = NULL;
  }
  return temp;
}
LL* InsertNodeAtEnd(int data, LL *root)
{
  LL * temp = CreateNode(data);
  if(!temp) 
    return NULL;
  
  if(root == NULL)
    return temp;
  FindLastNode(root)->next = temp;
  return root;
}
LL * InsertNodeAtBegin(int data,LL *root)
{
  LL * temp = CreateNode(data);
  temp->next = root;
  return temp;
}
LL* DeleteLL(LL* root)
{
  LL * nNode = root;
  LL * pNode;
  while(nNode != NULL)
  {
    pNode = nNode;
    nNode = nNode->next;
    free(pNode);
  }
}
LL* DeleteNode(LL* tNode,LL * root)
{
    if(tNode == root)
    {
      free(tNode);
      return NULL;
    }
    
    LL * pNode = root;
    LL * cNode = root;
    while(cNode != tNode)
    {
      pNode = cNode;
      assert(cNode != NULL);
      cNode = cNode->next;
      
    }
    pNode->next = cNode->next;
    free(cNode);
    
    return root;
}


/* Doubly Link List
 * O(n)
 */
DLL* CreateNodeDLL(int data)
{
   DLL * temp = (DLL *)malloc(sizeof(DLL));
   if(!temp)
   {
      temp->data = data;
      temp->prev = temp->next = NULL;
   }
   return temp;
}

/* Circular Link List
 * O(n)
 */
CLL* CreateNodeCLL(int data)
{
  CLL * temp = (CLL *)malloc(sizeof(CLL));
  if(!temp)
  {
    temp->data = data;
    temp->next = temp->prev = NULL;
  }
  return temp;
}

/* Que 1. Implementation of Stack using link list
 * 
 * Time Complexity : O(n)
 */
LLStack::LLStack()
{
  Top = NULL;
}
LLStack::~LLStack()
{

}
bool LLStack::IsEmpty()
{
  return Top == NULL;
}
void LLStack::Push(int data)
{
  LinkList * tmp = new LinkList(data);
  if(IsEmpty())
    Top = tmp;
  tmp->SetNext(Top);
  Top = tmp;
}

int LLStack::Pop()
{
  if(IsEmpty())
    return -1;
  int data = Top->GetData();
  LinkList * tmp = Top->GetNext();
  delete Top;
  Top = tmp;
  printf("Data popped : %d\n",data);
  return data;
}
LLStack::LinkList::LinkList(int data)
{
  this->data = data;
  this->next = NULL;
}
int LLStack::LinkList::GetData()
{
  return data;
}
LLStack::LinkList::~LinkList()
{

}
LLStack::LinkList* LLStack::LinkList::GetNext()
{
  return next;
}
void LLStack::LinkList::SetNext(LLStack::LinkList* nNode)
{
  this->next = nNode;
}
/* Que 3.
 * Reverse Link List
 * 
 * Time Complexity : O(n)
 */
LL * ReverseLL(LL * root)
{
  if(root == NULL)
    return NULL;
  if(root->next == NULL) 
    return root;
  
  LL * first = root;
  LL * rest  = ReverseLL(first->next);
  
  first->next->next = first;
  first->next = NULL;
  
  return rest;
}
/* Que 4.
 * Print nodes in reverse order using recursion
 */
void PrintLLReverse(LL * root)
{
   if(!root)
     return;
   PrintLLReverse(root->next);
   printf("%d\n",root->data);
}

/* Que 5. Find intersection point of two link lists
 *  
 * Algo used : two stacks are used to push all elements of 
 * both the link lists. Both stacks are popped together 
 * When ever popped elements from both stacks are not same 
 * the previously popped element is the insertion point. 
 *  
 * Time Complexity: O(M+N)
 */
int FindIntersection(LL* A, LL* B)
{
    LLStack sA,sB;
    LL * tNode = A;
    for(;tNode!=NULL;tNode=tNode->next)
      sA.Push(tNode->data);
    tNode = B;
    for(;tNode!=NULL;tNode=tNode->next)
      sB.Push(tNode->data);
    
    int ta=0,tb=0;
    while(ta != tb)
    {
      ta = sA.Pop();
      tb = sB.Pop();
    }  
    return ta;
}
/* Que 6. Find the middle node of the given linked list
 * Only using single scan.
 * 
 * Time complexity : O(N)
 */
LL * FindMiddleNode(LL *root)
{
    LL * fast;
    LL * slow;

    fast = slow = root;

    while(fast && slow)
    {
        if(!fast->next)
            break;
        fast = fast->next;
        if(!fast->next)
            break;
	slow = slow->next;
        fast = fast->next;
        if(!fast->next)
            break;
        
    }
    return slow;
}
/* Que 7. Merge two sorted linked list
 * Using single linked list scan.
 * 
 * Time Complexity : O(M + N)
 */
LL * MergeSortedLLists(LL * A, LL * B)
{
  if(!A || !B)
  {
    if(!A)
      return B;
    if(!B)
      return A;
  }
  LL * aNode = A;
  LL * bNode = B;
  LL * tNode = NULL;
  LL * rNode = NULL;
  
  while(aNode && bNode)
  {
    if(aNode->data > bNode->data)
    {
      if(!tNode)
		  rNode = tNode = bNode;
      else
		  tNode->next = bNode;
      tNode = bNode;
      bNode = bNode->next;
    }
    else
    {
      if(!tNode)
		  rNode = tNode = aNode;
      else
		  tNode->next = aNode;
      tNode = aNode;
      aNode = aNode->next;
    }
  }
  if(aNode)
  {
    if(tNode)
     tNode->next = aNode;
    else
     rNode = tNode = aNode;
  }
  else if(bNode)
  {
    if(tNode)
      tNode->next = bNode;
    else
      rNode = tNode = bNode;
  }
  return rNode;
}
/* Que 8. Reverse Linked List in pairs.
 * Using only one scan
 * 
 * Time Complexity : O(N)
 */
LL * ReverseLLinPairs(LL * root)
{
  if(!root)
    return root;
  
  LL * result = root->next;
  LL * cNode  = root;
  LL * tNode  = root;
  LL * pNode  = NULL;
  
  while(cNode && cNode->next)
  {
    if(pNode)
      pNode->next = cNode->next;
    
    pNode = cNode;
    tNode = cNode->next->next;
    cNode->next->next = cNode;
    cNode->next = tNode;
    cNode = tNode;
  }
  return result;
}
/* Que 9. Sort Linked Lists using Merge Sort
 * 
 * Time Complexity : 
 */
LL* MergeSorts(LL* root)
{
   if(!root || !root->next)
     return root;

   LL * mNode = FindMiddleNode(root);
   LL * tNode = mNode->next;

   mNode->next = NULL;

   LL * lNode = MergeSorts(root);
   LL * rNode = MergeSorts(tNode);
   
   return MergeSortedLLists(lNode,rNode);
}
/* Que. 10 Check if the given linked list is palindrome or not
 * 
 * Comment : 1) Calculating number of elements in the linked list
 *           2) Calculating number of elements to be pushed in stack.
 *           3) Half of the elements will be pushed in stack.
 *           4) All elements will be poped if any elements mismatched 
 * 		with the poped elements from remaining elements in linked
 *              list. List is not palindrome otherwise it is.
 * Paramters : root node
 * Returns   : bool (true/false)
 * 
 * Time Complexity : O(n)
 */
bool IsPalindrome(LL *root)
{
    if(!root) 
      return true;
    int  nCount = GetNumberOfNodes(root);
    int  nPush = nCount / 2;
    bool isEven = nCount % 2 == 0 ? true : false;
    LLStack stack;
    while(nPush)
    {
      stack.Push(root->data);
      root = root->next;
      nPush--;
    }
    if(!isEven) //skip one node
      root = root->next;
    
    while(root)
    {
	if(stack.Pop() != root->data)
	  return false;
	root = root->next;
    }
    return true;
}
/* Que 11. For a given K value (K > 0) reverse blocks of K nodes in a list (Modified version of Que.8)
 * Comment : 1) Reverse is only done when there are same or more elements than k given.
 *           2) Calculate new root before entering in the loop
 * 
 * Complexity : O(N)
 */
LL* ReverseLLinKthPairs(LL* root,int k)
{
  //Boundary condition
  if(!root || GetNumberOfNodes(root) < k)
    return root;
  
  LL * result = FindKthNode(root,k);
  LL * cNode  = root;
  LL * tNode  = root;
  LL * pNode  = NULL;
  LL * nNode  = NULL;
  int  T;
  
  while(cNode && GetNumberOfNodes(cNode) >= k)
  {
    if(pNode)
      pNode->next = FindKthNode(cNode,k);
    
    pNode = cNode;
    nNode = FindKthNode(cNode,k+1);
    
    T = k;
    while(T--)
    {
      tNode = cNode->next;
      cNode->next = nNode;
      nNode = cNode;
      cNode = tNode;
    }
  }
  if(cNode)
    pNode->next = cNode;
    
  return result;
}
/* Que 12. Josephus Circle : N people decided to elect a leader by arranging themselves in a circle 
 * and eliminating every M(th) person around the circle, closing ranks as each person drops out.
 * Find which person will be the last one remaining (with rank 1)
 * 
 * Comment(s) : 1) Create Circular linked list having n elements.
 *              2) In each cycle of m elements one element will be eliminated as soon as there is only
 *                 one element left.
 *              3) The last element is the elected leader.
 * 
 * Complexity : O(N*M)
 */
int JoshephusCircle(int n, int m)
{
    LL * root  = NULL;
    LL * tNode = NULL;
    LL * pNode = NULL;
    
    for(int i=1;i<=n;i++)
    {
      if(!root)
	tNode = root = CreateNode(i);
      else
      {
	tNode->next = CreateNode(i);
	tNode = tNode->next;
      }
    }
    //To make circular linked list
    tNode->next = root;
    
    tNode = root;
    while(--n)
    {
      for(int i=0;i<m;i++)
      {
	pNode = tNode;
	tNode = tNode->next;
      }
      pNode->next = tNode->next;
      delete tNode;
      tNode = pNode;
    }
    if(tNode)
    return tNode->data;
    return -1;
}


















