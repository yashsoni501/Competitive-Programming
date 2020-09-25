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

ll n,m;
vl adj[150000];
ll dp[100005];

ll val(int i)
{
    if(dp[i]!=-1)
        return dp[i];
    if(sz(adj[i])==0)
    {
        return 1;
    }
    ll ma = val(adj[i][0]);
    REP(j,sz(adj[i]))
    {
        ma = max(ma,val(adj[i][j]));
    }
    dp[i] = ma+1;
    return ma+1;
}

int main()
{
    IOS
    cin>>n>>m;
    memset(dp,-1,(n+1)*sizeof(dp[0]));
    REP(i,m)
    {
        ll x,y;
        cin>>x>>y;
        adj[y].pb(x);
    }
    for(int i=1;i<n+1;i++)
    {
        if(dp[i]==-1)
        {
            dp[i] = val(i);
        }
    }
    ll ma=dp[1];
    REP(i,n)
    {
        // cout<<dp[i+1]<<" ";
        ma = max(ma,dp[i+1]);
    }
    // cout<<endl;
    cout<<ma-1<<endl;
}