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
set<ll> adj[100050];
bool vis[100050];
vector<vl> conComp;
ll compcnt=0;
ll par[100050];
vector<tuple<ll,ll,ll>> ans;

void dfs(ll x)
{
    vis[x]=1;
    conComp[compcnt].pb(x);
    // trace(x)
    for(auto it:adj[x])
    {
        if(!vis[it])
        {
            dfs(it);
            par[it]=x;
        }
    }
}

void postorder(ll x)
{
    // trace(x)
    ll parent = par[x];
    vl child;
    for(auto it:adj[x])
    {
        if(par[it]==x)
        {
            child.pb(it);
        }
    }
    for(auto it:child)
    {
        postorder(it);
    }
    child.clear();
    adj[x].erase(parent);
    for(auto it:adj[x])
    {
        if(it!=par[x])
            child.pb(it);
    }
    ll a,b;
    for(int i=0;i<sz(child)-1;i+=2)
    {
        a = child[i];
        b = child[i+1];
        ans.pb(make_tuple(a,x,b));
        adj[a].erase(x);
        adj[x].erase(a);
        adj[b].erase(x);
        adj[x].erase(b);
    }
    if(sz(child)%2==1)
    {
        // cout<<"here\n";
        if(par[x]==x)   return;
        a = child[sz(child)-1];
        b = parent;
        ans.pb(make_tuple(a,x,b));
        adj[a].erase(x);
        adj[x].erase(a);
        adj[b].erase(x);
        adj[x].erase(b);
    }
    // trace(x)
}

void solve(vl &comp)
{
    par[comp[0]] = comp[0];
    postorder(comp[0]);
}

int main()
{
    // IOS
    cin>>n>>m;
    ll a,b;
    REP(i,m)
    {
        cin>>a>>b;
        adj[a-1].in(b-1);
        adj[b-1].in(a-1);
    }
    // cout<<"here\n";
    REP(i,n)
    {
        if(vis[i])  continue;
        conComp.pb(vector<ll>());
        dfs(i);
        compcnt++;
    }
    // trace(compcnt)
    REP(i,compcnt)
    {
        // trace(i)
        solve(conComp[i]);
    }
    cout<<sz(ans)<<endl;
    for(auto it:ans)
    {
        cout<<get<0>(it)+1<<" "<<get<1>(it)+1<<" "<<get<2>(it)+1<<endl;
    }
}