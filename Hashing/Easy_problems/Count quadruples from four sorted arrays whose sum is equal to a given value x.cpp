#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Chk(int arr1[],int arr2[],int arr3[],int arr4[],int n,int k)
{
	unordered_map<int,int> SumFreq;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			SumFreq[arr1[i]+arr2[j]]++;
	int count = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int preSum = arr3[i]+arr4[j];
			if(SumFreq.find(k-preSum) != SumFreq.end())
				count += SumFreq[k-preSum];
		}
	cout << count;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int m;
	cin >> m;
	int arr1[m],arr2[m],arr3[m],arr4[m];
	for(int i=0;i<m;i++)
		cin >> arr1[i];
	for(int i=0;i<m;i++)
		cin >> arr2[i];
	for(int i=0;i<m;i++)
		cin >> arr3[i];
	for(int i=0;i<m;i++)
		cin >> arr4[i];
	int k;
	cin >> k;
	Chk(arr1,arr2,arr3,arr4,m,k);
	return 0;
}