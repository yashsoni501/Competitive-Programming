#include<iostream>
using namespace std;

typedef long long int ll;

int main()
{
	ll n;
	cin>>n;
	int arr[2*n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		arr[n+i]=arr[i];
	}
	
	ll ma=0;
	for(int i=0;i<2*n;i++)
	{
		ll cnt=0;
		int j=i;
		if(arr[i])
		{
			while(arr[j]==arr[i]&&i<2*n)
			{
				cnt++;
				i++;
			}
			ma=max(cnt,ma);
		}
	}
	cout<<ma<<endl;
}
