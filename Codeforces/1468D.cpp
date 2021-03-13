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
ll s[300000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        ll n,m,a,b;
        cin>>n>>m>>a>>b;
        if(a>b){
            a=n-a+1;
            b=n-b+1;
        }
        for(int i=0;i<m;i++)
            cin>>s[i];
        sort(s,s+m);
        ll ans=0;
        ll val=0;
        for(ll i=0;i<min(m,b-a-1);i++){
            val=max(val+1,s[i]+1);
            if(val<=b-1)
                ans=i+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}