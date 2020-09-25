#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll n;
ll a[1000000];
ll b[1000000];

int main()
{
    IOS
    cin>>n;
    REP(i,n)
    {
        cin>>a[i];
    }   
    sort(a,a+n);
    b[0]=1;
    FOR(i,1,n,1)
    {
        b[i]=min(b[i-1]+1,a[i]);
    }
    ll ma=-1;
    REP(i,n)
    {
        ma=max(ma,b[i]);
    }
    cout<<ma<<endl;

}