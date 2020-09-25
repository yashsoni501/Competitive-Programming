#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

int main()
{
    IOS
    ll n,m;
    cin>>n>>m;
    if(m==0 || m==1)
    {
        cout<<1<<endl;
        return 0;
    }   
    if(m<=n/2)
    {
        cout<<m<<endl;
    }
    else
    {
        cout<<n-m<<endl;
    }
}