#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
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

ll t,n,a[300000],c,d,q,u,v;
ll f[200010][2],cf[200010];
bool vis[200010];
vector<vl> adj;

void dfsf(ll ind, ll par, ll s)
{
    if(vis[ind])    return;
    vis[ind]=1;
    f[ind][par]=s;
    if(a[ind]%2==par)   f[ind][par]+=a[ind];
    for(auto it:adj[ind])
    {
        dfsf(it,par,f[ind][par]);
    }
}
void dfscf(ll ind, ll s)
{
    if(vis[ind])    return;
    vis[ind]=1;
    cf[ind]=s+f[ind][a[ind]%2];
    for(auto it:adj[ind])
    {
        dfscf(it,cf[ind]);
    }
}
struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

signed main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        REP(i,n+1)  adj.pb(vector<ll>());
        REP(i,n)    cin>>a[i+1];
        REP(i,n-1)
        {
            cin>>c>>d;
            adj[c].pb(d);
            adj[d].pb(c);
        }
        LCA lca(adj,1);
        REP(i,n+1)  vis[i]=0;
        dfsf(1,0,0);
        REP(i,n+1)  vis[i]=0;
        dfsf(1,1,0);

        REP(i,n+1)  vis[i]=0;
        dfscf(1,0);

        cin>>q;
        while(q--)
        {
            cin>>u>>v;
            ll tmp = lca.lca(u,v);
            cout<<cf[u]+cf[v]-2*cf[tmp]+f[tmp][a[tmp]%2]<<endl;
        }
        // REP(i,n)    cout<<f[i+1][0]<<" ";
        // cout<<endl;
        // REP(i,n)    cout<<f[i+1][1]<<" ";
        // cout<<endl;
        // REP(i,n)    cout<<cf[i+1]<<" ";
        // cout<<endl;
    }   
}