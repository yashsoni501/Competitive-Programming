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
#define int ll
ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}

ll n,m,k;
vector<vl> adj;
ll par[300000];

bool vis[300000];
ll depth[300000];

map<pll,ll> ma;
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


void dfs(ll ind, ll dep)
{
    if(vis[ind])    return;
    vis[ind] = 1;
    depth[ind] = dep;
    REP(i,sz(adj[ind]))
    {
        if(!vis[adj[ind][i]])
        {
            par[adj[ind][i]] = ind;
        }
    }
    REP(i,sz(adj[ind]))
    {
        if(!vis[adj[ind][i]])   dfs(adj[ind][i],dep+1);
    }
}

signed main()
{
    IOS
    cin>>n>>m;
    REP(i,n+1)  adj.pb(vector<int>());
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    set<ll> st;
    map<ll,ll> dt;
    vl vt;
    dfs(1,1);
    par[1] = 0;
    LCA lca(adj, 1);
    while(m--)
    {
        st.clear();
        dt.clear();
        cin>>k;
        REP(i,k)
        {
            ll tmp;
            cin>>tmp;
            if(tmp!=1)
                st.insert(par[tmp]);
        }
        if(sz(st)==0)   
        {
            cout<<"YES\n";
            continue;
        }
        bool boo=0;
        for(auto i:st)
        {
            if(dt.find(depth[i])!=dt.end())
            {
                boo=1;
                break;
            }
            dt[depth[i]] = i;
        }
        if(boo)
        {
            cout<<"NO\n";
            continue;
        }

        vt.clear();
        for(auto i:dt)
        {
            vt.pb(i.ss);
        }
        REP(i,sz(vt)-1)
        {
            if(lca.lca(vt[i],vt[i+1])!=vt[i])
            {
                boo=1;
                break;
            }
        }
        if(boo) cout<<"NO\n";
        else
        {
            cout<<"YES\n";
        }
    }
}