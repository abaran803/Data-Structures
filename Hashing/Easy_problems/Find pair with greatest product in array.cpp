#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

int Approach1(int arr[],int n)
{
	int maxi = -1;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(find(arr,arr+n,arr[i]*arr[j]) != (arr+n))
				maxi = max(maxi,arr[i]*arr[j]);
	return maxi;
}

// Trick used in this array is -> 
// 		If a number is perfect square then largest numbers whose product is given number are sqrt(num) (both)
// 		If a number is not a perfect square then largest numbers whose product is given number are sqrt(num) (which is square root of number with perfect square root smaller than given number) and num/sqrt(num)

int Approach2(int arr[],int n)
{
	unordered_map<int,int> mp;

	// Storing the frequency of each element
	for(int i=0;i<n;i++)
		mp[arr[i]]++;

	// Sorting the array
	sort(arr,arr+n);

	// Traversing from last to check that is pairs available for largest number whose product is number
	// i>1 b/c for smallest two elements no pair is possible to get number as their product
	for(int i=n-1;i>1;i++)
	{
		for(int j=0;j<i;j++)
		{
			// Elements of pair must be a factor arr[i](maximum number)
			if(arr[i]%arr[j] == 0 && arr[j] <= sqrt(arr[i]))
			{
				// To store 2nd part of pair
				int res = arr[i]/arr[j];

				// If not a perfect square the frequency of both should be atleast 1
				// As we already know arr[j] exist so we check only for other paer of pair
				if(arr[j] != res && mp[res] > 0)
					return arr[i];

				// If a perfect square then both part pair will be same so that frequency should be atleast 2
				else if(arr[j] == res && mp[res] > 1)
					return arr[i];
			}
		}
	}
	return -1;
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
	cout << Approach1(arr,n);
	return 0;
}