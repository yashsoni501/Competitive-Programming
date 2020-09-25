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

ll t,n;
vl adj[100005];
ll siz[100005];
ll masiz[100005];
bool vis[100005];
ll p[100005];
ll dfs(ll ind,ll par)
{
    vis[ind]=1;
    p[ind]=par;
    ll si=1;
    REP(i,sz(adj[ind]))
    {
        if(adj[ind][i]==par)    continue;
        si+=dfs(adj[ind][i],ind);
        // trace(si)
    }
    siz[ind]=si;
    return si;
} 

int main()
{
    IOS
    // ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        REP(i,n+1)
        {
            p[0]=-1;
            adj[i].clear();
            vis[i]=0;
        }
        REP(i,n-1)
        {
            ll x,y;
            cin>>x>>y;
            adj[x-1].pb(y-1);
            adj[y-1].pb(x-1);
        }
        if(n%2==1)
        {
            REP(i,n)
            {
                cout<<'0';
            }
            cout<<endl;
            continue;
        }
        int tmp = dfs(0,-1);
        REP(i,n)
        {
            masiz[i] = 0;
            ll si=0;
            REP(j,sz(adj[i]))
            {
                if(adj[i][j]==p[i])
                    continue;
                si+=siz[adj[i][j]];
                // trace(adj[i][j])
                // trace(siz[adj[i][j]])
                masiz[i] = max(masiz[i],siz[adj[i][j]]);
            }
            masiz[i] = max(masiz[i],n-1-si);
        }
        // REP(i,n)
        // {
        //     cout<<i<<" "<<masiz[i]<<" "<<p[i]<<endl;
        // }
        if(n==2)
        {
            cout<<"11"<<endl;
            continue;
        }
        REP(i,n)
        {
            if(masiz[i]<=n-masiz[i])
            {
                cout<<'1';
            }
            else
            {
                cout<<'0';
            }
        }
        cout<<endl;
    }   
}