#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;

ll po(ll i)
{
    return pow(2,i)+0.5;
}

int main()
{
    IOS
    ll n;
    cin>>n;
    ll ans=0;
    
    if(n%2==1)
    {
        ans=0;
    } 
    else
    {
        ans=po(n/2);
    }
    
    cout<<ans<<endl;
}