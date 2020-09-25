#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;
ll a[1000000],b[1000000];

int main()
{
    IOS
    ll n;
    cin>>n;
    REP(i,n)
    {
        cin>>a[i];
    }
    bool o=0,e=0;
    REP(i,n)
    {
        if(a[i]%2)
            o=1;
        else
            e=1;
    }
    if(!o||!e)
    {
        REP(i,n)
            cout<<a[i]<<" ";
        return 0;
    }
    sort(a,a+n);
    REP(i,n)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}