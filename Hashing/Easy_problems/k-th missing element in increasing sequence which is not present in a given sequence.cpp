#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

int Chk(int arr1[],int arr2[],int m,int n,int k)
{
	unordered_set<int> s;
	for(int i=0;i<n;i++)
		s.insert(arr2[i]);
	int count = 0;
	for(int i=0;i<m;i++)
	{
		if(s.find(arr1[i]) == s.end())
			count++;
		if(count == k)
			return arr1[i];
	}
	return -1;
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
	int k;
	cin >> k;
	cout << Chk(arr1,arr2,m,n,k);
	return 0;
}