#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n,h,m;
ll ar[50];
int main()
{
    IOS
    cin>>n>>h>>m;
    REP(i,n) ar[i]=h;
    REP(i,m)
    {
        ll t,q,p;
        cin>>t>>q>>p;
        FOR(j,t-1,q,1)
        {
            ar[j]=min(ar[j],p);
        }
    }
    ll sum=0;
    REP(i,n)
    {
        sum+= ar[i]*ar[i];
    }
    cout<<sum<<endl;
}