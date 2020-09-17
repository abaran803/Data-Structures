#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Chk(int arr[],int n)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]] = i;
	int arr1[n];
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{
		arr1[mp[arr[i]]] = i;
	}
	for(int i=0;i<n;i++)
		cout << arr1[i] << " ";
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
	Chk(arr,n);
	return 0;
}