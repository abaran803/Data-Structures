#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

int Chk(int arr[],int n,int k)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	int r = INT_MAX;
	for(int i=0;i<n;i++)
		if(mp[arr[i]] == k)
		{
			r = min(arr[i],r);
			break;
		}
	return r;
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
	int k;
	cin >> k;
	cout << Chk(arr,n,k);
	return 0;
}