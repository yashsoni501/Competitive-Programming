#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define MOD 1000000007
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define prv(a) for(auto x : a) cout << x << ' ';cout << '\n';
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define OTP(s) cout<<s<<endl;
#define FOR(i,j,k,l) for(int i=j;i<k;i+=l)
#define REP(i,j) FOR(i,0,j,1)
inline ll add(ll a, ll b){a += b; if(a >= MOD)a -= MOD; return a;}
inline ll sub(ll a, ll b){a -= b; if(a < 0)a += MOD; return a;}
inline ll mul(ll a, ll b){return (ll)((ll) a * b %MOD);}
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}

ll fact[1000005],ifact[1000005];

ll ncr(ll n, ll r)
{
    return (((fact[n]*ifact[r])%MOD)*ifact[n-r])%MOD;
}
ll npr(ll n, ll r)
{
    return (fact[n]*ifact[n-r])%MOD;
}
ll binpow(ll a, ll b, ll m=MOD) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void computeFact(ll maxComputeFact)
{
    fact[0]=1;
    ifact[0]=1;

    FOR(i,1,maxComputeFact,1)
    {
        fact[i] = (fact[i-1]*i)%MOD;
        ifact[i] = binpow(fact[i],MOD-2,MOD);
    }
}

int main()
{
    IOS
    computeFact(1000003);
    ll t,n,k,g;

    cin>>t;
    while(t--)
    {
        cin>>n>>k>>g;
        // cout<<(((((fact[n-k-g]*fact[n-1]-fact[n-k-1]*fact[n-g])%MOD)+MOD)%MOD)*((ifact[n-k-g]*ifact[n-1])%MOD))%MOD<<endl;
        
        ll num = ncr(n-k-1,g-1);
        ll den =  binpow(ncr(n-1,g-1),MOD-2,MOD);
        cout<< (((1-(num*den)%MOD)%MOD)+MOD)%MOD<<endl;
    }
}