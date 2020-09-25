#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n,q;
ll ar[500],qu[500][2];

bool bet(int i,int x)
{
    if(x>=qu[i][0]&&x<=qu[i][1])
        return 1;
    return 0;
}

ll comp(int a,int b)
{
    ll sum=0;
    for(int i=0;i<q;i++)
    {
        if(bet(i,a)&&(!(bet(i,b))))
        {
            sum++;
            cout<<"sum"<<sum<<endl;
        }
    }
    return ar[b-1]-ar[a-1]+sum;
}

int main()
{
	ll n,q;
	cin>>n>>q;
	ll ar[n],query[q][2];
	for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(int i=0;i<q;i++)
    {
        cin>>qu[i][0]>>qu[i][1];
    }

    int ma=-1e9,m1,m2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ll m=comp(i+1,j+1);
            if(m>ma)
            {
                ma=m;
                m1=i;
                m2=j;
            }
        }
    }

    cout<<ma<<endl;

}
