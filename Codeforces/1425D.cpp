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
    if(n<r) return 0;
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

ll n,m,r;
ll x,y,b;
vpll vt;
vl bi;
set<ll> adj[3000];
ll com[3000][3000];
ll func(ll y,ll x)
{
    return sub(ncr(y,m),ncr(y-x,m));
}

ll diff(set<ll> &a, set<ll> &b)
{
    set<ll> tmp;
    for(auto it:a)
    {
        tmp.in(it);
    }
    for(auto it:b)
    {
        tmp.in(it);
    }
    return sz(a)+sz(b)-sz(tmp);
}
ll dp[1001][1001];
void calc(vector <pair<ll,ll>> &v,ll r){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<v.size();i++){
        dp[v[i].ff][v[i].ss]=1;
    }
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++)
            dp[i][j]+=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
    }
    // REP(i,n+1)    
    // {
    //     REP(j,n+1)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll xx1=v[i].ff, xx2=v[j].ff, yy1=v[i].ss,yy2=v[j].ss;
 
            if(min(xx1,xx2)+r<max(xx1,xx2)-r || min(yy1,yy2)+r<max(yy1,yy2)-r)
            {
                com[i][j] = 0;
                continue;
            }            
            else
            {
                ll xz[4] = {xx1+r,xx2+r,xx1-r,xx2-r};
                ll yz[4] = {yy1+r,yy2+r,yy1-r,yy2-r};
                sort(xz,xz+4);
                sort(yz,yz+4);
                
                ll x1 = max(1,xz[1]), x2 = min(1000,xz[2]);
                ll y1 = max(1,yz[1]), y2 = min(1000,yz[2]);
                com[i][j] = dp[x2][y2]+dp[x1-1][y1-1]-dp[x1-1][y2]-dp[x2][y1-1];
            }
        }
    }
} 
int main()
{
    IOS
    computeFact(3000);
    cin>>n>>m>>r;
    REP(i,n)
    {
        cin>>x>>y>>b;
        vt.pb({x,y});
        bi.pb(b);       
    }
    REP(i,n)
    {
        REP(j,n)
        {
            if(max(abs(vt[i].ff-vt[j].ff), abs(vt[i].ss-vt[j].ss)) <= r)
            {
                adj[i].in(j);
                adj[j].in(i);
            }
        }
    }
    // REP(i,n)
    // {
    //     REP(j,n)
    //     {
    //         com[i][j] = diff(adj[i],adj[j]);
    //     }
    // }
    calc(vt,r);
    ll ans = 0;
    // REP(i,n)
    // {
    //     ll tmp = sz(adj[i]);
    //     ans = add(ans,mul(sub(ncr(n,m),ncr(n-tmp,m)),bi[i]*bi[i]));
    // }
    // cout<<ans<<endl;
    // REP(i,n)
    // {
    //     REP(j,n)
    //     {
    //         cout<<com[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    REP(i,n)
    {
        REP(j,n)
        {
            // if(i==j)    continue;
            // trace()
            // trace((ncr(n,m)-(func(sz(adj[i])-com[i][j])+func(sz(adj[j])-com[i][j])+ncr(n-(sz(adj[i])+sz(adj[j])-com[i][j]),m)))
            // trace(ncr(n,m)-(func(n-adj[j],sz(adj[i])-com[i][j])+func(n-adj[i[,sz(adj[j])-com[i][j])+ncr(n-(sz(adj[i])+sz(adj[j])-com[i][j]),m)))
            // trace(func(sz(adj[i])-com[i][j]))
            // trace(func(sz(adj[j])-com[i][j]))
            // trace(ncr(n-(sz(adj[i])+sz(adj[j])-com[i][j]),m))
            ll x1 = add(add(func(n-sz(adj[j]),sz(adj[i])-com[i][j]),func(n-sz(adj[i]),sz(adj[j])-com[i][j])),ncr(n-(sz(adj[i])+sz(adj[j])-com[i][j]),m));
            ans = add(ans,mul(mul(bi[i],bi[j]),sub(ncr(n,m),x1)));
        }
    }
    cout<<ans<<endl;
}