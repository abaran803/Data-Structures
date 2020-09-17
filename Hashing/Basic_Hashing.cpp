// Purpose of Code -> Enter last 3-digit (as ID) and get the whole Name and Full Number

// Basic_Hash_Function
// Here we are ignoring collision
// We assume that the last three digit of every Phone number is unique

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair

// Structure to Record
struct Record
{
	string name;
	ll PhNo;
};

// Function to Insert Record
void Insert(Record* arr1[],int n)
{
	for(ll i=0;i<n;i++)
	{
		// Reserving location for record and store its location to hash table
		Record* rec = new Record();
		cin >> rec->name;
		cin >> rec->PhNo;
		arr1[rec->PhNo%1000] = rec;
	}
}

// Function to Search Query
Record* Search(int q,Record* arr1[])
{
	return arr1[q];
}

// Main Function
int main()
{
	// Interacting with Local file for Input and Output
	#ifndef ONLINE_JUDGE
		freopen("C:/Users/Ayush/Documents/GitHub/Data_Structures/input.txt","r",stdin);
		freopen("C:/Users/Ayush/Documents/GitHub/Data_Structures/output.txt","w",stdout);
	#endif

	// Number of Records
	ll n;
	cin >> n;

	// Hash table or array
	Record* arr1[1000] = {NULL};

	// Inserting Record
	Insert(arr1,n);

	// Query to search record
	int q;
	cin >> q;
	Record* r = Search(q,arr1);
	if(r != NULL)
		cout << "Name : " << r->name << endl << "PNo. : " << r->PhNo << endl;
	else
		cout << "Record not found" << endl;
	return 0;
}