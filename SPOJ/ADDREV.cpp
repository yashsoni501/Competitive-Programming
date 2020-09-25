#include<iostream>
using namespace std;

typedef long long int ll;


ll rever(ll n)
{
    ll t=0;
    while(n)
    {
        t=10*t+n%10;
        n/=10;
    }
    return t;
}

int main()
{
    int t;
    cin>>t;
    ll a,b;
    while(t--)
    {
        cin>>a>>b;
        cout<<rever(rever(a)+rever(b))<<endl;
    }
}
