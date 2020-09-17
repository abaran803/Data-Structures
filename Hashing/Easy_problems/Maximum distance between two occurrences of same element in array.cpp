#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Max_Dist(int arr[],int n)
{
	unordered_map<int,int> mp;
	// int max_dist = 0;
	// for(int i=0;i<n;i++)
	// {
	// 	if(mp[arr[i]] == 0)
	// 		mp[arr[i]] = i+1;
	// 	else
	// 		max_dist = max(max_dist,i+1-mp[arr[i]]);
	// }
	// cout << max_dist;
	cout << mp[arr[3]] << endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	Max_Dist(arr,n);
	return 0;
}