// Problem -> Given two array, we have to find sum of only those elements (from both array) which don't present in both array

// Approach -> Initilize a map to store frequency
// 			Traverse both array one by one and apply mp[arr[i]] to increase frequency of that element
// 			Initilize a variable with value 0 to get sum of all element
// 			Traverse map, if frequency at any index is 1 means element is present only in one array add that element in sum

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Chk(int arr1[],int arr2[],int m,int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<m;i++)
		mp[arr1[i]]++;
	for(int i=0;i<n;i++)
		mp[arr2[i]]++;
	int sum = 0;
	for(auto i:mp)
		if(i.second == 1)
			sum += i.first;
	cout << sum;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int m,n;
	cin >> m;
	int arr1[m];
	for(int i=0;i<m;i++)
		cin >> arr1[i];
	cin >> n;
	int arr2[n];
	for(int i=0;i<n;i++)
		cin >> arr2[i];
	Chk(arr1,arr2,m,n);
	return 0;
}