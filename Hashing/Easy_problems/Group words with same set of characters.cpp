#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX_CHAR 26 
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

string newString(string str)
{
	// Making all char from a to z as false
	bool vis[MAX_CHAR] = {false};
	// If anyone occur any number of time it will become true and this hold uniqueness
	for(int i=0;i<str.length();i++)
		vis[str[i]-'a'] = true;
	// Key to store new string
	string key = "";
	// Traversing table which is from a to z to this hold sort property
	for(int i=0;i<MAX_CHAR;i++)
		if(vis[i])
			key += (char)(i+'a');
	// returning key in which element are arranged in unique manner and in sorted order
	return key;
}

void Chk(string arr[],int n)
{	
	// String hold sorted unique key (like in set but for char) string
	// Vector store index of all string whose key value is same
	unordered_map<string,vector<int>> mp;
	for(int i=0;i<n;i++)
	{
		// Here key is a string act as set
		string key = newString(arr[i]);
		mp[key].push_back(i);
	}
	for(auto it:mp)
	{
		for(auto v=it.second.begin();v != it.second.end();v++)
			cout << arr[*v] << " ";
		cout << endl;
	}
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
	Chk(arr,n);
	return 0;
}