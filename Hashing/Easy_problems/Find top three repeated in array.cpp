// Problem -> 	Find 3 elements with maximum frequency
// 			Like if max_freq of an element is 4 and no other have 4 so the other two elements with 3 or less(but currently maximum) will be considered

// Approach ->	Initilize a map
// 			Traverse array and increment map as mp[arr[i]]++
// 			Initilize three pairs namely x,y,z in which 1st part contain frequency and 2nd part will contain value
// 			Traverse the map
// 				If frequency part of x is smaller than frequency part of map
// 					put y in z and x in y and make frequency part of x as frequency part of map and val part of x as val part of map, this will put 1st max frequency element in x
// 				Else if frequency part of y is smaller than frequency of map
// 					put y in z and make frequency part of y as frequency part of map and val part of y as val part of map, this will put 2nd max frequency element in y
// 				Else if frequency part of z is smaller than frequency of map
// 					Make frequency part of z as frequency part of map and val part of z as val part of map, this will put 3rd max frequency element in z

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void ChkRep(int arr[],int n)
{
	unordered_map<int,int> mp;
	pair<int,int> x,y,z;
	int max_freq = -1;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	for(auto it:mp)
	{
		if(it.second>x.first)
		{
			z = y;
			y = x;
			x.first = it.S;
			x.second = it.F;
		}
		else if(it.second>y.first)
		{
			z = y;
			y.first = it.S;
			y.second = it.F;
		}
		else if(it.second>z.first)
		{
			z.first = it.S;
			z.second = it.F;
		}
	}
	cout << x.second << " " << y.second << " " << z.second;
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
	ChkRep(arr,n);
	return 0;
}