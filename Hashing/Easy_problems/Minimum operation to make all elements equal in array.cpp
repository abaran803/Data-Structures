// Problem -> In an array find minimum operation involve to  make all the element equal
// eg -> 1,2,3,4 <> 1,1,1,1 Output -> 3
// eg -> 2,4,5,3,2,4,3,5,2 <> 2,2,2,2,2,2,2,2,2 Output -> 6

// Approach -> Find element with maximum freq and subtract freq from total size

// Method -> 	In a map store elements of array as first and its freq as second
// 				Calculate max freq and perform n-max_freq

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

int Max_Freq(int arr[],int n)
{
	unordered_map<int,int> mp;
	int max_freq = 0;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	for(auto it = mp.begin();it != mp.end();it++)
		max_freq = max(max_freq,it->second);
	return max_freq;
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
	int max_freq = Max_Freq(arr,n);
	cout << n-max_freq;
	return 0;
}