// Problem -> Find element occurr more then one time

// Approach ->	Create a map
// 				Traverse array increament second part of map with index arr[i]
// 				Traverse map
// 				If second part of map >1 print first part of map at that indexs


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void CheckDuplicacy(int arr[],int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	for(auto it=mp.begin();it != mp.end();it++)
		if(it->second > 1)
			cout << it->first << " ";
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
	CheckDuplicacy(arr,n);
	return 0;
}