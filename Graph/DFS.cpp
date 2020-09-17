#include<bits/stdc++.h>
#include"Graph.h"
using namespace std;
#define SIZE 10

int Visited[SIZE] = {0};

void DFSRecursive(vector<int> Adj[],int query)
{
	if(!Visited[query])
	{
		Visited[query] = 1;
		cout << query << " ";
		for(auto it=Adj[query].begin();it != Adj[query].end();it++)
			DFSRecursive(Adj,*it);
	}
}

// Depth First Search
void DFSNon_Recursive(vector<int> Adj[],int query)
{
	stack<int> st;
	int Visited[SIZE] = {0};
	st.push(query);
	Visited[query] = 1;
	cout << query << " ";
	while(!st.empty())
	{
		int s = st.top();
		vector<int>::iterator it;
		for(it=Adj[s].begin();it != Adj[s].end();it++)
		{
			if(!Visited[*it])
			{
				st.push(*it);
				Visited[*it] = 1;
				cout << *it << " ";
				break;
			}
		}
		if(it == Adj[s].end())
			st.pop();
	}
	cout << endl;
}

int main()
{
	// Using Vector to Store nodes
	vector<int> Adj[SIZE];
	Graph(Adj);

	// Traversing Graph Nodes
	DFSNon_Recursive(Adj,0);
	DFSRecursive(Adj,0);
	return 0;
}