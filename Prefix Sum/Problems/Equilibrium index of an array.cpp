#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

int Equli(int arr[],int n)
{
	int sum = 0,LSum = 0;
	for(int i=0;i<n;i++)
		sum += arr[i];
	for(int i=0;i<n;i++)
	{
		// Sum on right side
		sum -= arr[i];
		if(sum == LSum)
			return i;
		// Sum on right side
		LSum += arr[i];
	}
	return -1;
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
	cout << Equli(arr,n);
	return 0;
}