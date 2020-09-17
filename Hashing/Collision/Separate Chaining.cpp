// Collision -> It occurr when two different data have same value when applying hash function
// Store record as Nodes in Linked list form, pointed to NULL
// When collision occurr Node will point to another which contain new data and new Node will now point to NULL
// Initially: hash[index] -> Node1 -> NULL
// When collision occur: hash[index] -> Node1 -> Node2 -> NULL

// Advantages
// Easy to Implement
// Never fill up

// Disadvantages
// Cache performance is not good due to use of Linked List
// Wastage of Space
// For long chain(repeated many times) search may be O(n)
// Use extra space to store links

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
	Record* next;
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
			Record* r = arr1[rec->PhNo%1000];
			while(r->next != NULL)
			{
				r = r->next;
			}
			r->next = rec;
		}
	}
}

void Search(int q,Record* arr1[])
{
	Record* r = arr1[q];
	if(r != NULL)
	{
		while(r != NULL)
		{
			cout << "Name : " << r->name << endl << "PNo. : " << r->PhNo << endl;
			r = r->next;
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
