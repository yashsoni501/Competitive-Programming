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

char cast(char a)
{
	if(a=='R')
		return '0';
	if(a=='G')
		return '1';
	return '2';
}

char cast2(char a)
{
	if(a=='0')
		return 'R';
	if(a=='1')
		return 'G';
	return 'B';		
}

char change(string s, int i,int n)
{
	if(i==n-1)
	{
		return cast2((cast(s[i])-48+1)%3+48);
	}
	else
	{
		if(s[i+1]!=cast2((cast(s[i])-48+1)%3+48))
			return cast2((cast(s[i])-48+1)%3+48);
		else
			return cast2((cast(s[i])-48+2)%3+48);
	}
}

int main()
{
	//0R 1G 2B
    string s;
    ll n;
    cin>>n;
    cin>>s;
    string t=s;
    int ind=0;
    ll stp=0;
    
    while(ind<n)
    {
    	int cnt=0;
    	for(int i=ind;s[ind]==s[i];i++)
    		cnt++;
    	if(cnt>=2)
    	{
    		for(int i=ind+1;i<ind+cnt;i+=2)
    		{
    			t[i]=change(s,i,n);
    			stp++;
			}
		}
		ind+=cnt;
	}
	
	cout<<stp<<endl;
	cout<<t<<endl;

}

