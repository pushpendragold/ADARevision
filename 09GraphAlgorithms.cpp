#include <cstdio>
#include <climits>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <list>
#include <cmath>
#include <set>

#include "09GraphAlgorithms.h"

using namespace std;

Graph::Graph(int vertices,bool isDirected)
{
		v = vertices;
		e = 0;
		directed = isDirected;
		
		// Resize adjancy matrix
		Adj = new list< int > [v];
}
Graph::~Graph()
{
	for(int i = 0; i < v; i++) 
		Adj[i].clear();
}

void Graph::AddEdge(int v,int u)
{
	Adj[ v - 1 ].push_back(u - 1);
	e++;

	if(!directed) 
		Adj[ u - 1 ].push_back(v - 1);
}

// Init Graph
// Parameters : Edges between A[] and B[]
void Graph::InItGraph(int A[],int B[],int nEdges)
{
	for(int i = 0 ; i < nEdges ; i++ ) 
		AddEdge(A[i] - 1, B[i] - 1);
}

/********************************************************* 
 * DFS : 
 *********************************************************/
void Graph::DFS(int u,vector<bool> &visited)
{
	visited[u] = 1;

	printf(" %d",u);
	for( list<int>::iterator i = Adj[u].begin() ; i != Adj[u].end(); i++ ) 
	{
		if( !visited[ *i ] )
			DFS(*i,visited);
	}
}
void Graph::DFSTraversal()
{
	vector< bool > visited;
	visited.resize(v);

	printf("DFS : ");

	for(int i = 0; i < v; i++) 
	{
		if( !visited[i] ) 
			DFS(i,visited);
	}
	printf("\n");
}
/********************************************************* 
 * BFS : 
 *********************************************************/
void Graph::BFSTraversal()
{
	vector< bool > visited;
	visited.resize(v);

	printf("BFS : ");

	for(int i = 0; i < v; i++) 
		if(!visited[i]) 
			BFS(i,visited);

	printf("\n");
}
void Graph::BFS(int u, vector<bool> &visited)
{
	visited[ u ] = 1;
	printf(" %d",u);

	queue < int > Q;
	Q.push(u);

	while(! Q.empty() ) 
	{
		u = Q.front();
		Q.pop();

		if( !visited[ u ] ) 
		{
			visited[ u ] = 1;
			printf(" %d",u);
		}

		for( list<int>::iterator i = Adj[u].begin() ; i != Adj[u].end(); i++ ) 
		{
			if( !visited[ *i ] ) 
				Q.push(*i);
		}
	}
}

/********************************************************* 
 * Topological Sort :
 *********************************************************/
void Graph::TopologicalSort()
{
	vector<bool> visited;
	visited.resize(v);

	stack<int> Stack;

	for(int i = 0; i < v; i++) 
	{
		if(!visited[i]) 
			TopologicalSort_until(i,visited,Stack);
	}

	cout<<"Topological Sort : ";
	while(!Stack.empty()) 
	{
		cout<<" "<<Stack.top();
		Stack.pop();
	}
	cout<<endl;
}
void Graph::TopologicalSort_until(int u,vector<bool> &visited, stack<int> &Stack)
{
	visited[ u ] = true;

	for( list<int>::iterator i = Adj[u].begin(); i != Adj[u].end(); i++) 
	{
		if(!visited[((int)*i)]) 
			TopologicalSort_until(*i,visited,Stack);
	}

	// All adjucent vertices visited now we can push the vertex safely.
	Stack.push(u);
}
/********************************************************* 
 * UnWeighted Graph Sortest path :
 *********************************************************/
void Graph::UnWeightedSorted_Path(int start)
{
	queue<int> Q;
	int f;

	vector<int> Distance;
	Distance.resize(v);

	for(int i = 0; i < v; i++) 
		Distance[i] = -1;

	Distance[start] = 0;
	Q.push(start);

	while( !Q.empty()) 
	{
		f = Q.front();
		Q.pop();

		for( list<int>::iterator i = Adj[f].begin() ; i != Adj[f].end(); i++ ) 
		{
			if( Distance[*i] == -1 ) 
			{
				Distance[*i] = Distance[ f ] + 1;
				Q.push(*i);
			}
		}
	}

	cout<<"Sortest path unweighted graph : ";
	for(int i = 0 ; i < Distance.size(); i++) 
		cout<<Distance[i]<<" ";
	cout<<endl;
}
/********************************************************* 
 * Weighted Graphs :
 *  
 *  
 *********************************************************/
