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
	unordered_set<int> st;
	for(int i=0;i<n;i++)
		st.insert(arr[i]);
	bool isExist = false;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(st.find(arr[i]+arr[j]) != st.end())
			{
				cout << arr[i] << " " << arr[j] << endl;
				isExist = true;
			}
		}
	}
	if(!isExist)
		cout << "Not Exist";
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