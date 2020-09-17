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
	unordered_set<int> st;
	for(int i=0;i<n;i++)
		st.insert(arr2[i]);
	for(int i=0;i<m;i++)
		if(st.find(arr1[i]) == st.end())
			cout << arr1[i] << " ";
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
	for(int i=0;i<m;i++)
		cin >> arr1[i];
	int n;
	cin >> n;
	int arr2[n];
	for(int i=0;i<n;i++)
		cin >> arr2[i];
	Chk(arr1,arr2,m,n);
	return 0;
}