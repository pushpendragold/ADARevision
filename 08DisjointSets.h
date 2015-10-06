#ifndef _H_DISJOINT_H
#define _H_DISJOINT_H
#define DEBUG 1


enum {
  _QUICKFIND,
  _QUICKUNION,
  _QUICKUNION_WEIGHTED
};

class Set {
  
private :
  
  int * array;
  int * size;
  int count;
  int type;
  
public :
  
  Set(int _size,int _type);
 ~Set();
  
 int  Find(int a, int b);
 void Union(int a,int b);
 void PrintArray();
 int  Root(int i);
 void CheckElement(int a,int b);
 int  GetSize(int a);

};

#endif