#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll f(ll x)
{
    x++;
    while(x%10==0)
    {
        x/=10;
    }
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin>>n;
    ll cnt=9;
    bool boo=1;
    while(n>=10)
    {
        if(n==1)
            boo=0;
        n=f(n);
        
        cnt++;
    }
    cout<<cnt<<endl;

}