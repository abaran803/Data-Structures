// Problem -> Show all occurrence of element ordered by first occurrence

// Approach ->	Initilize a map mp to store frequency of arr[i] at index arr[i] of map
// 			Traverse array and initilize mp[arr[i]]++ to get frequency
// 			Traverse array and if frequency >0 print element until frequency becomes 0

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Rep(int arr[],int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	for(int i=0;i<n;i++)
	{
		while(mp[arr[i]] > 0)
		{
			cout << arr[i] << " ";
			mp[arr[i]]--;
		}
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
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	Rep(arr,n);
	return 0;
}