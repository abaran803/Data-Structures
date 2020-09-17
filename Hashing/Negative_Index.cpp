// Logic -> Create a 2D hash table with totalSize*2 (where totalsize = maxIndex)
// This means for every index there are two blocks to contain records
// If index is +ve make firse block of that index 1 
// If index is -ve make second block of abs(index) 1

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

bool arr1[1000][2] = {0};

void Insert(int n)
{
	for(int i=0;i<n;i++)
	{
		int q;
		cin >> q;
		if(q>=0)
			arr1[q][0] = 1;
		else
			arr1[abs(q)][1] = 1;
	}
}

void Search(int q)
{
	if(q>=0)
	{
		if(arr1[q][0] == 1)
		{
			cout << q << " exist in Record" << endl;
		}
		else
		{
			cout << q << " does not exist in Record" << endl;
		}
	}
	else
	{
		if(arr1[abs(q)][1] == 1)
		{
			cout << q << " exist in Record" << endl;
		}
		else
		{
			cout << q << " does not exist in Record" << endl;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("C:/Users/Ayush/Documents/GitHub/Data_Structures/input.txt","r",stdin);
		freopen("C:/Users/Ayush/Documents/GitHub/Data_Structures/output.txt","w",stdout);
	#endif

	int n;
	cin >> n;
	Insert(n);
	int q;
	cin >> q;
	Search(q);
	return 0;
}

