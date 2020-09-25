#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll t,n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>t;
    ll a[n][2];
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    ll mi=1e10,ind=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i][0]>=t)
        {
            if(mi>a[i][0]-t)
            {
                //cout<<mi<<" "<<ind<<endl;
                mi=a[i][0]-t;
                ind = i+1;
            }
        }
        else
        {
            ll x=((a[i][0]-t)%a[i][1]+a[i][1])%(a[i][1]);
            if(mi>x)
            {
                mi=x;
                ind=i+1;
            }
        }
    }
    cout<<ind<<endl;
}
