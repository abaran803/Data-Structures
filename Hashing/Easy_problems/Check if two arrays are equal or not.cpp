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
	if(m != n)
		return false;
	unordered_map<int,int> mp;
	for(int i=0;i<m;i++)
		mp[arr1[i]]++;
	for(int i=0;i<n;i++)
		mp[arr2[i]]--;
	for(auto it:mp)
		if(it.second != 0)
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
	for(int i=0;i<m;i++)
		cin >> arr1[i];
	int n;
	cin >> n;
	int arr2[n];
	for(int i=0;i<n;i++)
		cin >> arr2[i];
	if(Chk(arr1,arr2,m,n))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}