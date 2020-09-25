#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef long long int ll;

ll summer(ll a)
{
    if (a==0)
        return 0;
    ll terms=floor(log(a)/log(2));
    ll odd=0;
    ll even=0;
    ll ein=1;
    for (int i=0;i<terms+1;i+=2)
    {
        even=(ein+even)%mod;
        ein=(ein*4)%mod;
    }
    ll oin=2;
    for (int i=1;i<terms+1;i+=2)
    {
        odd=(odd+oin)%mod;
        oin=(oin*4)%mod;
    }
    if(terms%2==0)
        even=(even+a-(ll)(pow(2,terms+1)+1))%mod;
    else
        odd=(odd+a-(ll)(pow(2,terms+1)+1))%mod;
        
    ll ans=(even*even)%mod;
    ans=(ans+odd*(odd+1))%mod;
    cout<<a<<" "<<even<<" "<<odd<<" "<<ans<<endl;
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll l,r;
    cin>>l>>r;
    ll ans=(summer(r)-summer(l-1))%mod;
    cout<<ans<<endl;

}