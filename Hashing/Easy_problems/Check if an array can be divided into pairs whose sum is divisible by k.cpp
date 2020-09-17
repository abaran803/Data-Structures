// Problem -> Check if an array can be divided into pairs (all elements should be involve) whose sum is divisible by k

// Approach -> Initilize a map to store number of occurance of remainder
// 			Traverse the array and increment second of map at index = k-arr[i]%k
// 			Initilize variable count with value 0
// 			Traverse the array again 
// 						if (k-arr[i]%k) is found decrement mp[k-arr[i]%k], this will give second part of pair
// 						if (arr[i]%k) is found decrement mp[arr[i]%k], this will give first part of pair
// 						increase count by 2, because 2 elements found and also pair contain two elements
// 			return true if count become n means all the elements are involve in pairs
// 			return false otherwise, means some elements don't participate in pairing

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

bool DivArr(int arr[],int n,int k)
{
	if(n%2 != 0)
		return false;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[k-arr[i]%k]++;
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(mp[k-arr[i]%k]>0)
		{
			mp[k-arr[i]%k]--;
			mp[arr[i]%k]--;
			count += 2;
		}
	}
	if(count == n)
		return "true";
	return false;
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
	if(DivArr(arr,n,k))
		cout << "true";
	else
		cout << "false";
	return 0;
}