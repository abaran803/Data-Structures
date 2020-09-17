#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void MaxFreq(int arr[],int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	int maxi = -1;
	int max_freq = 0;
	for(auto it = mp.begin();it != mp.end();it++)
	{
		if(max_freq < it->second)
		{
			maxi = it->first;
			max_freq = it->second;
		}
	}
	cout << maxi;
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
	MaxFreq(arr,n);
	return 0;
}