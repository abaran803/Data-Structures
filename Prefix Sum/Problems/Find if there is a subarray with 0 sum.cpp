#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

bool Ckh(int arr[],int n)
{
	// Set to store prefix sum
	unordered_set<int> st;
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum += arr[i];
		if(sum == 0 || st.find(sum) != st.end())
			return true;
		st.insert(sum);
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
	if(Ckh(arr,n))
		cout << "True";
	else
		cout << "False";
	return 0;
}