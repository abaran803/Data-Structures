#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void PSum(int arr[],int PrefixSum[],int n)
{
	PrefixSum[0] = arr[0];
	for(int i=1;i<n;i++)
		PrefixSum[i] = PrefixSum[i-1] + arr[i];
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
	int PrefixSum[n];
	PSum(arr,PrefixSum,n);
	for(int i=0;i<n;i++)
		cout << PrefixSum[i] << " ";
	return 0;
}