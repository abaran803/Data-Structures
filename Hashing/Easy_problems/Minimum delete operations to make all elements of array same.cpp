// Problem -> Minimum deletion of element so all the remaining element will be same
// Or simply minimum deletion involvento form maximum size array whose all element will be same
// Example -> 3,6,4,2,4,2,5,4,6
// Output -> 6
// After deletion remaining array will be -> 4,4,4

// Logic ->	Put element of array as first and its frequency second on map
// 			Find map position whose frequency is maximum
// 			Subtract maximum frequency from total size of array : n-max_freq

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Approach(int arr[],int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	int max_freq = 0;
	for(auto it = mp.begin();it != mp.end();it++)
		max_freq = max(max_freq,it->second);
	cout << n-max_freq << endl;
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
	Approach(arr,n);
	return 0;
}