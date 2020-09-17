// Problem -> An array of length n contain elements from 1 to (n-1), contain an element twice, find that ONLINE_JUDGE

// Approach (Time: O(n) Space: O(n)) ->	Initilize a set contain
// 										Traverse array and if set don't contain arr[i] insert it else return that element

// Better approach(Time: O(n) Space:O(1))-> Calculate sum of (n-1) natural number using formula n*(n-1)/2
// 										 Calculate sum of all elements in array
// 										 Subtract First from Second

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

int RepEle(int arr[],int n)
{
	unordered_set<int> st;
	for(int i=0;i<n;i++)
	{
		if(st.find(arr[i]) != st.end())
			return arr[i];
		else
			st.insert(arr[i]);
	}
	return -1;
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
	cout << RepEle(arr,n);
	return 0;
}