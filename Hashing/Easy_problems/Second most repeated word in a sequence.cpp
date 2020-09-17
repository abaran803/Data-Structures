#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

string Chk(string arr[],int n)
{
	unordered_map<string,int> mp;
	int max1 = -1;
	int max2 = -1;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	for(auto it:mp)
	{
		if(max1 < it.second)
		{
			max2 = max1;
			max1 = it.second;
		}
		else if(max2 < it.second && max1 != it.second)
			max2 = it.second;
	}
	for(auto it:mp)
		if(it.second == max2)
			return it.first;
	return "No Solution";
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int n;
	cin >> n;
	string arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << Chk(arr,n);
	return 0;
}