#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a!=c)
            cout<<a<<" "<<c<<endl;
        else if(b!=d)
            cout<<b<<" "<<d<<endl;
        else
            cout<<a<<" "<<d<<endl;

    }
}
