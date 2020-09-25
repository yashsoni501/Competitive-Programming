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

ll t,n;
vector<vector<ll>> adj;
bool vis[120000];
string s;

ll par[2];
pll dfs1(ll nd, ll dep)
{
    pll cnt={0,0};
    vis[nd] = 1;
    par[dep%2]++;
    if((dep%2 == 0 && s[nd]=='0'))
    {
        cnt.ff++;
    }
    if((dep%2 == 1 && s[nd]=='1'))
    {
        cnt.ss++;
    }
    for(auto it:adj[nd])
    {
        if(!vis[it])
        {
            pll tmp=dfs1(it, dep+1);
            cnt.ff+=tmp.ff;
            cnt.ss+=tmp.ss;
        }
    }
    return cnt;
}

pll dfs2(ll nd, ll dep, ll ps)  // sgn,dst
{
    vis[nd]=1;
    ll sgn = 0, dst = 0;
    if((dep+ps)%2 != s[nd]-'0')
    {
        if(s[nd]=='0')
        {
            sgn = -1;
        }
        else
        {
            sgn = 1;
        }        
    }
    for(auto it:adj[nd])
    {
        if(!vis[it])
        {
            pll tmp = dfs2(it,dep+1,ps);
            sgn += tmp.ff;           
            dst += tmp.ss;
        }
    }
    return {sgn, abs(sgn)+dst};
}

ll check(ll ps)
{
    REP(i,n)
    {
        vis[i]=0;
    }
    pll tmp = dfs2(0,0,ps);
    // trace(tmp.ff)   trace(tmp.ss)
    return tmp.ss;
}

signed main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        adj.clear();
        REP(i,n)
        {
            vis[i] = 0;
            adj.pb(vector<ll>());
        }
        ll x,y;
        REP(i,n-1)
        {
            cin>>x>>y;
            x--,y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        cin>>s;
        // s = "."+s;
        // trace(s)
        ll red = count(all(s), '0');
        ll blue = count(all(s), '1');
        par[0] = par[1] = 0;
        pll cnt = dfs1(0, 0);
        // trace(par[0])   trace(par[1])   trace(red)  trace(blue)
        // cout<<cnt.ff<<" "<<cnt.ss<<endl;
        ll ans = 1e9;
        if(red == blue && red == par[0] && par[0]==par[1])
        {
            ans = min(check(1),check(0));

        }
        else if((par[0] == red && par[1] == blue))
        {
            ans = check(0);
        }
        else if (par[0]==blue && par[1] == red)
        {
            ans = check(1);
        }
        else
        {
            ans = -1;
        }
        
        cout<<ans<<endl;
    }
}