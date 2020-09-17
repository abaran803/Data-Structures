// Problem -> Find minimum number of subarray form by given array, whose all elements are distinct

// Solution -> If an element repeat k times we have to form k subarray to get all the repeating element
// 			So we have to form atlest n subarray where n is frequency of element whose frequency is maximum in array to put all the repeating element
// 			So finally we have to find frequency of element with maximum frequency

// Approach -> Initilize a map
// 			Store frequency of all the elements of array
// 			Print the maximum frequency

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
	unordered_map<int,int> mp;
	int count = -1;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	for(auto i:mp)
		count = max(count,i.second);
	cout << count;
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