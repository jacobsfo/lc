#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Data structure to store a graph edge
struct Edge {
	int src, dest;
};

// A class to represent a graph object
class Graph
{
public:
	// a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// Graph Constructor
	Graph(vector<Edge> const &edges, int n)
	{
		// resize the vector to hold `n` elements of type `vector<int>`
		adjList.resize(n);

		// add edges to the undirected graph
		for (auto &edge: edges)
		{
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};


void BFS(Graph const &graph, int v, vector<bool> &discovered)
{
	//create a queue
	queue<int>q;

	//set src node to visited and push src node to queue

	discovered[v]=true;
	q.push(v);
	//while q is not empty
	while(!q.empty())
	{	 
		v = q.front();
		//pop the top
		q.pop();
		cout << v << " ";
		//loop thru nei of v
		for(auto nei:graph.adjList[v])
		{
			//visited if not visited,and push nei into q
			if(!discovered[nei])
			{
				discovered[nei]=true;
				q.push(nei);
			}
		}
	}
	

}
int main()
{
	// vector of graph edges as per the above diagram
	vector<Edge> edges = {
		{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
		{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
		// vertex 0, 13, and 14 are single nodes
	};

	// total number of nodes in the graph (labelled from 0 to 14)
	int n = 15;

	// build a graph from the given edges
	Graph graph(edges, n);

	// to keep track of whether a vertex is discovered or not
	vector<bool> discovered(n, false);

	// Perform BFS traversal from all undiscovered nodes to
	// cover all connected components of a graph
	for (int i = 0; i < n; i++)
	{
		if (discovered[i] == false)
		{
			// start BFS traversal from vertex `i`
			BFS(graph, i, discovered);
		}
	}

	return 0;
}