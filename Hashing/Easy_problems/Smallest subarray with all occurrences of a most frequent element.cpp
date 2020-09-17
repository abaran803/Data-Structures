// Problem -> Find minimum part(continuous) of array that contain all element having maximum freq

// Approach ->	Initilize some variables: 	max_freq -> To contain current maximum frequency
// 										min_len  -> To contain current minimum length that contain element with max_freq
// 										strtind  -> To contain starting position of array element with max_freq and min_len
// 			Initilize map left to contain index of first occurance of array elements
// 			Initilize map freq to contain frequency of array elements
// 			Traverse the array
// 			If freq of arr[i] is 0 put that value in left[arr[i]] and make freq[arr[i]] as 1
// 			Else increment freq[arr[i]]
// 			If freq of arr[i] > max_freq
// 					max_freq change to frequency of array
// 					min_len change to difference b/w current position and leftmost position of arr[i] means left[arr[i]]
// 					starting point becomes left[arr[i]]
// 			Else if freq of arr[i] == max_freq and min_len > difference b/w current position and left[arr[i]]
// 					min_len = difference b/w current position and left[arr[i]]
// 					starting point = left[arr[i]]

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

void SmSub(int arr[],int n)
{
	unordered_map<int,int> freq;
	unordered_map<int,int> left;
	int min_len = n;
	int max_freq = -1;
	int strtind;
	for(int i=0;i<n;i++)
	{
		if(freq[arr[i]] == 0)
		{
			left[arr[i]] = i;
			freq[arr[i]] = 1;
		}
		else
			freq[arr[i]]++;
		if(freq[arr[i]]>max_freq)
		{
			max_freq = freq[arr[i]];
			min_len = i-left[arr[i]]+1;
			strtind = left[arr[i]];
		}
		else if(freq[arr[i]] == max_freq && i-left[arr[i]]+1 < min_len)
		{
			min_len = i - left[arr[i]] + 1;
			strtind = left[arr[i]];
		}
	}
	for(int i=strtind;i<strtind+min_len;i++)
		cout << arr[i] << " ";
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
	SmSub(arr,n);
	return 0;
}