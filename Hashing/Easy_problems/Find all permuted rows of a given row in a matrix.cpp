#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Chk(int **arr,int m,int n,int k)
{
	unordered_set<int> st;
	for(int i=0;i<n;i++)
		st.insert(arr[k][i]);
	for(int i=0;i<m;i++)
	{
		if(i == k)
			continue;
		int j;
		for(j=0;j<n;j++)
			if(st.count(arr[i][j]) < 1)
				break;
		if(j == n)
			cout << i << " ";
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int m,n;
	cin >> m >> n;
	int **arr = new int*[m];
	for(int i=0;i<m;i++)
	{
		arr[i] = new int[n];
		for(int j=0;j<n;j++)
			cin >> arr[i][j];
	}
	int k;
	cin >> k;
	Chk(arr,m,n,k);
	return 0;
}