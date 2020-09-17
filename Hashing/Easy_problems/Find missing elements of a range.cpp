#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Chk(int arr[],int n,int start,int end)
{
	unordered_set<int> st;
	for(int i=0;i<n;i++)
		st.insert(arr[i]);
	for(int i=start;i<end+1;i++)
		if(st.find(i) == st.end())
			cout << i << " ";
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
	int start,end;
	cin >> start >> end;
	Chk(arr,n,start,end);
	return 0;
}