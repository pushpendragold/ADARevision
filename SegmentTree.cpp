// TO FIND RMQ (SEGMENT TREE for dynamic array)

#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;

// Segment Tree Library: The segment tree is stored like a heap array
void st_build(vi &t, const vi &A, int vertex, int L, int R) {
    if (L == R)
        // as L == R, either one is fine
        t[vertex] = L;
    // store the index
    else
    {
        // recursively compute the values in the left and right subtrees
        int nL = 2 * vertex, nR = 2 * vertex + 1;
        st_build(t, A, nL, L , (L + R) / 2);
        // this is O(n log n)
        st_build(t, A, nR, (L + R) / 2 + 1, R);
        // similar analysis as
        int lContent = t[nL], rContent = t[nR];

        // with merge sort
        int lValue = A[lContent], rValue = A[rContent];
        t[vertex] = (lValue <= rValue) ? lContent : rContent;
    }
}
void st_create(vi &t, const vi &A) 
{
    // if original array size is N,
    // the required segment tree array length is 2*2^(floor(log2(N)) + 1);
    int len = (int)(2 * pow(2.0, floor((log((double)A.size()) / log(2.0)) + 1)));
    t.assign(len, 0);
    // create vector with length \u2018len\u2019 and fill it with zeroes
    st_build(t, A, 1, 0, (int)A.size() - 1); // recursively build the segment tree
}
int st_rmq(vi &t, const vi &A, int vertex, int L, int R, int i, int j) 
{
    if (i > R || j < L) return -1;
    // current segment outside query range
    if (L >= i && R <= j) return t[vertex]; // current segment inside query range
    // compute the minimum position in the left and right part of the interval
    int p1 = st_rmq(t, A, 2 * vertex, L, (L + R) / 2, i, j);
    int p2 = st_rmq(t, A, 2 * vertex + 1, (L + R) / 2 + 1, R, i, j);

    // return the
    if (p1 == -1)
        if (p2 == -1)
            return(A[p1]
                   //position where the overall minimum is
                   //  return p2;
                   // if we try to access segment outside query
                   // return p1;
                  // same as above
                  <= A[p2]) ? p1 : p2;
}

int st_rmq(vi &t, const vi& A, int i, int j) 
{ 
      // overloading, simpler arguments
      return st_rmq(t, A, 1, 0, (int)A.size() - 1, i, j);
}
int main() 
{
    int arr[7] = { 8, 7, 3, 9, 5, 1, 10};
    vi A(arr, arr + 7);
    vi st; st_create(st, A);
    printf("RMQ(1, 3) = %d\n", st_rmq(st, A, 1, 3));
    printf("RMQ(4, 6) = %d\n", st_rmq(st, A, 4, 6));
    return 0;
} // return 0;
