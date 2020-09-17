#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

bool isPrime(int n)
{
	if(n <= 1)
		return false;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i == 0)
			return false;
	return true;
}

void Chk(int arr[],int n,int k)
{
	unordered_map<int,int> freq;
	for(int i=0;i<n;i++)
		freq[arr[i]]++;
	bool isAny = false;
	for(auto it:freq)
	{
		if(it.second>=k && isPrime(it.second))
		{
			isAny = true;
			cout << it.first << " ";
		}
	}
	if(!isAny)
		cout << -1;
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
	int k;
	cin >> k;
	Chk(arr,n,k);
	return 0;
}