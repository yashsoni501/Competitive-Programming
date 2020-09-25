#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t,n,k,m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n>>k>>m;
    }

    ll p,q;
    if(m%2)
    {
        p=m+1;
        q=2*n;
    }
    else
    {
        p=m*(n+k)+2*n;
        q=2*n*(n+k);
    }

    ll gcd=__gcd(p,q);
    p/=gcd;
    q/=gcd;


}
