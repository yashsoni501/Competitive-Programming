#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll ans=1e9;
ll ar[10];

void solve(ll sum, ll ind)
{
    if(ind==10)
    {
        if(abs(sum-100)<abs(ans-100))
        {
            ans=sum;
        }
        else if(abs(sum-100)==abs(ans-100))
        {
            ans=max(sum,ans);
        }
        return;
    }
    solve(sum,ind+1);
    solve(sum+ar[ind],ind+1);
}

int main()
{
    IOS
    REP(i,10)   cin>>ar[i];
    solve(0,0);
    cout<<ans<<endl;
}