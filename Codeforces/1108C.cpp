#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int min(int a,int b,int c)
{
    return min(min(a,b),c);
}

char prnt(char a)
{
	if(a=='0')
		return 'R';
	if(a=='1')
		return 'G';
	if(a=='2')
		return 'B';
}


int main()
{
	//0R 1G 2B
    string s;
    ll n;
    cin>>n;
    cin>>s;
    int ar[3][3]={};
    for(int i=0;i<3;i++)
    {
    	for(int j=i;j<n;j+=3)
    	{
    		if(s[j]=='R')
    			ar[i][0]++;
			else if(s[j]=='G')
    			ar[i][1]++;
    		else
    			ar[i][2]++;
		}
	}
	string cases[6]={"012","021","201","210","120","102"};
	int mx=-1;
	int ind=-1;
	for(int i=0;i<6;i++)
	{
		int cnt=0;
		for(int j=0;j<3;j++)
			cnt+=ar[j][cases[i][j]-48];
		if(mx<cnt)
		{
			mx=cnt;
			ind=i;
		}
		
	}
	cout<<n-mx<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<prnt(cases[ind][i%3]);
	}
	cout<<endl;

}

