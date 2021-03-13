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

ll n,a,b;
vl adj[5000];
ll siz[5000];
bool vis[5000];
ll par[5000];
void dfs(ll i, ll pare)
{
    par[i] = pare;
    if(sz(adj[i]) == 1)
    {
        siz[i] = 1;
        return;
    }
    siz[i] = 1;
    for(auto it:adj[i])
    {
        if(it != pare)
        {
            dfs(it, i);
            siz[i] += siz[it];
        }
    }
}

bool achhahaikya(ll i)
{
    ll sizeofpar = n-siz[i];
    if(sizeofpar == 0)
    {
        sizeofpar = siz[adj[i][0]];
    }
    
    for(auto it:adj[i])
    {
        if(it != par[i] && siz[it] != sizeofpar)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    IOS
    cin>>n;
    REP(i,n-1)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, -1);
    ll achanode = -1;
    REP(i,n)
    {
        if(achhahaikya(i+1))
        {
            achanode = i+1;
            break;
        }
    }
    REP(i,n)
    {
        cout<<siz[i+1]<<" ";
    }
    cout<<endl;
    if(achanode != -1)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<achanode<<endl;
    }
    cout<<par[4]<<endl;
    for(auto it:adj[4])
    {
        cout<<siz[it]<<endl;
    }
}