GraphWeighted::GraphWeighted(int vertices,bool isDirected):Graph(vertices,isDirected)
{
	AdjWeight = new list< Data > [vertices];
}
GraphWeighted::~GraphWeighted()
{
	for(unsigned i = 0; i < v; i++) 
		AdjWeight[i].clear();
}
void GraphWeighted::AddEdge(int u,int v,int weight)
{
	Data tmp;
	tmp.weight = weight;
	tmp.vertex = v - 1;

	AdjWeight[u - 1].push_back(tmp);

	// Parent Class
	Graph::AddEdge(u,v);
}
/********************************************************* 
 * Weighted Graphs :
 *  Dijkstra Algo to find shortest path to all nodes from
 *  starting node
 *  
 *  Complexity : O( E + V log V ) E = Edges, V = Vetices
 *  
 *********************************************************/
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int GraphWeighted::minDistance(int dist[], bool visited[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int i = 0; i < v; i++)
     if ( !visited[i] && dist[i] <= min)
         min = dist[i], min_index = i;
 
   return min_index;
}
void GraphWeighted::Dijkstra(int start)
{
	int  Distance[v];
	bool visited[v];
	
	for(unsigned i = 0; i < v; i++) 
		Distance[i] = INT_MAX,visited[i] = false;

	Distance[ start ] = 0;
	
	for( int count = 0; count < v - 1; count++ ) 
	{
	   // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to start in first iteration.
       int u = minDistance(Distance, visited);

	   // Mark vertex
	   visited[u] = true;

	   for( list< Data >::iterator it = AdjWeight[u].begin(); 
			it != AdjWeight[u].end(); 
			it++ ) 
	   {
		   if( !visited[(*it).vertex] && Distance[ u ] != INT_MAX && 
			   Distance[ u ] + (*it).weight < Distance[ (*it).vertex ]  ) 
		   {
			   Distance[ (*it).vertex ] = Distance[ u ] + (*it).weight;
		   }
	   }
	}

	// Dijkstra Output
	cout<<"Dijkstra : ";
	for( int i = 0; i < v; i++) 
		cout<<Distance[i]<<" ";
	cout<<endl;
}
/********************************************************* 
 * Weighted Graphs :
 *  Bellman Ford Algo to find shortest path to all nodes from
 *  starting node with -ve edges
 *  
 *  Complexity : O( |E| * |V| ) E = Edges, V = Vetices
 *  
 *********************************************************/
