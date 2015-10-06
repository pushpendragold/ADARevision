#ifndef _H_GRAPH_ALGO_
#define _H_GRAPH_ALGO_

#include <vector>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

// UnWeighted Graph
class Graph 
{
  
protected :

  int v;
  int e;
  bool directed; 
  list< int > *Adj;

private :

   

public:

	// Initalize Graph
	void InItGraph(int A[],int B[],int nEges);
	void AddEdge(int v,int u);

	// DFS
	void DFSTraversal();
	void DFS(int u,vector<bool> &visited);

	// BFS
	void BFSTraversal();
	void BFS(int u, vector<bool> &visited);

	// Topological search
	void TopologicalSort();
	void TopologicalSort_until(int u,vector<bool> &visited, stack<int> &Stack);

	// Sortest path in unweighted graph
	void UnWeightedSorted_Path(int u);

	Graph(int vertices,bool isDirected = false);
   ~Graph();
	
    // Que 1: To check whether there is path between two vertices in a given graph
    bool IsConnected(int source,int destination);

	// Que 2: To count number of paths between given nodes
	int  CountNumberOfPaths(int source,int destination);
	void CountNumberOfPaths_until(int source,int destination,vector<bool> &visited, int &count);

	// Que 3. Articulation point
	// Articulation point is the vertices which iff removed will divides graphs in two different graphs
	void AP();
	void APUtil(int u,bool visited[],int disc[],int low[], int   parent[], bool ap[]);

	// Que 4. Bridge in Graph
	// iff Bridge in graph is removed there will be two different graphs
	void bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[]);
	void bridge();

	// Que 5. Eulerian path circuit and path
	bool isConnected();
	void DFSUtil(int v, bool visited[]);
	int  isEulerian();

	// Que 6. Find cycle in the graph
	bool isCyclic();
	bool isCyclic_until(int u, bool visited[], bool recStack[]);

	// utility Functions
	
	bool hasEdge(int u,int v); // To check if u is directly connected to v
};

typedef struct Data {
	int vertex;
	int weight;
}Data;

class GraphWeighted : public Graph
{
	private:
		list< Data > *AdjWeight;

	public:

		// Constructor / Distructor
		GraphWeighted(int vertices,bool isDirected = false);
	    virtual ~GraphWeighted();

		// Overiding AddEdge 
		virtual void AddEdge(int v,int u,int weight);

		// Dijkstra
		void Dijkstra(int start);
		int minDistance(int dist[], bool visited[]);
		
		// Bellman - Ford Algorithm ( Shortest path with -ve edges )
		void BellmanFord(int start);

		// Spanning Tree

		// Hamilton Path
		bool HamiltonCycle();
		bool HamiltonCycle_until(int path[],int curPos, bool visited[]);


};

#endif