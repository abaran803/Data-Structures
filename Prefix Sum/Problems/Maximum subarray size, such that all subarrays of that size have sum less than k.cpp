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
	int PSum[n];
	PSum[0] = arr[0];
	for(int i=1;i<n;i++)
		PSum[i] += PSum[i-1] + arr[i];
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=i;j<n;j++)
	// 	{
	// 		if(j-i-1 < 0)
	// 			cout << PSum[j] << " ";
	// 		else
	// 			cout << PSum[j]-PSum[i] << " ";
	// 	}
	// 	cout << endl;
	// }
	for(int i=0;i<n;i++)
		cout << PSum[i] << " ";
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