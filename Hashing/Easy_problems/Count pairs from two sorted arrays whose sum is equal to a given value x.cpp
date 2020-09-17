#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

int Chk(int arr1[],int arr2[],int m,int n,int x)
{
	int count = 0; 
      
    unordered_set<int> us; 
      
    // insert all the elements  
    // of 1st array in the hash 
    // table(unordered_set 'us') 
    for (int i = 0; i < m; i++) 
        us.insert(arr1[i]); 
      
    // for each element of 'arr2[]  
    for (int j = 0; j < n; j++)  
  
        // find (x - arr2[j]) in 'us' 
        if (us.find(x - arr2[j]) != us.end()) 
            count++; 
      
    // required count of pairs      
    return count; 
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int m;
	cin >> m;
	int arr1[m];
	for(int i=0;i<m;i++)
		cin >> arr1[i];
	int n;
	cin >> n;
	int arr2[n];
	for(int i=0;i<n;i++)
		cin >> arr2[i];
	int k;
	cin >> k;
	cout << Chk(arr1,arr2,m,n,k);
	return 0;
}