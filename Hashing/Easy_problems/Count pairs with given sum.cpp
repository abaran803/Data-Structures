#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Chk(int arr[],int n,int k)
{
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	int count = 0;
	for(int i=0;i<n;i++)
	{
		// Addding total number of element whose value is k-arr[i]
		count += mp[k-arr[i]];

		// If a number and k-number is equal like for 6 it is 3,3 then for frequency of k-arr[i] we have to remove 1 from all value where the 1 which is not added is arr[i]
		if(k-arr[i] == arr[i])
			count--;
	}
	// For every (a,b) whose sum is k there exist (b,a) so we have to divide by 2
	cout << count/2;
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