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
	map<int,int> freq;
	for(int i=0;i<n;i++)
		freq[arr[i]]++;
	int count = 0;
	for(auto it:freq)
	{
		count += it.second;
		cout << it.first << "->" << count << endl;
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
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	Chk(arr,n);
	return 0;
}