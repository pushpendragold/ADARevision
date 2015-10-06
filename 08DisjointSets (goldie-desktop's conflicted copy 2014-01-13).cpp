#include <stdio.h>
#include <string.h>

#include "08DisjointSets.h"

int Set::Root(int i)
{
  if(type == _QUICKUNION)
  {
    while(i != array[i])
      i = array[i];
    return i;
  } // Quick Union
  else if(type == _QUICKUNION_WEIGHTED)
  {
    while(i != array[i])
    {
      array[i] = array[array[i]];
      i = array[i];
    }
    return i;
  }  
  return -1;
}

void Set::CheckElement(int a, int b)
{
  if(Find(a,b))
     printf("%d and %d are of same set.\n",a,b);
  else
     printf("%d and %d are of different set.\n",a,b);
}


void Set::Union(int a, int b)
{
  if(DEBUG)
    printf("Union %d %d\n",a,b);
  if(type == _QUICKFIND)
  {
    if(!Find(a,b))
    {
      int min = array[a] < array[b] ? array[a] : array[b];
      int max = array[a] < array[b] ? array[b] : array[a];
       //Union
      for(int i=0;i<count;i++)
      {
	if(array[i] == max)
	  array[i] = min;
      }
    }
  } //Quick Find
  else if(type == _QUICKUNION)
  {
    if(!Find(a,b))
    {
      int i = Root(a);
      int j = Root(b);
      array[i] = j;
    }
  }
  else if(type == _QUICKUNION_WEIGHTED)
  {
    if(!Find(a,b))
    {
      int i = Root(a);
      int j = Root(b);
      if(size[i] < size[j]) 
      {
	array[i] = j;
	size[j] += size[i];
	
      }
      else
      {
	array[i] = j;
	size[i]+=size[j];
      }
    }
  }
  if(DEBUG)
    PrintArray();
}

int Set::Find(int a, int b)
{
  if(type == _QUICKFIND)
  {
    return array[a] == array[b];
  }
  if(type == _QUICKUNION || type == _QUICKUNION_WEIGHTED)
  {
    return Root(a) == Root(b);
  }
}

void Set::PrintArray()
{
  if(type == _QUICKFIND || type == _QUICKUNION)
  {
    for(int i=0; i<count; i++)
      printf("%d ",i);
    printf("\n");
    for(int i=0; i<count; i++)
      printf("%d ",array[i]);
    printf("\n");
  }
  else if(type == _QUICKUNION_WEIGHTED)
  {
    for(int i=0; i<count; i++)
      printf("%d ",i);
    printf("\n");
    for(int i=0; i<count; i++)
      printf("%d ",array[i]);
    printf("\n");
    for(int i=0; i<count; i++)
      printf("%d ",size[i]);
    printf("\n");
  }
}

Set::Set(int _size, int _type)
{
  count = _size;
  type = _type;
  if(type == _QUICKFIND || type == _QUICKUNION)
  {
    array = new int[_size];
    
    for(int i=0; i<count; i++)
      array[i] = i;
    
    size  = NULL;
  }
  else if(type == _QUICKUNION_WEIGHTED)
  {
     array = new int[_size];
     size  = new int[_size];
    
     for(int i=0; i<count; i++)
     {
	array[i] = i;
	size[i]  = 1;
     }
   }
}

Set::~Set()
{
  if(array)
  delete [] array;
  if(size)
  delete  [] size;
}
