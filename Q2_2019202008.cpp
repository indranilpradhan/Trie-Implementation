#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <iterator>
using namespace std;
#define ll long long int

class Node
{
	public:
	ll data;
	Node *left = NULL;
	Node *right = NULL;
	bool isend =false;
};

Node* root = NULL;
vector<ll> res;
vector<ll> decimaltobinary(ll number)
{
	vector<ll> v;
	ll i = 0;
	while (number > 0) { 
        // storing remainder in binary array 
        v.push_back(number%2);
        number = number / 2; 
        i++; 
    }

    for(ll k=0; k<(40-i); k++)
    {
    	v.push_back(0);
    }
    reverse(v.begin(), v.end());
    return v;
}

ll binarytodecimal(vector<ll> v) 
{ 
    ll number = 0;
    ll base = 1;
    reverse(v.begin(),v.end());
    vector<ll>::iterator it;
    for (it = v.begin(); it != v.end(); it++) { 
        if ((*it) == 1) 
            number += base; 
        base = base * 2; 
    } 
    return number; 
}

void createtrie(vector<ll> v)
{
	if(root == NULL)
	{
	//	cout<<"root"<<endl;
		root = new Node();
		root->data = 2;
		root->left = NULL;
		root->right = NULL;
	}
	Node* ptr = root;
	for(auto i = v.begin(); i!= v.end(); i++)
	{
	//	cout<<"root data "<<root->data<<endl;
		if((*i) == 0)
		{
		//	cout<<"here o"<<endl;
			if(ptr->left == NULL)
			{
				ptr->left = new Node();
				ptr = ptr->left;
				ptr->right = NULL;
				ptr->left = NULL;
				ptr->data = (*i);
			}
			else
				ptr = ptr->left;
		}
		if((*i) == 1)
		{
		//	cout<<"here 1"<<endl;
			if(ptr->right == NULL)
			{
				ptr->right = new Node();
				ptr = ptr->right;
				ptr->right = NULL;
				ptr->left = NULL;
				ptr->data = (*i);			
			}
			else
				ptr = ptr->right;
		}
	}
}

void findxor(vector<ll> x)
{
	Node *ptr = root;
	for(auto i=x.begin(); i!=x.end();i++)
	{
		//ptr = findxorutil((*i),ptr);
		if((*i) == 1)
		{
			if(ptr->left == NULL)
			{
				ptr = ptr->right;
				ll r = (*i)^ptr->data;
				res.push_back(r);
			}
			else
			{
				ptr = ptr->left;
				ll r = (*i)^ptr->data;
				res.push_back(r);
			}
		}
		if((*i) == 0)
		{
			if(ptr->right == NULL)
			{
				ptr = ptr->left;
				ll r = (*i)^ptr->data;
				res.push_back(r);
			}
			else
			{
				ptr = ptr->right;
				ll r = (*i)^ptr->data;
				res.push_back(r);
			}
		}
	}
}

void display(Node* ptr)
{
	if(ptr != NULL)
	{
		display(ptr->left);
		cout<<ptr->data<<" ";
		display(ptr->right);
	}
}

int main()
{
	ll n;
	cin>>n;
	ll q;
	cin>>q;
	for(ll i =0; i < n; i++)
	{
		ll num;
		cin>>num;
		vector<ll> v = decimaltobinary(num);
		// for(auto i=v.begin(); i!=v.end();i++)
		// {
		// //	cout<<(*i)<<" ";
		// }
	//	cout<<endl;
		createtrie(v);
	}
//	display(root);
	//cout<<endl;
	while(q--)
	{
		ll xorele;
		cin>>xorele;
		vector<ll> x = decimaltobinary(xorele);
		// for(auto i=x.begin(); i!=x.end();i++)
		// {
		// //	cout<<(*i)<<" ";
		// }
		//cout<<endl;
		findxor(x);
		// for(auto i=res.begin(); i!=res.end();i++)
		// {
		// //	cout<<(*i)<<" ";
		// }
		//cout<<endl;
		ll decimal = binarytodecimal(res);
		res.clear();
		cout<<decimal<<endl;
	}
}