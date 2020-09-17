#include<bits/stdc++.h>
using namespace std;
#define SIZE 10;

struct Graph
{
	int V;
	vector<int> *Adj;
};

Graph* CreateGraph(int V)
{
	Graph* graph = new Graph();
	graph->V = V;
	graph->Adj = new vector<int>[V];
	return graph;
}

void AddEdge(Graph *graph,int sour,int dest)
{
	graph->Adj[sour].push_back(dest);
	// graph->Adj[dest].push_back(sour);
}

void PrintGraph(Graph *graph)
{
	for(int i=0;i<graph->V;i++)
	{
		if(!graph->Adj[i].empty())
		{
			cout << "For " << i << " ";
			for(int it:graph->Adj[i])
				cout << "->" << it;
			cout << endl;
		}
	}
}

void ShortestPath(Graph* graph,int Distance[],int v)
{
	queue<int> q;
	q.push(v);
	Distance[v] = 0;
	while(!q.empty())
	{
		int s = q.front();
		q.pop();
		for(auto it:graph->Adj[s])
		{
			if(Distance[it]>Distance[s]+1)
			{
				Distance[it] = Distance[s]+1;
				q.push(it);
			}
		}
	}
}

int main()
{
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int V = SIZE;
	Graph *graph = CreateGraph(V);
	AddEdge(graph,0,1);
	AddEdge(graph,0,3);
	AddEdge(graph,1,3);
	AddEdge(graph,1,4);
	AddEdge(graph,2,0);
	AddEdge(graph,2,5);
	AddEdge(graph,3,5);
	AddEdge(graph,3,6);
	AddEdge(graph,4,6);
	AddEdge(graph,6,5);
	PrintGraph(graph);
	int Distance[V];
	for(int i=0;i<V;i++)
		Distance[i] = INT_MAX;
	ShortestPath(graph,Distance,0);
	cout << "Vertex" << "\t| " << "Distance" << endl;
	cout << "--------|-------" << endl;
	for(int i=0;i<V;i++)
	{
		if(Distance[i] != INT_MAX)
			cout << i << "\t\t|\t" << Distance[i] << endl;
		else
			cout << i << "\t\t|\t" << "Infinite" << endl;
	}
	return 0;
}