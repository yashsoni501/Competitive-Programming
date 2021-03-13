#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int ll
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

struct Edge
{
    ll u,v,wt;
    bool operator<(Edge const &other)
    {
        return wt<other.wt;
    }
};

Edge edge[300000];
ll parent[300000];
ll ranke[300000];

void make_set(int v) {
    parent[v] = v;
    ranke[v] = 0;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranke[a] < ranke[b])
            swap(a, b);
        parent[b] = a;
        if (ranke[a] == ranke[b])
            ranke[a]++;
    }
}

ll t, n,m,k;
vl weight;
signed main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        weight.clear();
        REP(i,m)
        {
            cin>>edge[i].u>>edge[i].v>>edge[i].wt;
            weight.push_back(edge[i].wt);
        }
        sort(edge,edge+m);
        sort(all(weight));
        REP(i,n)
        {
            make_set(i+1);
        }
        ll comp=n;
        ll mawt = -1;
        ll exwt=0;
        REP(i,m)
        {
            Edge ed = edge[i];
            if(find_set(ed.u) != find_set(ed.v))
            {
                union_sets(ed.u,ed.v);
                exwt += max(0, ed.wt-k);
                comp--;
                mawt = ed.wt;
            }
        }
        // trace(exwt)
        // trace(mawt)
        ll iwt=-1e16,awt=1e16;
        if(exwt == 0)
        {
            exwt = k-mawt;
            // trace(exwt)
            for(auto it:weight)
            {
                if(it>k && it<awt)
                {
                    awt = it;
                }
                if(it<=k && it>iwt)
                {
                    iwt = it;
                }
            }
            exwt = min(exwt, awt-k);
            exwt = min(exwt, k-iwt);
        }
        cout<<exwt<<endl;
    }
}