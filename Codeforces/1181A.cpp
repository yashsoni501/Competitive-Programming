#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define OTP(s) cout<<s<<endl;
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;

int main()
{
    IOS
    ll x,y,z;
    cin>>x>>y>>z;
    cout<<(x+y)/z<<" ";
    if(x/z+y/z<(x+y)/z)
    {
        cout<<min(z-x%z,z-y%z)<<endl;
    }   
    else
    {
        cout<<0<<endl;
    }
    
}