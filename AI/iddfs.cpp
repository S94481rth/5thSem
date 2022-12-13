#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V; 
	list<int> *adj;

	bool DLS(int v, int target, int limit);

public:
	Graph(int V); 
	void addEdge(int v, int w);

	bool IDDFS(int v, int target, int max_depth);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

bool Graph::DLS(int src, int target, int limit)
{
	if (src == target)
		return true;

	if (limit <= 0)
		return false;

	for (auto i = adj[src].begin(); i != adj[src].end(); ++i)
	if (DLS(*i, target, limit-1) == true)
		return true;

	return false;
}


bool Graph::IDDFS(int src, int target, int max_depth)
{

	for (int i = 0; i <= max_depth; i++)
	if (DLS(src, target, i) == true)
		return true;

	return false;
}


int main()
{
    int v,e,e1,e2;
    int target, maxDepth = 3, src;
    cout<<"Enter numebr of vertices : ";
    cin>>v;
    Graph g(v);
    cout<<"Enter numeber of edges : ";
    cin>>e;
    for(int i=0;i<e;i++){
        cout<<"Edge "<<i+1<<" : ";
        cin>>e1>>e2;
        g.addEdge(e1,e2);
    }
    cout<<"Enter source and destination : ";
    cin>>src>>target;
	
	if (g.IDDFS(src, target, maxDepth) == true)
		cout << "Target is reachable from source "
				"within max depth";
	else
		cout << "Target is NOT reachable from source "
				"within max depth";
	return 0;
}
