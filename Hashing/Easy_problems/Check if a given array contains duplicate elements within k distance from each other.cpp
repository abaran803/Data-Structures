// Problem -> Check the distance between two equal element in an array in less than or equal k or not

// Approach1 -> Create an unordered map in which first part is element of array and second is its latest position+1
// 				Traverse the array
// 				If the 2nd part of map with index as array element is not 0 and difference between current index and previous index (inside map) is less than or equal to k
// 					then return true
// 				Update map second part of index arr[i] as current index
// 				If array traversal completed perfectly return true

// Approach2 ->	Create a set
// 				Traverse the array
// 				If the element arr[i] present in set return true
// 				Insert arr[i] in set
// 				If i>=k delete element k distance before current index so that data of element whose distance greater than or equal to k on left side, get removed
// 				If array traversal completed successfully return false

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

bool Dup(int arr[],int n,int k)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		if(mp[arr[i]] != 0)
			if(i+1-mp[arr[i]] <= k)
				return true;
		mp[arr[i]] = i+1;
	}
	return false;
}

bool Dup1(int arr[],int n,int k)
{
	unordered_set<int> st;
	for(int i=0;i<n;i++)
	{
		if(st.find(arr[i]) != st.end())
			return true;
		st.insert(arr[i]);
		if(i>=k)
			st.erase(arr[i-k]);
	}
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
	if(Dup1(arr,n,k))
		cout << "true";
	else
		cout << "false";
	return 0;
}