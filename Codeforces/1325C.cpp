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

ll n;
map<pll,ll> ma;
vector<vector<ll> > adj(200000);
ll ar[200000];
bool vs[200000];
ll ans[200000];
vector<vector<ll> > siz(200000);
set<pll> st;


int main()
{
    IOS
    cin>>n;
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        ma[{a,b}] = ma[{b,a}] = i;
    }    
    REP(i,n+1)
    {
        if(!i)  continue;   
        vs[i] = 1;
        REP(j,sz(adj[i]))
        {
            if(st.find({min(i,adj[i][j]),max(i,adj[i][j])})==st.end())
            {
                st.insert({min(i,adj[i][j]),max(i,adj[i][j])});
                siz[min(sz(adj[i]),sz(adj[adj[i][j]]))].pb(ma[{min(i,adj[i][j]),max(i,adj[i][j])}]);
            }
        }
    }   
    int cnt=0;
    REP(i,n-1)
    {
        REP(j,sz(siz[i]))
        {
            ans[siz[i][j]] = cnt++;
        }
    }
    REP(i,n-1)    cout<<ans[i]<<" ";
    cout<<endl;

}