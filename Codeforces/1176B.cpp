#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll t,n,a[1000];

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        REP(i,n) cin>>a[i];
        ll ar[3]={};
        REP(i,n)
        {
            ar[a[i]%3]++;
        }
        ll ans=0;
        ans+=ar[0];
        ll tmp=min(ar[1],ar[2]);
        ar[1]-=tmp;
        ar[2]-=tmp;
        ans+=tmp;
        ans+=ar[1]/3;
        ans+=ar[2]/3;
        cout<<ans<<endl;
    }

}
