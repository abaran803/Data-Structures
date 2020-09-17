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
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	sort(arr,arr+n);
	int count = 0;
	for(int i=n-1;i>1;i--)
	{
		int k = arr[i];
		for(int j=0;j<i;j++)
		{
			if(k%arr[j] == 0)
			{
				if(k/arr[j] != arr[j] && mp[k/arr[j]] > 0)
					count++;
				else if(k/arr[j] == arr[j] && mp[arr[j] > 1])
					count++;
			}
		}
	}
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
	Chk(arr,n);
	return 0;
}