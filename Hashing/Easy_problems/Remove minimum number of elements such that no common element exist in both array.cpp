#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

int Chk(int arr1[],int arr2[],int m,int n)
{
	unordered_map<int,int> mp;
	int count = 0;
	for(int i=0;i<m;i++)
		mp[arr1[i]]++;
	for(int i=0;i<n;i++)
	{
		if(mp[arr2[i]]>0)
		{
			count++;
			mp[arr2[i]]--;
		}
	}
	return count;

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
	cout << Chk(arr1,arr2,m,n);
	return 0;
}