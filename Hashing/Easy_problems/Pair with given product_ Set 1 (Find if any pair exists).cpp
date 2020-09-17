#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

bool Chk(int arr[],int n,int k)
{
	unordered_set<int> st;
	for(int i=0;i<n;i++)
		st.insert(arr[i]);
	for(int i=0;i<n;i++)
	{
		if(arr[i] == 0)
		{
			if(k == 0)
				return true;
		}
		else if(k%arr[i] == 0)
			if(k/arr[i] != arr[i] && st.find(k/arr[i]) != st.end())
				return true;
	}
	return false;
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
	int k;
	cin >> k;
	if(Chk(arr,n,k))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}