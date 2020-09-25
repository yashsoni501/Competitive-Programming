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

ll t=1;
ll n,a,b,da,db;
vector<ll> adj[100010];

ll dist(ll x, ll y)
{
    bool vis[n+1]={};
    queue<pll> qu;
    qu.push({x,0});
    // vis[x]=1;
    while(!qu.empty())
    {
        pll ft = qu.front();
        vis[ft.ff]=1;
        if(ft.ff==y)    return ft.ss;
        qu.pop();
        for(auto it:adj[ft.ff])
        {
            if(!vis[it])
            {
                qu.push({it,ft.ss+1});
            }
        }
    }
    return -1;
}

ll longest_chain()
{
    queue<pll> qu;
    qu.push({1,0});
    bool vis[n+1]={};
    pll ft;
    while(!qu.empty())
    {
        ft = qu.front();
        vis[ft.ff]=1;
        // if(ft.ff==y)    return ft.ss;
        qu.pop();
        for(auto it:adj[ft.ff])
        {
            if(!vis[it])
            {
                qu.push({it,ft.ss+1});
            }
        }
    }
    REP(i,n+1)  vis[i]=0;
    qu.push({ft.ff,0});
    while(!qu.empty())
    {
        ft = qu.front();
        vis[ft.ff]=1;
        // if(ft.ff==y)    return ft.ss;
        qu.pop();
        for(auto it:adj[ft.ff])
        {
            if(!vis[it])
            {
                qu.push({it,ft.ss+1});
            }
        }
    }
    return ft.ss;
}

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>da>>db;
        ll x,y;
        REP(i,n+1)  adj[i].clear();
        REP(i,n-1)
        {
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        if(db<=2*da)    
        {
            cout<<"Alice\n";
            continue;
        }
        ll dst = dist(b,a);
        if(dst<=da)
        {
            cout<<"Alice\n";
            continue;
        }
        if(longest_chain()<2*da+1) 
        {
            cout<<"Alice\n";
        }
        else
        {
            cout<<"Bob\n";
        }
    }
}