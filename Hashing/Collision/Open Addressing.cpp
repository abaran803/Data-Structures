// Collision -> It occurr when two different data have same value when applying hash function
// If collision occur, store new data to next block of hash table
// If next block already reserve we traverse until we get empty block
// If we use %n so that we repeat hash table if we don't found empty space until last index
// For searching, search for hash[data]
// If hash[data] != required value, apply data++ until get required value;

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

struct Record
{
	string name;
	ll PhNo;
};

void Insert(Record* arr1[],int n)
{
	for(ll i=0;i<n;i++)
	{
		Record* rec = new Record();
		cin >> rec->name;
		cin >> rec->PhNo;
		if(arr1[rec->PhNo%1000] == NULL)
			arr1[rec->PhNo%1000] = rec;
		else
		{
			int r = (rec->PhNo+1)%1000;
			while(arr1[r] != NULL)
			{
				(r++)%1000;
			}
			arr1[r] = rec;
		}
	}
}

void Search(int q,Record* arr1[])
{
	int r = q;
	if(arr1[r] != NULL)
	{
		while(arr1[r] != NULL)
		{
			if((arr1[r]->PhNo)%1000 == q)
			{
				cout << "Name : " << arr1[r]->name << endl << "PNo. : " << arr1[r]->PhNo << endl;
			}
			r = (r+1)%1000;
		}
	}
	else
		cout << "Record not found" << endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	ll n;
	cin >> n;
	Record* arr1[1000] = {NULL};
	Insert(arr1,n);
	int q;
	cin >> q;
	Search(q,arr1);
	return 0;
}
