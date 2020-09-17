#include<bits/stdc++.h>
using namespace std;
#define SIZE 10;

struct Graph
{
	int V;
	vector<int> *Adj;
	int **Cost;
};

Graph* CreateGraph(int V)
{
	Graph* graph = new Graph();
	graph->V = V;
	graph->Adj = new vector<int>[V];
	graph->Cost = new int*[V];
	for(int i=0;i<graph->V;i++)
	{
		graph->Cost[i] = new int[V];
		for(int j=0;j<graph->V;j++)
			graph->Cost[i][j] = INT_MAX;
	}
	return graph;
}

void AddEdge(Graph *graph,int sour,int dest,int cost)
{
	graph->Adj[sour].push_back(dest);
	graph->Cost[sour][dest] = cost;
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

pair<int,int> minEle(Graph *graph,int arr[],int Visited[])
{
	int ind;
	int mini = INT_MAX;
	for(int i=0;i<graph->V;i++)
	{
		if(arr[i]<mini && Visited[i] == 0)
		{
			mini = arr[i];
			ind = i;
		}
	}
	return {ind,mini};
}

void ShortestPath(Graph* graph,int Distance[],int v)
{
	int Visited[graph->V] = {0};
	queue<int> q;
	q.push(v);
	Distance[v] = 0;
	Visited[v] = 1;
	while(!q.empty())
	{
		int s = q.front();
		q.pop();
		for(auto it:graph->Adj[s])
			if(Distance[it] > Distance[s]+graph->Cost[s][it])
				Distance[it] = Distance[s]+graph->Cost[s][it];
		// q.push(minEle(graph,Distance,Visited).first);
		// Visited[q.front()] = 1;
	}
}

int main()
{
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int V = SIZE;
	Graph *graph = CreateGraph(V);
	AddEdge(graph,1,2,9);
	AddEdge(graph,1,3,4);
	AddEdge(graph,3,2,4);
	AddEdge(graph,3,5,13);
	AddEdge(graph,2,4,12);
	AddEdge(graph,2,5,5);
	AddEdge(graph,5,4,3);
	AddEdge(graph,5,6,15);
	AddEdge(graph,4,6,2);
	int Path[graph->V];
	int Distance[graph->V];
	for(int i=0;i<graph->V;i++)
		Distance[i] = INT_MAX;
	ShortestPath(graph,Distance,1);
	for(int i=0;i<V;i++)
		cout << Distance[i] << " ";
	// PrintGraph(graph);
	// int Distance[V];
	// for(int i=0;i<V;i++)
	// 	Distance[i] = INT_MAX;
	// ShortestPath(graph,Distance,0);
	// cout << "Vertex" << "\t| " << "Distance" << endl;
	// cout << "--------|-------" << endl;
	// for(int i=0;i<V;i++)
	// {
	// 	if(Distance[i] != INT_MAX)
	// 		cout << i << "\t\t|\t" << Distance[i] << endl;
	// 	else
	// 		cout << i << "\t\t|\t" << "Infinite" << endl;
	// }
	// for(int i=0;i<V;i++)
	// {
	// 	for(int j=0;j<V;j++)
	// 		cout << graph->Cost[i][j] << " ";
	// 	cout << endl;
	// }
	return 0;
}