#include<bits/stdc++.h>
#include"Graph.h"
using namespace std;
#define SIZE 10

// Breadth First Search
void BFS(vector<int> Adj[],int query)
{
	queue<int> q;
	// Check if Node is Visited
	int Visited[SIZE] = {0};
	// Inserting Node to be started
	q.push(query);
	// Converting to visited Node
	Visited[query] = 1;
	// Printing Value
	cout << query << " ";
	while(!q.empty())
	{
		int s = q.front();
		q.pop();
		vector<int>::iterator it;
		for(it=Adj[s].begin();it != Adj[s].end();it++)
		{
			if(!Visited[*it])
			{
				q.push(*it);
				// Converting to visited Node
				Visited[*it] = 1;
				cout << *it << " ";
			}
		}
	}
}

int main()
{
	// Using Vector to Store nodes
	vector<int> Adj[SIZE];
	Graph(Adj);

	// Traversing Graph Nodes
	BFS(Adj,0);
	return 0;
}