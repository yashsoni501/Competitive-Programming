#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n,k;
map<pair<ll,ll> ,ll> mp;
bool ar[100005]={};
/*bool pres(pair g)
{
    if(mp.find(g)==mp.end())
    {
        return 1;
    }
    return 0;
}
*/
int main()
{
    IOS
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        ll t;
        cin>>t;
        ar[t]=1;
        mp[make_pair(t,t)]=1;
        if(t!=1 && ar[t-1])
        {
            mp[make_pair(t,t-1)]=1;
        }
        if(t!=n && ar[t+1])
        {
            mp[make_pair(t,t+1)]=1;
        }
    }
    cout<<3*n-2-mp.size();
}