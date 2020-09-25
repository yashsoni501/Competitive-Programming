#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
#define MOD 1000000007
typedef long long int ll;
ll n,k;

ll modPower(ll a, ll b) // return a^b % MOD where MOD is defined globally
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b%2 == 0)
    {
        ll tmp = modPower(a,b/2);
        return (tmp*tmp)%MOD;
    }
    else
    {
        ll tmp = modPower(a,(b-1)/2);
        return (((tmp*tmp)%MOD)*a)%MOD;
    }
}

int main()
{
    IOS
    //cin>>n>>k;
    cout<<modPower(1223,2421345)<<endl;
}