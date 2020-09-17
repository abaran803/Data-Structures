#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Approach1(int arr[],int n,int sum)
{
	sort(arr,arr+n);
	int i=0,j=n-1;
	while(i<j)
	{
		if(arr[i]+arr[j]<sum)
			i++;
		else if(arr[i]+arr[j]>sum)
			j--;
		else
		{
			cout << arr[i] << " " << arr[j] << endl;
			i++;
			j--;
		}
	}
}

void Approach2(int arr[],int n,int sum)
{
	unordered_set<int> mp;
	for(int i=0;i<n;i++)
	{
		int temp = sum-arr[i];
		if(mp.find(temp) != mp.end())
			cout << arr[i] << " " << temp << endl;
		mp.insert(arr[i]);
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
	int sum;
	cin >> sum;
	Approach2(arr,n,sum);
	return 0;
}