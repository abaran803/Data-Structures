#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void AllSym(int arr[][2],int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		mp[arr[i][0]] = arr[i][1];
		if(mp[arr[i][1]] == arr[i][0])
			cout << "{" << arr[i][1] << ", " << arr[i][0] << "}" << endl;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int n;
	cin >> n;
	int arr[n][2];
	char c;
	// Input way ->
	// 					k = 3 (or other)
	// 					{30, 40}, {3, 4}, {40, 30}
	for(int i=0;i<n;i++)
		cin >> c >> arr[i][0] >> c >> arr[i][1] >> c >> c;
	AllSym(arr,n);
	return 0;
}