#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ll n;
	cin>>n;
	ll p[n],ar[n],arr[n];
	ll sum=0;
	for(int i=0;i<n-1;i++)
	{
		cin>>p[i];
	}
	
	ar[0]=0;
	for(int i=1;i<n;i++)
	{
		ar[i]=p[i-1]+ar[i-1];
	}
	
	ll mi=1e10;
	for(int i=0;i<n;i++)
	{
		mi=min(mi,ar[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		ar[i]+=mi+1;
		arr[i]=ar[i];
	}
	sort(ar,ar+n);
	bool b=1;
	for(int i=0;i<n;i++)
	{
		if(ar[i]!=i+1)
		{
			b=0;
			break;
		}
	}
	
	if(!b)
	{
		cout<<-1<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}
