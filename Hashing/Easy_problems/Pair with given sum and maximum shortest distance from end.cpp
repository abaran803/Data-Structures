// Problem -> First find all the pairs whose sum is K, then find pair whose max(firstDigit,secondDigit) is minimum

// Approach ->	Initilize a map
// 			Traverse the array and store its minimum distance from both side using min(i+1,n-i) in map
// 			Initilize a variable with maximim value of int named res to store result
// 			Traverse the loop and find pair whose sum is k and whose maximum distance of both digits in pair from side is minimum and store it in res

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Chk(int arr[],int n,int k)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		if(mp[arr[i]] == 0)
			mp[arr[i]] = min(i+1,n-i);
		else
			mp[arr[i]] = min(mp[arr[i]],min(i+1,n-i));
	}
	int res = INT_MAX;
	for(int i=0;i<n;i++)
		if(mp[k-arr[i]] != 0 && arr[i] != k-arr[i])
			res = min(max(mp[arr[i]],mp[k-arr[i]]),res);
	cout << res;
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
	Chk(arr,n,k);
	return 0;
}