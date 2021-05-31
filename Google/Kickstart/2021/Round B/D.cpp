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

ll t;
ll n,q;
struct edge
{
    ll y,l,a;
};
edge par[100000];
vector<edge> adj[100000];

void dfs(ll x, ll pr, ll lr, ll ar)
{
    par[x].y = pr;
    par[x].l = lr;
    par[x].a = ar;
    for(auto it: adj[x])
    {
        if(it.y != pr)
        {
            dfs(it.y,x,it.l, it.a );
        }
    }
}

ll gcd(ll x, ll c)
{
    if(par[x].y==-1)
    {
        return 0;
    }
    else
    {
        ll id = gcd(par[x].y, c);
        ll ans = 0;
        if(c>=par[x].l)
        {
            ans = par[x].a;
        }
        if(id == 0)     return ans;
        else if(ans == 0)     return id;
        else
        {
            return __gcd(ans,id);
        }
    }
}

int main()
{
    IOS
    cin>>t;
    REP(te,t)
    {
        cin>>n;
        REP(i,n)    adj[i].clear();
        cin>>q;
        ll x,y,l,a;
        REP(i,n-1)
        {
            cin>>x>>y>>l>>a;
            edge ed = {y-1,l,a};
            adj[x-1].pb(ed);
            ed = {x-1,l,a};
            adj[y-1].pb(ed);
        }
        dfs(0, -1,-1,-1);
        vl ans;
        ll xs,c;
        while(q--)
        {
            cin>>xs>>c;
            ans.pb(gcd(xs,c));
        }
        cout<<"Case #"<<te+1<<": ";
        for(auto it:ans)    cout<<it<<" ";
        cout<<endl;
    }
}