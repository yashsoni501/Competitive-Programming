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

ll t,n,a,b;
set<ll> adj[100006];
bool vis[100005];
ll par[100006];
vector<pair<pll,pll>> ans;

ll dfs(ll x)
{
    stack<pll> st;
    bool vst = vis[x];
    // vis[x]=!vst;
    st.push({x,0});
    ll ind=x, dst=0;
    while(!st.empty())
    {
        pll top = st.top();
        st.pop();
        vis[top.ff]=!vst;
        if(top.ss>dst) dst=top.ss, ind=top.ff;
        for(auto it:adj[top.ff])
        {
            if(vis[it]==vst)
            {
                st.push({it,top.ss+1});
                par[it]=top.ff;
            }
        }
    }
    return ind;
}

vl bt(ll a, ll b)
{
    vl path;
    ll ind = a;
    while(ind != b)
    {
        path.pb(ind);
        ind = par[ind];
    }
    path.pb(b);
    reverse(all(path));
    return path;
}
pll solver(vl &path);
pll solve(ll ind)
{
    // trace(ind)
    // prv(adj[ind])
    ll it = dfs(ind);
    // trace(it)
    ll it2 = dfs(it);
    // trace(it2)
    vl path = bt(it2, it);
    // prv(path)
    pll ret = solver(path);
    // trace(ret.ff)
    // trace(ret.ss)
    return ret;
}

pll solver(vl &path)
{
    ll hd = path[0];
    for(int i=1;i<sz(path)-1;i++)
    {
        for(auto it:adj[path[i]])
        {
            if(it==path[i+1] || path[i-1]==it)   continue;
            adj[it].erase(path[i]);
            pll aa = solve(it);
            ans.pb({{it,path[i]},{hd,aa.ss}});
            hd = aa.ff;
        }
    }
    // trace(hd)
    // trace(path[sz(path)-1])
    return {hd, path[sz(path)-1]};
}

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        REP(i,n+1)  adj[i].clear();
        ans.clear();
        REP(i,n-1)
        {
            cin>>a>>b;
            adj[a-1].in(b-1);
            adj[b-1].in(a-1);
        }
        REP(i,n+1)  vis[i]=0;
        solve(0);
        // cout<<"ans\n";
        cout<<sz(ans)<<endl;
        for(auto it:ans)
        {
            cout<<it.ff.ff+1<<" "<<it.ff.ss+1<<" "<<it.ss.ff+1<<" "<<it.ss.ss+1<<endl;
        }
    }
}