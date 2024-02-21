// An Iterative C++ program to do DFS traversal from
// a given source vertex. DFS(int s) traverses vertices
// reachable from s.
#include<bits/stdc++.h>
using namespace std;
//r
// This class represents a directed graph using adjacency
// list representation
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // adjacency lists
public:
	Graph(int V); // Constructor
	void addEdge(int v, int w); // to add an edge to graph
	void DFS(); // prints all vertices in DFS manner

	// prints all not yet visited vertices reachable from s
	void DFSUtil(int s, vector<bool> &visited);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// prints all not yet visited vertices reachable from s
void Graph::DFSUtil(int s, vector<bool> &visited)
{
	//make stack
	stack<int>st;
	//push src node to st
	st.push(s);
	
	//while stack not empty
	while(!st.empty())
	{	int v = st.top();
		//pop the top
		st.pop();
		//loop thru nei of v
		if (!visited[v])
		{
			cout << v << " ";
			visited[v] = true;
		}
		for(auto i = adj[v].begin(); i != adj[v].end();i++)
		{
			//if not visited set to visited
			if(!visited[*i])
			{
				//visited[*i]=true;
				st.push(*i);
			}
		}
	}
	
}

// prints all vertices in DFS manner
void Graph::DFS()
{
	// Mark all the vertices as not visited
	vector<bool> visited(V, false);

	for (int i = 0; i < V; i++)
		if (!visited[i])
			DFSUtil(i, visited);
}

// Driver program to test methods of graph class
int main()
{
	Graph g(5); // Total 5 vertices in graph
	g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

	cout << "Following is Depth First Traversal\n";
	g.DFS();

	return 0;
}
