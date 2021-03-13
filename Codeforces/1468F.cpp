#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ff first
#define ss second
typedef long long ll;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector <pair<ll,ll>> v2;
        vector <pair<ll,ll>> v1;
        for(int i=0;i<n;i++){
            ll x,y;
            ll u,v;
            cin>>x>>y>>u>>v;
            ll val=gcd(abs(u-x),abs(v-y));
            ll x1=(u-x)/val;
            ll y1=(v-y)/val;
            v2.push_back({x1,y1});
            v1.push_back({-x1,-y1});
        }
        sort(v2.begin(),v2.end());
        sort(v1.begin(),v1.end());
        ll j=0;
        ll ans=0ll;
        for(ll i=0;i<n;i++){
            ll k=i;
            while(k<n&&v2[i]==v2[k])
                k++;
            while(j<n&&v1[j].ff<v2[i].ff)
                j++;
            while(j<n&&v1[j].ff==v2[i].ff&&v1[j].ss<v2[i].ss)
                j++;
            ll l=j;
            while(l<n&&v1[l]==v2[i])
                l++;
            ans+=(l-j)*(k-i);
            j=l;
            i=k-1;
        }
        ans/=2;
        cout<<ans<<"\n";
    }
    return 0;
}