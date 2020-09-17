#include<bits/stdc++.h>
using namespace std;

struct Graph
{
	int V;
	set<int,greater<int>> *Adj;
};

Graph* CreateGraph(int V)
{
	Graph *graph = new Graph();
	graph->V = V;
	graph->Adj = new set<int,greater<int>>[V];
	return graph;
}

void addEdge(Graph* graph,int sor,int dest)
{
	graph->Adj[sor].insert(dest);
	graph->Adj[dest].insert(sor);
}

void PrintGraph(Graph* graph)
{
	for(int i=0;i<graph->V;i++)
	{
		if(!graph->Adj[i].empty())
		{
			cout << "List for " << i << " ";
			for(auto it:graph->Adj[i])
				cout << "->" << it;
			cout << endl;
		}
	}
}

void SearchEdge(Graph *graph,int sor,int dest)
{
	if(graph->Adj[sor].find(dest) != graph->Adj[sor].end())
		cout << "Edge from " << sor << " to " << dest << " found." << endl;
	else
		cout << "Edge from " << sor << " to " << dest << " not found." << endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int V = 10;
	Graph *graph = CreateGraph(V);
	addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
    PrintGraph(graph);
    SearchEdge(graph, 2, 1); 
    SearchEdge(graph, 0, 3); 
	return 0;
}