void GraphWeighted::BellmanFord(int start)
{
	queue<int> Q;
	bool visited[v];
	int Distance[v];
	
	
	for(unsigned i = 0; i < v; i++) 
	{
		Distance[i] = INT_MAX;
		visited[i] = false;
	}

	Q.push(start);
	Distance[start] = 0;
	
	while( !Q.empty() ) 
	{
		int u = Q.front();
		Q.pop();

		for( list< Data >::iterator it = AdjWeight[u].begin(); 
			 it != AdjWeight[u].end();
			 it++ ) 
		{
			int d = Distance[u] + (*it).weight;
			if( Distance[ (*it).vertex ] > d ) 
			{
				Distance[ (*it).vertex ] = d;
				if( !visited[ (*it).vertex ]) 
					Q.push((*it).vertex);
			}
		}
	}

	cout<<"Bellman Ford : ";
	for(unsigned i = 0; i < v; i++) 
		cout<< Distance[i]<<" ";
	cout<<endl;
}
/********************************************************* 
* Questions 1: To check whether there is path between two vertices in a given graph
*  
* Time complexity : O(E) 
* Space complexity: O(V) 
*********************************************************/  
bool Graph::IsConnected(int source,int destination)
{
	vector<bool> visited;
	visited.resize(v);

	visited[source] = 0;
	for( list<int>::iterator it = Adj[source].begin();
		 it != Adj[source].end(); it++ ) 
	{
		if( !visited[ (*it) ]) 
			DFS(*it,visited);

		if( visited[ destination ]) 
			return true;
	}
	return false;
}
/********************************************************* 
* Questions 2: To Count total number of paths for source 
* To destination vertices in a given graph. 
*  
* Time complexity : O(E) 
* Space complexity: O(V) 
*********************************************************/  
int Graph::CountNumberOfPaths(int source,int destination)
{
	vector<bool> visited;
	int count = 0;
	visited.resize(v);
	visited[source] = true;
	CountNumberOfPaths_until(source,destination,visited,count);
	return count;
}
void Graph::CountNumberOfPaths_until(int source,int destination,vector<bool> &visited, int &count)
{
	if( source == destination ) 
	{
		count++;
		visited[destination] = false;
		return;
	}

	
	for( list<int>::iterator it = Adj[source].begin(); 
		 it != Adj[source].end(); it++) 
	{
		if( !visited[ (*it) ] ) 
		{
			visited[ (*it) ] = true;
			CountNumberOfPaths_until((*it),destination,visited,count);
			visited[ (*it) ] = false;
		}
	}
}
/********************************************************* 
* Questions 3: Articulation point problem
*  
* Time complexity : O(E + V) 
*********************************************************/  
// A recursive function that find articulation points using DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
// ap[] --> Store articulation points
void Graph::APUtil(int u,     bool visited[], int disc[], 
                   int low[], int   parent[], bool ap[])
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;
 
    // Count of children in DFS Tree
    int children = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = Adj[u].begin(); i != Adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
 
        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if ( !visited[v] )
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);
 
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);
 
            // u is an articulation point in following cases
 
            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == -1 && children > 1)
               ap[u] = true;
 
            // (2) If u is not root and low value of one of its children is more
            // than discovery value of u.
            if (parent[u] != -1 && low[v] >= disc[u])
               ap[u] = true;
        }
 
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
// The function to do DFS traversal. It uses recursive function APUtil()
void Graph::AP()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[v];
    int  *disc    = new int[v];
    int  *low     = new int[v];
    int  *parent  = new int[v];
    bool *ap      = new bool[v]; // To store articulation points
 
    // Initialize parent and visited, and ap(articulation point) arrays
    for (int i = 0; i < v; i++)
    {
        parent[i] = -1;
        visited[i] = false;
        ap[i] = false;
    }
 
    // Call the recursive helper function to find articulation points
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);
 
    // Now ap[] contains articulation points, print them
	cout<<"AP : ";
    for (int i = 0; i < v; i++)
        if (ap[i] == true)
            cout << i << " ";
	cout<<endl;
}
/********************************************************* 
* Questions 4: Bridge in a graph ( DFS - Aplication )
*  
* Time complexity : O(E + V) 
*********************************************************/
// A recursive function that finds and prints bridges using DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
void Graph::bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[])
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = Adj[u].begin(); i != Adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
 
        // If v is not visited yet, then recur for it
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);
 
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);
 
            // If the lowest vertex reachable from subtree under v is 
            // below u in DFS tree, then u-v is a bridge
            if ( low[v] > disc[u] )
              cout << u <<" " << v << endl;
        }
 
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
// DFS based function to find all bridges. It uses recursive function bridgeUtil()
void Graph::bridge()
{
    // Mark all the vertices as not visited
    bool * visited = new bool[v];
    int  * disc    = new int[v];
    int  * low     = new int[v];
    int  * parent  = new int[v];
 
    // Initialize parent and visited arrays
    for (int i = 0; i < v; i++)
    {
        parent[i] = -1;
        visited[i] = false;
    }
 
	cout<<"Bridge in Graphs are : "<<endl;

    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}

