#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
typedef long long int ll;

int main()
{
    IOS
    ll n;
    cin>>n;
    cout<<n/2+1<<endl;
    for(int i=0;i<n/2;i++)
    {
        cout<<1<<" "<<i+1<<endl;
    }
    for(int i=n/2;i<n;i++)
    {
        cout<<n/2+1<<" "<<i-n/2+1+(n+1)%2<<endl;
    }
}
