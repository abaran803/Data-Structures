#include<bits/stdc++.h>
using namespace std;

struct Graph
{
	int V;
	vector<int> *Adj;
};

Graph* CreateGraph(int V)
{
	Graph *graph = new Graph();
	graph->V = V;
	graph->Adj = new vector<int>[V];
	return graph;
}

void AddEdge(Graph* graph,int u,int v,int Occurance[])
{
	graph->Adj[u].push_back(v);
	if(Occurance[u] == -1)
		Occurance[u] = 0;
	if(Occurance[v] == -1)
		Occurance[v] = 1;
	else
		Occurance[v]++;
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

// void DFS(Graph* graph)
// {
// 	int Visited[graph->V] = {0};
// }

void TSort(Graph *graph,int Occurance[],vector<int> &TopologicalSort)
{
	queue<int> q;
	for(int i=0;i<graph->V;i++)
	{
		if(Occurance[i] == 0)
		{
			TopologicalSort.push_back(i);
			q.push(i);
			Occurance[i] = -1;
		}
	}
	while(!q.empty())
	{
		int s = q.front();
		q.pop();
		for(auto it:graph->Adj[s])
		{
			if(--Occurance[it] == 0)
			{
				TopologicalSort.push_back(it);
				q.push(it);
				Occurance[it] = -1;
			}
		}
	}
}

int main()
{
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int V = 12;
	int Occurance[V];
	vector<int> TopologicalSort;
	for(int i=0;i<V;i++)
		Occurance[i] = -1;
	Graph* graph = CreateGraph(V);
	AddEdge(graph,3,8,Occurance);
	AddEdge(graph,3,10,Occurance);
	AddEdge(graph,5,11,Occurance);
	AddEdge(graph,7,8,Occurance);
	AddEdge(graph,7,11,Occurance);
	AddEdge(graph,11,2,Occurance);
	AddEdge(graph,11,9,Occurance);
	AddEdge(graph,11,10,Occurance);
	AddEdge(graph,8,9,Occurance);
	PrintGraph(graph);
	TSort(graph,Occurance,TopologicalSort);
	for(int it:TopologicalSort)
		cout << it << " ";
	return 0;
}