/********************************************************* 
* Que 5. Eulerian path circuit and path ( DFS - Application)
*  
* Time complexity : O(E + V) 
*********************************************************/
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = Adj[v].begin(); i != Adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
// Method to check if all non-zero degree vertices are connected.
// It mainly does DFS traversal starting from
bool Graph::isConnected()
{
    // Mark all the vertices as not visited
    bool visited[v];
    int i;
    for (i = 0; i < v; i++)
        visited[i] = false;
 
    // Find a vertex with non-zero degree
    for (i = 0; i < v; i++)
        if (Adj[i].size() != 0)
            break;
 
    // If there are no edges in the graph, return true
    if (i == v)
        return true;
 
    // Start DFS traversal from a vertex with non-zero degree
    DFSUtil(i, visited);
 
    // Check if all non-zero degree vertices are visited
    for (i = 0; i < v; i++)
       if (visited[i] == false && Adj[i].size() > 0)
            return false;
 
    return true;
}
/* The function returns one of the following values
   0 --> If grpah is not Eulerian
   1 --> If graph has an Euler path (Semi-Eulerian)
   2 --> If graph has an Euler Circuit (Eulerian)  */
int Graph::isEulerian()
{
    // Check if all non-zero degree vertices are connected
    if (isConnected() == false)
        return 0;
 
    // Count vertices with odd degree
    int odd = 0;
    for (int i = 0; i < v; i++)
        if (Adj[i].size() & 1)
            odd++;
 
    // If count is more than 2, then graph is not Eulerian
    if (odd > 2)
        return 0;
 
    // If odd count is 2, then semi-eulerian.
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected graph
    return (odd) ? 1 : 2;
}
bool Graph::isCyclic()
{
	bool * visited = new bool[v];
	bool * recStack = new bool[v];

	for(int i = 0; i < v; i++) 
		visited[i] = recStack[i] = false;
	
	for( int i = 0; i < v; i++) 
	{
		if( isCyclic_until(i,visited,recStack) ) 
			return true;
	}

	return false;
}
bool Graph::isCyclic_until(int u, bool visited[], bool recStack[])
{
	visited[u]  = true;
	recStack[u] = true;

	list<int>::iterator it;
	for( it = Adj[u].begin(); it != Adj[u].end(); it++) 
	{
		int t = *it;
		if( !visited[t] && isCyclic_until(t,visited,recStack) ) 
			return true;
		else if( recStack[t] ) 
			return true;
	}
	recStack[u] = false;
	return false;
}
/********************************************************* 
* Que 6. Hmilton Path
*  
* Algo Type : Back tracking 
* Prob Type : NP complete 
* Time complexity : 
*********************************************************/
bool GraphWeighted::HamiltonCycle()
{
	int  path[v];
	bool visited[v];
	for(int i = 0; i < v; i++) 
	{
		path[i] = -1;
		visited[i] = false;
	}

	path[0] = 0;
	visited[0] = true;


	if( HamiltonCycle_until(path,1,visited) == false ) 
	{
		cout<<"No Hamilton Path exits"<<endl;
		return false;
	}

	cout<<"Hamilton Path : ";
	for(int i = 0; i < v; i++) 
		cout<<path[i];
	cout<<endl;
}
bool GraphWeighted::HamiltonCycle_until(int path[],int curPos, bool visited[])
{
	if( curPos == v ) 
	{
		return hasEdge( path[curPos - 1],path[0]);
	}
	
	list<int>::iterator it;
	for(it = Adj[path[curPos - 1]].begin(); it != Adj[path[curPos - 1]].end(); it++) 
	{
		int v = (*it);
		if( !visited[v] ) 
		{
			// include vertex 
			path[ curPos ] = v;
			visited[ v ] = true;

			if( HamiltonCycle_until(path,curPos + 1,visited))
				return true;

			visited[ v ] = false;
		}
	}
	return false;
}
bool Graph::hasEdge(int u,int v)
{
	list<int>::iterator it;
	for(it = Adj[u].begin(); it != Adj[u].end(); it++) 
	{
		if( (*it) == v ) 
			return true;
	}
	return false;
}
