// Note : Elements are different in both set and <1000
// Initilise an array (as hash table) with value of all element as 0
// Traverse 1st array and increase value of hash table at arr1[i] index by 1
// Traverse 2nd array and if value of hash table at arr2[i] index is 0 return false otherwise return true

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MAX 1000

bool SubsetOrNot(int arr1[],int arr2[],int n,int m)
{
	int arr3[MAX] = {0};
	for(int i=0;i<n;i++)
		arr3[arr1[i]]++;
	for(int i=0;i<m;i++)
		if(arr3[arr2[i]] == 0)
			return false;
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int n,m;
	cin >> n;
	int arr1[n];
	for(int i=0;i<n;i++)
		cin >> arr1[i];
	cin >> m;
	int arr2[m];
	for(int j=0;j<m;j++)
		cin >> arr2[j];
	if(SubsetOrNot(arr1,arr2,n,m))
		cout << "True";
	else
		cout << "False";
	return 0;
}