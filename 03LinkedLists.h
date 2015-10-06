#ifndef _H_LINKEDLIST_
#define _H_LINKEDLIST_

/* Linked List structure */
typedef struct LL{
  int data;
  struct LL * next;
}LL;

LL * CreateNode(int data);
LL * InsertNodeAtEnd(int data, LL *root);
LL * InsertNodeAtBegin(int data,LL *root);
LL * ReverseLL(LL * root);
void PrintLLReverse(LL * root);
LL* DeleteNode(LL* tNode,LL * root);

LL * DeleteLL(LL *root);

// Que. 5 Find intersection of two link list
// Implemented for value can be changed stack structure
// To return Link List node address
int FindIntersection(LL *A,LL *B);
// Que. 6 Find the middle element of the linked list
// In single scan.
LL * FindMiddleNode(LL * root);
// Que. 7 Merge two sorted linked list.
LL * MergeSortedLLists(LL * A, LL * B);
// Que. 8 Reverse Linked list in pairs
LL * ReverseLLinPairs(LL * root);
// Que. 9 Sort Linked List using merge sort
LL * MergeLists(LL * A, LL * B);
LL * MergeSorts(LL * root);
// Que. 10 Check if the given linked list is palindrome or not
bool IsPalindrome(LL *root);
// Que. 11 Reverse Linked list in k-pairs
LL * ReverseLLinKthPairs(LL * root,int k);
// Que. 12 Joshephus Circle
int  JoshephusCircle(int n,int m);


/* Doubly Link List */
typedef struct DLL{
  int data;
  struct DLL * next;
  struct DLL * prev;
}DLL;

DLL * CreateNodeDLL(int data);

/* Circular Link List */
typedef struct CLL{
  int data;
  struct CLL * next;
  struct CLL * prev;
}CLL;

CLL * CreateNodeCLL(int data);

//Que 1. Implementation of Stack using link list
class LLStack{
  
class LinkList{
private :
  int data;
  LinkList * next;
public :
  LinkList(int data);
 ~LinkList();
  int GetData();
  void SetNext(LinkList * nNode);
  LinkList * GetNext();
}; 
private : 
  LinkList * Top;
public :
  LLStack();
 ~LLStack();
  bool IsEmpty();
  void Push(int data);
  int  Pop();
};

#endif