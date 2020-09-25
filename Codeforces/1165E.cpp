#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
#define MOD 998244353
typedef long long int ll;
ll n;
ll a[1000000],b[1000000];

int main()
{
    IOS
    cin>>n;
    REP(i,n)
    {
        cin>>a[i];
        a[i]*=(n+i*(n-1-i));
    }
    REP(i,n)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);

    ll ans=0;
    REP(i,n)
    {
        ans=(ans+(((a[i])%MOD)*b[n-1-i])%MOD)%MOD;
    }
    cout<<ans<<endl;

}