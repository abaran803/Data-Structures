#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int m,n,num;
	string str;
	cin >> m;
	unordered_map<string,int> mp;
	for(int i=0;i<m;i++)
	{
		cin >> str >> num;
		mp[str] = num;
	}
	cin >> n;
	int count = 0;
	for(int i=0;i<n;i++)
	{
		cin >> str >> num;
		if(mp[str] != 0 && mp[str] != num)
			count++;
	}
	cout << count;
	return 0;
}