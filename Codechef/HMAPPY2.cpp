#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;

ll gcd(ll a,ll b)
{
    if(a==0)
    {
        return b;
    }
    return gcd(b%a,a);
}

ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,n,k,a,b;
    cin>>t;

    while(t--)
    {
        cin>>n>>a>>b>>k;
        ll num=n/a-n/lcm(a,b);
        num+=n/b-n/lcm(a,b);
        //cout<<num<<endl;
        if(num<k)
        {
            cout<<"Lose"<<endl;
        }
        else
        {
            cout<<"Win"<<endl;
        }
    }
}
