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
	unordered_map<int,int> freq;
	for(int i=0;i<n;i++)
		freq[arr[i]]++;
	int m = 1;
	for(int i=0;i<n;i++)
	{
		while(freq[m] > 0)
			m++;
		if(arr[i] > n)
			arr[i] = m++;
		if(freq[arr[i]] > 1 || arr[i] > n)
		{
			freq[arr[i]]--;
			arr[i] = m++;
			freq[m-1]++;
		}
	}
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
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