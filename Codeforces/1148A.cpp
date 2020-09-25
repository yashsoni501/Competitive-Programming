#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;

int main()
{
    IOS
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans=2*c;
    ans+=2*min(a,b);
    if(b!=a)
    {
        ans++;
    }
    cout<<ans<<endl;
}