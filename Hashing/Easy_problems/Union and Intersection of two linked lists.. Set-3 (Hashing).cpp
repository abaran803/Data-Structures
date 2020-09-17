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

struct Node
{
	int data;
	Node* next;
};

Node* UnionSet = NULL;
Node* Hash = NULL;
Node* IntersectionSet = NULL;
Node* List1 = NULL;
Node* List2 = NULL;

void Insert(int data,Node** head)
{
	Node* temp = new Node();
	temp -> data = data;
	temp -> next = NULL;
	if(*head == NULL)
	{
		*head = temp;
		return;
	}
	Node* temp1 = *head;
	while(temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	temp1->next = temp;
}

void Print(Node** head)
{
	Node* temp = *head;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void Union(unordered_map<int,int> mp)
{
	Node* temp = UnionSet;
	for(auto it = mp.begin();it != mp.end();it++)
	{
		if(it->S != 0)
		{
			Node* temp1 = new Node();
			temp1->data = it->F;
			temp1->next = NULL;
			if(UnionSet == NULL)
			{
				UnionSet = temp1;
				temp = UnionSet;
			}
			else
			{
				while(temp->next != NULL)
					temp = temp->next;
				temp->next = temp1;
			}
		}
	}
	Print(&UnionSet);
}

void Intersection(unordered_map<int,int> mp)
{
	Node* temp = IntersectionSet;
	for(auto it = mp.begin();it != mp.end();it++)
	{
		if(it->S == 2)
		{
			Node* temp1 = new Node();
			temp1->data = it->F;
			temp1->next = NULL;
			if(IntersectionSet == NULL)
			{
				IntersectionSet = temp1;
				temp = IntersectionSet;
			}
			else
			{
				while(temp->next != NULL)
					temp = temp->next;
				temp->next = temp1;
			}
		}
	}
	Print(&IntersectionSet);
}

void UnionAndIntersection()
{
	unordered_map<int,int> mp;
	Node* temp1 = List1;
	Node* temp2 = List2;
	while(temp1 != NULL || temp2 != NULL)
	{
		if(temp1 != NULL)
		{
			mp[temp1->data]++;
			temp1 = temp1->next;
		}
		if(temp2 != NULL)
		{
			mp[temp2->data]++;
			temp2 = temp2->next;
		}
	}
	Union(mp);
	Intersection(mp);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int n,val;
	cin >> n;
	while(n--)
	{
		cin >> val;
		Insert(val,&List1);
	}
	int m;
	cin >> m;
	while(m--)
	{
		cin >> val;
		Insert(val,&List2);
	}
	Print(&List1);
	Print(&List2);
	UnionAndIntersection();
}