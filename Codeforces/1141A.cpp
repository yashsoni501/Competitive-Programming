#include<iostream>

using namespace std;

typedef long long int ll;

int main()
{
    ll n,m;
    cin>>n>>m;
    if(m%n)
    {
    	cout<<-1<<endl;
    	return 0;
	}
	
	m/=n;
	int cnt=0;
	while(m%2==0)
	{
		m/=2;
		cnt++;
	}
	while(m%3==0)
	{
		m/=3;
		cnt++;
	}
	if(m!=1)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<cnt<<endl;
	}
}
