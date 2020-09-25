#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n,k,a[1000000];
ll f[1000000];
int main()
{
    IOS
    cin>>n>>k;
    ll k2=k;
    REP(i,n)
    {
        cin>>a[i];
    }
    ll pos=2;
    k--;
    f[0]=1;
    for(int i=1;i<min(n,n-k);i++)
    {
        if(a[i]<=0)
        {
            f[i]=f[i-1];
        }
        else
        {
            f[i]=pos;
            pos++;
            k--;
        }
    }
    for(int i=n-k;i<n;i++)
    {
        f[i]=pos++;
    }

    REP(i,n)
    {
        if(f[i]>k2)
            f[i]=k2;
    }
    ll sum=0;
    REP(i,n)
    {
        cout<<f[i]<<" ";
        sum+=f[i]*a[i];
    }
    cout<<endl;
    cout<<sum<<endl;
}