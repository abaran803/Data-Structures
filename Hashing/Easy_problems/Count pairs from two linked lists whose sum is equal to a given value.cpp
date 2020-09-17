#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

struct Node
{
	int data;
	Node* next;
};

Node* head1 = NULL;
Node* head2 = NULL;

void Chk(int k)
{
	unordered_set<int> st;
	Node* temp = head1;
	while(temp != NULL)
	{
		st.insert(temp->data);
		temp = temp->next;
	}
	temp = head2;
	int count = 0;
	while(temp != NULL)
	{
		if(st.find(k-temp->data) != st.end())
			count++;
		temp = temp->next;
	}
	cout << count;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("inp.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	int m;
	cin >> m;
	int temp;
	for(int i=0;i<m;i++)
	{
		cin >> temp;
		Node* temp1 = head1;
		Node* temp2 = new Node();
		temp2->data = temp;
		temp2->next = NULL;
		if(temp1 == NULL)
			head1 = temp2;
		else
		{
			while(temp1->next != NULL)
				temp1 = temp1->next;
			temp1->next = temp2;
		}
	}
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		Node* temp1 = head2;
		Node* temp2 = new Node();
		temp2->data = temp;
		temp2->next = NULL;
		if(temp1 == NULL)
			head2 = temp2;
		else
		{
			while(temp1->next != NULL)
				temp1 = temp1->next;
			temp1->next = temp2;
		}
	}
	int k;
	cin >> k;
	Chk(k);
	return 0;
}