#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll ar[1000000];
int main()
{
    IOS
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        REP(i,n)
        {
            cin>>ar[i];
        }
        ll mi=1e10;
        sort(ar,ar+n);
        ll ans;
        //ll ki=(k+1)/2,ans;
        //cout<<"ki "<<ki<<endl;
        REP(i,n-k)
        {
            if((ar[i+k]-ar[i]) < mi)
            {
                mi = ar[i+k]-ar[i];
                ans = (ar[i+k]+ar[i])/2;
            }

        }
        cout<<ans<<endl;
    }
}