#include<bits/stdc++.h> 
#define int long long
#define endl '\n'

using namespace std; 
void solve(); 

int32_t main() 
{ 
	ios_base::sync_with_stdio(false);cin.tie(NULL); 

	#ifndef ONLINE_JUDGE 
		freopen("inp.txt", "r", stdin); 
		freopen("err.txt", "w", stderr); 
		freopen("out.txt", "w", stdout); 
	#endif 

	int t=1; 
	//cin>>t; 
	while(t--) 
	{ 
		solve(); 
		cout<<"\n"; 
	} 
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0; 
} 

void solve() 
{ 
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	int maxi = INT_MIN;
	for (int i = 0; i < n; ++i)
		maxi = max(maxi,arr[i]);
	int *arr1 = new int[maxi+1];
	for(int i=0;i<n;i++)
		arr1[arr[i]]++;
	for(int i=0;i<=maxi;i++)
	{
		while(arr1[i])
		{
			cout << i << ' ';
			arr1[i]--;
		}
	}
}