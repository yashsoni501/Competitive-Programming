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

ll n,m,del;
map<ll,bool> adj[2000000];
ll deg[2000000];

void join(ll x,ll y)
{
    adj[x][y]=1;
    adj[y][x]=1;
}

bool degchk(ll i)
{
    return (deg[i]+1)/2 < sz(adj[i]);
}

void brk(ll i,ll j)
{
    adj[i].erase(j);
    adj[j].erase(i);
    del--;
}

void dfs(ll ind)
{
    for(map<ll,bool>::iterator it = adj[ind].begin(); it!=adj[ind].end(); it++)
    {
        if(!degchk(ind))    return;
        if(degchk(it->ff))
        {
            brk(ind,(*it).ff);
        }
    }
}

int main()
{
    IOS
    cin>>n>>m;
    REP(i,m)
    {
        ll x,y;
        cin>>x>>y;
        join(x,y);
    }
    FOR(i,1,n+1,1)
    {
        deg[i]=sz(adj[i]);
    }
    
    del=m-(n+m+1)/2;
    for(int i=1;i<n+1 && del>0;i++)
    {
        dfs(i);
    }
    map<pll,bool> st;
    REP(i,n)
    {
        for(map<ll,bool>::iterator it=adj[i+1].begin();it!=adj[i+1].end();it++)
        {
            st[mp(min(i+1,it->ff),max(i+1,it->ff))]=1;
        }
    }
    cout<<sz(st)<<endl;
    for(map<pll,bool>::iterator it=st.begin();it!=st.end();it++)
    {
        cout<<it->ff.ff<<" "<<it->ff.ss<<endl;
    }
}
