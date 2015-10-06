#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
typedef vector<int> vi;

vi pset;
// remember: vi is vector<int>
void initSet(int N) { pset.assign(N, 0); for (int i = 0; i < N; i++) pset[i] = i; }
int  findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }

int main()
{
    return 0;
}

