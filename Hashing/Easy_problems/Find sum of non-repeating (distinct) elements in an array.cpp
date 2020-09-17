#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

int Chk(int arr[],int n)
{
	unordered_set<int> st;
	int count = 0;
	for(int i=0;i<n;i++)
		if(st.find(arr[i]) == st.end())
		{
			st.insert(arr[i]);
			count += arr[i];
		}
	return count;
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
	cout << Chk(arr,n);
	return 0;
}