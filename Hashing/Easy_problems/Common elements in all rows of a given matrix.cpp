#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Chk(int **arr,int m,int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			if(i==0)
				mp[arr[i][j]] = 1;
			else if(i>0 && mp[arr[i][j]] == i)
				mp[arr[i][j]] = i+1;
			if(i == m-1 && mp[arr[i][j]] == i+1)
				cout << arr[i][j] << " ";
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
	Chk(arr,m,n);
	return 0;
}