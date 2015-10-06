#ifndef _H_SEGMENT_TREE_
#define _H_SEGMENT_TREE_

class SegmentTree
{
	private : 
		int * A;
		int size; 

		int GetMinVal(int a,int b) { return a > b ? b : a; }
		int GetMid(int a,int b){ return a + (b - a)/2; }

		int ConstructSegmentTree( int A_[],int start,int end, int segment_index );
		int RMQUtil(int start, int end, int qStart, int qEnd, int index);

	public:
		SegmentTree(int _A[],int n);
	   ~SegmentTree();

	   int RMQ(int n, int qStart, int qEnd);

};

#endif
