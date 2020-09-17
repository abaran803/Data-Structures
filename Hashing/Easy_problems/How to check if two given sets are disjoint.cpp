// Problem -> Given two array check that they are disjoint or not

// Approach -> Initilize a set
// 			Traverse 1st array and insert it in set
// 			Traverse 2nd set and if any element is found in set return false means not-disjoint
// 			If no element matches with set and gte out of loop prefectly return true means disjoint

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

bool Chk(int arr1[],int arr2[],int m,int n)
{
	unordered_set<int> st;
	for(int i=0;i<m;i++)
		st.insert(arr1[i]);
	for(int i=0;i<n;i++)
		if(st.find(arr2[i]) != st.end())
			return false;
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int m;
	cin >> m;
	int arr1[m];
	for (int i = 0; i < m; ++i)
		cin >> arr1[i];
	int n;
	cin >> n;
	int arr2[n];
	for(int i=0;i<n;i++)
		cin >> arr2[i];
	if(Chk(arr1,arr2,m,n))
		cout << "Disjoint";
	else
		cout << "Not Disjoint";
	return 0;
}