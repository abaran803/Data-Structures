#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	vector<int> *Adj;

	public:
		void DFS(int i,bool Visited[]);
		Graph(int v);
		void PrintGraph();
		void AddEdge(int sour,int dest);
		int Mother_Vertex(bool Visited[]);
};

Graph::Graph(int v)
{
	V = v;
	Adj = new vector<int>[V];
}

void Graph::AddEdge(int sour,int dest)
{
	Adj[sour].push_back(dest);
}

void Graph::DFS(int i,bool Visited[])
{
	Visited[i] = true;
	for(auto it:Adj[i])
		if(!Visited[it])
			DFS(it,Visited);
}

void Graph::PrintGraph()
{
	for(int i=0;i<V;i++)
	{
		if(!Adj[i].empty())
		{
			cout << "For " << i << endl;
			cout << i;
			for(auto it:Adj[i])
			{
				cout << "-->" << it;
			}
			cout << endl;
		}
	}
}

int Graph::Mother_Vertex(bool Visited[])
{
	int v;
	for(int i=0;i<V;i++)
	{
		if(!Visited[i])
		{
			DFS(i,Visited);
			v = i;
		}
	}
	for(int i=0;i<V;i++)
		Visited[i] = false;
	DFS(v,Visited);
	for(int i=0;i<V;i++)
		if(!Visited[i])
			return -1;
	return v;
}

int main()
{
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int V = 7;
	Graph graph(V);
	graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(4, 1);
    graph.AddEdge(6, 4);
    graph.AddEdge(5, 6);
    graph.AddEdge(5, 2);
    graph.AddEdge(6, 0);
    bool Visited[V];
    for(int i=0;i<V;i++)
    	Visited[i] = false;
    cout << graph.Mother_Vertex(Visited);
	return 0;
}