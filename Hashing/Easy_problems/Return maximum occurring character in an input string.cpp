#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Chk(string str)
{
	int n = 26;
	int arr[n] = {0};
	for(int i=0;i<str.size();i++)
		arr[str[i]-'a']++;
	int maxi = -1;
	char val;
	for(int i=0;i<26;i++)
	{
		if(maxi<arr[i])
		{
			maxi = arr[i];
			val = i+'a';
		}
	}
	cout << val;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	string str;
	cin >> str;
	Chk(str);
	return 0;
}