// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
	int V; // No. of vertices

	// Pointer to an array containing adjacency
	// lists
	vector<list<int>> adj;
public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints BFS traversal from a given source s
	void BFS(int s);
	
	//prints shortest path to a target
	vector <int> pathTo(int start, int target);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	vector<bool> visited;
	visited.resize(V,false);

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (auto adjecent: adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}

vector <int> Graph::pathTo(int start, int target){
    
    //path
    vector<int> path;
    
    //paths
    queue<vector<int>> paths;
    
    //initialize visited list
    vector <bool> visited;
    visited.resize(V, false);
    
    queue<int> nodesToVisit;
    nodesToVisit.push(start);
    
    path.push_back(start);
    paths.push(path);
    
    while(!nodesToVisit.empty()){
        
        path = paths.front();
        paths.pop();
        
        int last = path[path.size() - 1];
        
        if (last == target){
            return path;
        }
        
        int node = nodesToVisit.front();
        nodesToVisit.pop();
        
        //visit all adjacent nodes
        for (auto adjacent : adj[node]){
            if (!visited[adjacent]){
                visited[adjacent] = true;
                vector<int> newpath = path;
                newpath.push_back(adjacent);
                paths.push(newpath);
                nodesToVisit.push(adjacent);
            }
        }
    }
    return {};    
}

// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.addEdge(1, 3);
	g.addEdge(3, 5);

	//the following is the first path to destination using BFS
	cout << "This is the path: " << endl;
	vector <int> path = g.pathTo(2, 5);
	for (auto node : path) cout << node << endl;

	return 0;
}
