
#include <cstdio>
#include <cstring>
#include <malloc.h>
#include <iostream>
#define MAX 100010

int A[MAX];

using namespace std;
enum TYPE{ ADD = 0,UPDATE };
typedef long long int INT;
typedef struct Node { INT sum,num; int si,ei; Node * right,*left; } Node;

/* segment Tree */
Node * CreateNode();
Node * CreateSegment_Tree(int A[],int si,int ei,INT &sum);
void DeleteTree(Node * node);
INT  Query(Node * node,int si,int ei);
void Update_SegmentTree(Node * node,int si,int ei,int Type,int n_num,INT &sum);
void Traverse(Node * node);

int main()
{
    int T,N,Q,a,b,c,d,aa=0;
    INT sum = 0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&Q);
        for(int i = 0; i < N; ++i)
            scanf("%d",&A[i]);
        sum = 0;
        Node * tree = CreateSegment_Tree(A,0,N-1,sum);
        printf("Case %d:\n",++aa);
        for(int i = 0; i < Q; ++i)
        {
            scanf("%d",&a);
            if( a == 2 ) // print sum
            {
                scanf("%d %d",&b,&c);
                printf("%lld\n",Query(tree,b-1,c-1));
            }
            else if( a == 0 )
            {
                scanf("%d %d %d",&b,&c,&d);
                sum = 0;
                Update_SegmentTree(tree,b-1,c-1,UPDATE,d,sum);
            }
            else
            {
                scanf("%d %d %d",&b,&c,&d);
                sum = 0;
                Update_SegmentTree(tree,b-1,c-1,ADD,d,sum);
            }
        }
        
        DeleteTree(tree);
    }
    return 0;
}
void Traverse(Node * node)
{
	if(node)
	{
        printf("(%d,%d)(%lld,%lld)\n",node->si,node->ei,node->num,node->sum);

        Traverse(node->left);
		Traverse(node->right);
	}

}
void Update_SegmentTree(Node * node,int si,int ei,int Type,int n_num,INT &sum)
{
	if( !node )
	{
		sum = 0;
		return;
	}
	
    
	if((node->si > ei && node->ei > ei) || (node->si < si && node->ei < si) ) 
	{
		sum = node->sum;
		return;
	}
    
	
	if( node->si == node->ei )
	{
        if (node->ei >= si && node->ei <= ei )
        {
            if(Type == ADD)
                node->num += n_num;
            else
                node->num = n_num;
        }
        sum = node->sum = node->num * node->num;
        return;
	}

	INT lSum=0,rSum=0;

	Update_SegmentTree(node->left,si,ei,Type,n_num,lSum);
	Update_SegmentTree(node->right,si,ei,Type,n_num,rSum);

	sum = node->sum = lSum + rSum;
	return;
}

INT Query(Node * node,int si,int ei)
{
    if(!node)
        return 0;

    if( node->si >= si && node->ei <= ei )
        return node->sum;

    return Query(node->left,si,ei) + 
           Query(node->right,si,ei);
}

Node * CreateSegment_Tree(int A[],int si,int ei,INT &sum)
{
    Node * tmp = CreateNode();

    // Boundary case
    if( si == ei )
    {
        tmp->ei = tmp->si = si;
		tmp->num = A[si];
        sum = tmp->sum = A[si] * A[si];
        return tmp;
    }

    // Find Mid
    int mid = ( si + ei ) / 2;
    INT lSum=0,rSum=0;

    // Update indices
    tmp->si = si;
    tmp->ei = ei;
    
    // Update sub trees
    tmp->left  = CreateSegment_Tree(A,si,mid,lSum);
    tmp->right =CreateSegment_Tree(A,mid+1,ei,rSum);

    // Update sum
    sum = tmp->sum = lSum + rSum;
	
    return tmp;
}

void DeleteTree(Node * node)
{
    if(!node)
    {
        DeleteTree(node->left);
        DeleteTree(node->right);
        free(node);
    }
}

Node * CreateNode()
{
    Node * tmp = (Node *)malloc(sizeof(Node));
    tmp->sum = tmp->si = tmp->ei = -1;
    tmp->right = tmp->left = NULL;
    return tmp;
}
