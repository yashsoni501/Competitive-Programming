#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ff first
#define ss second
#define pub push_back
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

ll t,s,c,ra,pa,rb,pb;
pll ar[100];
set<pll> stc;
vector<pll> adj[10][50];
map<pll,ll> ma;
map<pll,ll> dep;
ll depa,depb;
void msbfs(pll xa,ll xb)
{
    dep.clear();
    set<pll> vis;
    queue<pll> qu;
    ma[xa]=1;
    ma[xb]=2;
    qu.push(xa);
    qu.push(xb);
    dep[xa]=dep[xb]=1;
    while(!qu.empty())
    {
        pll fnt = qu.front();
        vis.in(fnt);
        qu.pop();
        for(auto it:adj[fnt.ff][fnt.ss])
        {
            if(vis.count(it)==0)
            {
                dep[it]=dep[fnt]+1;
                ma[it]=ma[fnt];
                qu.push(it);
            }
        }
    }
    depa=depb=0;
    for(auto it:ma)
    {
        if(it.ss == 1)
        {
            depa=max(depa,dep[it.ff]);
        }
        else
        {
            depb=max(depb,dep[it.ff]);
        }
    }
}

void dfs(pll a, ll b)
{
    set<pll> vis;
    stack<pll> stk;
    map<pll,ll> dfsd;
    for(auto it:ma)
    {
        if(it.ss==b)
        {
            dfsd[it.ff]=0;
        }
    }
    stk.in(a);
    dfsd[a]=1;
    while(!stk.empty())
    {
        ll top = stk.top();
        vis.in(top);
        stk.pop();
        for(auto it:adj[top.ff][top.ss])
        {
            if(vis.count(it)==0 && ma[it]==b)
            {
                stk.push(it);
                dfsd[it]=dfsd[top]+1;
            }
            
        }
    }
}

int main()
{
    IOS
    cin>>t;
    REP(te,t)
    {
        stc.clear();
        ma.clear();
        cin>>s>>ra>>pa>>rb>>pb>>c;
        REP(i,c)    cin>>ar[i].ff>>ar[i].ss;
        REP(i,c)    stc.in(ar[i]);    
        REP(i,s+1)    REP(j,2*s+4)  adj[i][j].clear();
        FOR(i,1,s+1,1)
        {
            FOR(j,1,2*s,2)
            {
                if(j>1 && stc.count({i,j-1})==0)
                adj[i][j].pub({i,j-1}), adj[i][j-1].pub({i,j});
                if(j<2*s-1 && stc.count({i,j+1})==0) adj[i][j].pub({i,j+1}), adj[i][j+1].pub({i,j});
                if(i<s && stc.count({i+1,j+1})==0) adj[i][j].pub({i+1,j+1}), adj[i+1][j+1].pub({i,j});
            }
        }
        msbfs({ra,pa},{rb,pb});
        
        cout<<"Case #"<<te+1<<": "<<ans;
        
        cout<<endl;
    }
}