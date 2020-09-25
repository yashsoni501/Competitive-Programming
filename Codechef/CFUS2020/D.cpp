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
#define MOD 998244353
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
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll t=1;
ll n,m,x1,yy1,x2,y2;
ll fact[200000],ifact[200000];

ll ncr(ll n, ll r)
{
    return (((fact[n]*ifact[r])%MOD)*ifact[n-r])%MOD;
}

int main()
{
    IOS
    fact[0]=1;
    ifact[0]=1;
    
    FOR(i,1,100005,1)
    {
        fact[i] = (fact[i-1]*i)%MOD;
        ifact[i] = binpow(fact[i],MOD-2,MOD);
    }
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x1>>yy1>>x2>>y2;
        ll a = ncr(n+m,n);
        ll b = mul(ncr(x1+yy1,x1),ncr(n+m-x1-yy1, n-x1));
        ll c = mul(ncr(x2+y2,x2),ncr(n+m-x2-y2, n-x2));
        ll d = mul(ncr(x2-x1+y2-yy1,x2-x1), mul(ncr(x1+yy1,x1),ncr(n+m-x2-y2, n-x2)));
        cout<<sub(add(a,d),add(b,c))<<endl;
    }
}