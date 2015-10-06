#ifndef _H_HASHING_H
#define _H_HASHING_H

class HashTable {
  
public:

  class LLNode
  {
    public:
      int key;                    //Hashtable Key
      int data;                   //Hashtable data
      LLNode * next;
      LLNode(int _key,int _data)
      {
	key = _key;
	data = _data;
	next = NULL;
      }
  };

  class HashTableNode
  {
   public:
      int    bCount;              //LLNode's count after chaining
      LLNode  *next;
      HashTableNode()
      {
	bCount = 0;
	next = NULL;
      }
  };
  HashTableNode *hash;            //Array of HashTableNode pointers
  
  int tSize;                      //Total Hash table nodes
  int count;                      //Total elements in Hash Table
  
  virtual int Module(int data);   //Hash function
  
  void PrintLL(LLNode *root);
  
  HashTable(int size);
 ~HashTable();
  
  virtual void InsertElement(int data);
  virtual int  SearchElement(int data);
  virtual void DeleteElement(int data);
  
};

/* Que 4. Given an array of characters, give an algorithm for removing the duplicates. */

class StringHash : public HashTable
{
  virtual int Module(int data);

public:
    StringHash(int size):HashTable(size){};
};
void RemoveDuplicates(char A[],int size);

/* Que 8. Given a list of numbers pairs. If pair(i,j) exist, and pair (j,i) exit report all such
 * pairs. For example {1,3},{2,5},{3,1} -> report the pair when encounters {3,1}.
 */
class PairHash : public HashTable
{
public: 
  virtual void InsertElement(int key,int data);
  virtual int  SearchElement(int key,int data);
  
public :
  PairHash(int size):HashTable(size){};
};

/* Chaining in Hash table STL */
void ChainingHash();


#endif