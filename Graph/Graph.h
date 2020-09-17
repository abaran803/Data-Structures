// Creating Undirected Graph
void Insert(std::vector<int> Adj[],int a,int b)
{
	Adj[a].push_back(b);
	Adj[b].push_back(a);
}

int Graph(std::vector<int> Adj[])
{
	// Inseeting Edges
	Insert(Adj,0,1);
	Insert(Adj,0,4);
	Insert(Adj,1,4);
	Insert(Adj,1,2);
	Insert(Adj,1,3);
	Insert(Adj,2,3);
	Insert(Adj,3,4);
	return 0;
}