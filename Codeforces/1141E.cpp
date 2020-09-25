#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll sum,arr[1000000],ar[1000000],h;

bool fun(ll x,ll ind)
{
	ll t=h+x*sum+arr[ind];
	if(x<=0)
		return 1;
	return 0;
}

ll binary(ll low,ll high,ll ind)
{
	if(low==high)
	{
		return low;
	}
	ll mid=(high+low)/2;
	if(fun(mid,ind))
	{
		return binary(low,mid,ind);
	}
	else
	{
		return binary(mid+1,high,ind);
	}
}

int main()
{
	ll n;
	cin>>h>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=ar[i];
		arr[i]=sum;
	}
	
	if(sum>=0)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	ll cost[n];
	for(int i=0;i<n;i++)
	{
		cost[i] = n*max(0.0,ceil(h-arr[i]/sum))+i+1;
	}
	
	ll mi=1e18;
	for(int i=0;i<n;i++)
	{
		cout<<cost[i]<<" ";
		mi=min(mi,cost[i]);
	}
	cout<<endl;
	
	cout<<mi<<endl;
}
