#include <stdio.h>
#include <string.h>
#include <map>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

#include "14Hashing.h"

/* Constructor */
HashTable::HashTable(int size)
{
  tSize = size;
  count = 0;
  hash  = new HashTableNode[size];
  if(!hash)
    printf("Allocation failed\n");
}
/* Destructor */
HashTable::~HashTable()
{

}
/* Print LL (Utility function)*/
void HashTable::PrintLL(HashTable::LLNode* root)
{
  while(root != NULL)
  {
    printf("%d ",root->data);
    root = root->next;
  }
  printf("\n");
}
/* Hash Function.returns module */
int HashTable::Module(int data)
{
  return data % tSize;
}
/* Insert element in Hash Table */
void HashTable::InsertElement(int data)
{
  int key = Module(data);
  LLNode *temp = hash[key].next;
  LLNode *prev = temp;
  if(hash[key].next == NULL)
  {
    hash[key].bCount++;
    hash[key].next = new LLNode(key,data);
    printf("Data inserted : %d\n",hash[key].next->data);
    return;
  }
  else
  {
    hash[key].bCount++;
    while(temp != NULL)
    {
      if(temp->data == data)
      {
	printf("Element already present in HashTable : %d\n",data);
	return;
      }
      prev = temp;
      temp = temp->next;
    }
    prev->next = new LLNode(key,data);
    printf("Data inserted : %d\n",prev->data);
    //PrintLL(hash[key].next);
  }
}
/* Search element in Hash Table */
int HashTable::SearchElement(int data)
{
  int key = Module(data);
  LLNode * temp = hash[key].next;
  while(temp != NULL)
  {
    if(temp->data == data)
      return 1;
    temp = temp->next;
  }
  return 0;
}
/*Delete Element*/
void HashTable::DeleteElement(int data)
{
  int key = Module(data);
  LLNode * temp = hash[key].next;
  LLNode * prev = temp;
  if(temp == NULL)
  {
    printf("Element not present in HashTable.\n");
    return;
  }
  while(temp != NULL)
  {
    if(temp->data == data)
    {
      prev = temp->next;
      delete temp;
      printf("Element Deleted\n");
      return;
    }
    prev = temp;
    temp = temp->next;
  }
  printf("Element not present in HashTable.\n");
  return;
}

/* Que 4. Given an array of characters, give an algorithm for removing the duplicates. 
 * Changing Module function to operate with character array.
 * 
 * Time Complexity : O(n)
 */ 
int StringHash::Module(int data)
{
    return data - 'a';
}

void RemoveDuplicates(char A[],int size)
{
  StringHash str(26); //Assuming all alphabates 
  int first,last;
  first = last = 0;
  for(int i=0;i<size; i++)
  {
    if(!str.SearchElement(A[i]))
    {
      str.InsertElement(A[i]);
      A[first++] = A[last++];
    }
    else
    {
      last++;
    }
  }
  A[first] = '\0';
}

/* Que 8. Given a list of numbers pairs. If pair(i,j) exist, and pair (j,i) exit report all such
 * pairs. For example {1,3},{2,5},{3,1} -> report the pair when encounters {3,1}.
 * 
 * Time Complexity : O(n)
 */

void PairHash::InsertElement(int key,int data)
{
  if(SearchElement(data,key))
  {
    printf(" {%d,%d} ",key,data);
    return;
  }
  
  LLNode *temp = hash[key].next;
  LLNode *prev = temp;
  if(hash[key].next == NULL)
  {
    hash[key].bCount++;
    hash[key].next = new LLNode(key,data);
    printf("Data inserted : %d\n",hash[key].next->data);
    return;
  }
  else
  {
    hash[key].bCount++;
    while(temp != NULL)
    {
      if(temp->data == data)
      {
	printf("Element already present in HashTable : %d\n",data);
	return;
      }
      prev = temp;
      temp = temp->next;
    }
    prev->next = new LLNode(key,data);
    printf("Data inserted : %d\n",prev->data);
    //PrintLL(hash[key].next);
  }
}
int PairHash::SearchElement(int key,int data)
{
  LLNode * temp = hash[key].next;
  while(temp != NULL)
  {
    if(temp->data == data)
      return 1;
    temp = temp->next;
  }
  return 0;
}
typedef struct Data {
	int i; int j;
} Data;

void ChainingHash()
{
		int A[] = { 4,5,-2,2,-1,1,4 };
		int n = sizeof(A)/sizeof(A[0]);
		map<int,vector<Data> > hash;
		for(int i = 0; i < n;i++)
		{
				for(int j = i+1; j < n; j++)
				{
						int k = A[i] + A[j];
						Data d; d.i = i; d.j = j;
						hash[k].push_back(d);
				}
	 }

	 for( int i = 0; i < hash[0].size(); i++ )
	 {
		 cout<<hash[0][i].i<<" "<<hash[0][i].j<<endl;
	 }
}
