#include <cstdio>
#include <limits.h>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cmath>
#include <set>

#include "18SegmentTree.h"

using namespace std;

#define DEBUG 1
typedef long long int INT;

SegmentTree::SegmentTree(int A_[],int n)
{
	// Allocate memory 

	// Size of the segment tree
	size = (int)(ceil(log2(n)));     // height of the segment tree
	size = 2 * (int)pow(2,size) - 1; // Max size of segment tree

	A = new int[size]; // Allocate memory

	// Construct segment tree
	ConstructSegmentTree(A_,0,n-1,0);
}

SegmentTree::~SegmentTree()
{
	delete [] A;
}

// Construct Segment tree
int SegmentTree::ConstructSegmentTree( int A_[],int start,int end, int segment_index )
{
	// If there is one element in array, store it in current node of
    // segment tree and return
    if (start == end)
    {
        A[segment_index] = A_[start];
        return A_[start];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    int mid = GetMid(start, end);

    A[segment_index] =  GetMinVal( ConstructSegmentTree(A_, start, mid, segment_index * 2 + 1),
                                   ConstructSegmentTree(A_, mid+1, end, segment_index * 2 + 2));
	
	// Return the current segment tree element
	return A[segment_index];
}

/*  A recursive function to get the minimum value in a given range of array
    indexes. The following are parameters for this function.
 
	index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
int SegmentTree::RMQUtil(int start, int end, int qStart, int qEnd, int index)
{
    // If segment of this node is a part of given range, then return the
    // min of the segment
    if (qStart <= start && qEnd >= end)
        return A[index];
 
    // If segment of this node is outside the given range
    if (end < qStart || start > qEnd)
        return INT_MAX;
 
    // If a part of this segment overlaps with the given range
    int mid = GetMid(start, end);
    return GetMinVal(RMQUtil( start, mid, qStart, qEnd, 2*index+1),
                  RMQUtil( mid+1, end, qStart, qEnd, 2*index+2));
}
 
// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int SegmentTree::RMQ(int n, int qStart, int qEnd)
{
    // Check for erroneous input values
    if (qStart < 0 || qEnd > n-1 || qStart > qEnd)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return RMQUtil(0, n-1, qStart, qEnd, 0);
}

/********************************************************************** **************
 Que 1. Segment tree application to find mininum number between given index range
 Time Complexity  : 
 Space Complexity :
*************************************************************************************/




