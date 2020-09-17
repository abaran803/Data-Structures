#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void Chk(string arr1[],string arr2[],int m,int n)
{
	// Map to store index of elements of first array
	unordered_map<string,int> mp;

	// Store answer
	vector<string> result;

	// Store minimum index sum
	int min_sum = INT_MAX;

	// Storing index of element of first array
	for(int i=0;i<m;i++)
		mp[arr1[i]] = i;

	// Traversing 2nd array
	for(int i=0;i<n;i++)
	{
		// If element of 2nd array is present in first array
		if(mp.count(arr2[i]))
		{
			// Checking if index sum is smaller than or equal to minimum index sum till now
			// If minimum index sum is smaller
			if(i+mp[arr2[i]] < min_sum)
			{
				// Update minimum index sum
				min_sum = i+mp[arr2[i]];
				// Clearing vector that hold answer b/c now new minimum index sum is found
				result.clear();
				// Inserting value in result
				result.push_back(arr2[i]);
			}
			// If minimum index sum is eaual
			else if(i+mp[arr2[i]] == min_sum)
			{
				// Update minimum index sum
				min_sum = i+mp[arr2[i]];
				// Store new value in result (don't clear b/c new sum is equal to old sum)
				result.push_back(arr2[i]);
			}
		}
	}
	for(auto i:result)
		cout << i << " ";
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int m;
	cin >> m;
	string arr1[m];
	for(int i=0;i<m;i++)
		cin >> arr1[i];
	int n;
	cin >> n;
	string arr2[n];
	for(int i=0;i<n;i++)
		cin >> arr2[i];
	Chk(arr1,arr2,m,n);
	return 0;
}