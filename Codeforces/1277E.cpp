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

ll t,n,m,a,b;
ll cncp=0;
ll cna,cnb,cnab;
bool vis[300000];
vl adj[300000];

pair<int,int> dfs(int i)
{
    if(i==a)
    {
        // cout<<i<<" "<<"return "<<1<<" "<<0<<endl;
        return mp(1,0);
    }
    if(i==b)
    {
        // cout<<i<<" "<<"return "<<2<<" "<<0<<endl;
        return mp(2,0);
    }
    if(vis[i])
    {
        // cout<<i<<" "<<"return "<<0<<" "<<0<<endl;
        return mp(0,0);
    }   
    vis[i]=1;
    int rt=0;
    int wt=1;
    REP(j,sz(adj[i]))
    {
        pair<int,int> tmp = dfs(adj[i][j]);
        wt+=tmp.ss;
        if(tmp.ff==1)
        {
            if(rt==0)
                rt=1;
            else if(rt==2)
            {
                rt=3;
            }
        }
        if(tmp.ff==2)
        {
            if(rt==0)
                rt=2;
            else if(rt==1)
            {
                rt=3;
            }
        }
        if(tmp.ff==3)
        {
            rt=3;
        }
    }
    // trace(i)
    // trace(rt)
    // cout<<i<<" "<<"return "<<rt<<" "<<wt<<endl;
    return mp(rt,wt);
}

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>a>>b;
        REP(i,n)
        {
            adj[i+1].clear();
            vis[i+1]=0;
        }
        REP(i,m)
        {
            ll x,y;
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        cncp=0;
        
        cna=cnb=cnab=0;
        REP(i,n)
        {
            if(i+1==a || i+1==b)
                continue;
            if(!vis[i+1])
            {
                cncp++;
                pair<int,int> tmp = dfs(i+1);
                if(tmp.ff==1)
                {
                    cna+=tmp.ss;
                }
                if(tmp.ff==2)
                {
                    cnb+=tmp.ss;
                }
                if(tmp.ff==3)
                {
                    cnab+=tmp.ss;
                }
            }
        }
        // trace(cncp)
        // trace(cna)  trace(cnb)  trace(cnab)
        cout<<cna*cnb<<endl;
    }   
}