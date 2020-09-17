#include<bits/stdc++.h>
#include"Graph.h"
using namespace std;
#define SIZE 10

void Traverse(vector<int> Adj[])
{
	for(int i=0;i<SIZE;i++)
	{
		if(!Adj[i].empty())
		{
			cout << "For value " << i;
			for(int it:Adj[i])
				cout << "->" << it;
			cout << endl;
		}
	}
	cout << endl;
}

int main()
{
	// Using Vector to Store nodes
	vector<int> Adj[SIZE];
	Graph(Adj);

	// Traversing Graph Nodes
	Traverse(Adj);
	return 0;
}