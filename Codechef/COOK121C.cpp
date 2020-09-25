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

ll t,n,m,k;
vl adj[1000000];
ll mcnt[1000000];
ll f[1000000];
map<ll, ll> ma;
ll mpcnt[1000000];
ll lft[1000000];
int main()
{
    IOS
    cin>>t;
    ll tmp;
    while(t--)
    {
        ma.clear();
        
        cin>>n>>m>>k;
        REP(i,n)    adj[i].clear();
        REP(i,m+1)
        {
            mcnt[i]=0;
            mpcnt[i]=0;
            lft[i]=0;
        }
        REP(i,n)   
        {
            cin>>f[i];
            mcnt[f[i]]++;
        }
        REP(i,n)    
        {
            REP(j,k)
            {
                cin>>tmp;
                // if(f[i]!=f[tmp-1])
                adj[i].pb(tmp-1);
            }
        }
        ll p1 = 0, p2 = 0;
        ll cfcnt = sz(adj[0]) + mcnt[f[0]]-1;
        REP(i,sz(adj[0]))
        {
            mpcnt[adj[0][i]]++;
        }
        ma[f[0]]++;
        ll ans=0;
        lft[f[0]]++;
        while(p1<n-1 || p2<n-1)
        {
            trace(p1)   trace(p2)
            trace(cfcnt)
            if(cfcnt<n && p2<n-1)
            {
                // trace(lft[f[p2]])
                p2++;
                ma[f[p2]]++;
                cfcnt+=sz(adj[p2]);

                for(auto it:adj[p2])
                {
                    mpcnt[f[it]]++;
                }
                if(ma[f[p2]]==1)
                {
                    cfcnt += mcnt[f[p2]]-1-mpcnt[f[p2]];
                    lft[f[p2]] = 1;
                }
                else
                {
                    cfcnt += lft[f[p2]];
                    lft[f[p2]] = 0;
                }
                // trace(lft[f[p2]])
            }
            else
            {
                if(cfcnt==n)
                {
                    ans+=n-p2;
                }
                ma[f[p1]]--;
                // mpcnt[f[p1]]--;
                if(ma[f[p1]]==0)
                {
                    cfcnt -= mcnt[f[p1]]-1-ma[f[p2]];
                    lft[f[p1]]=0;
                }
                // cout<<"midway: ";
                trace(cfcnt)
                for(auto it:adj[p1])
                {
                    trace(it)
                    trace(mpcnt[f[it]])
                    mpcnt[f[it]]--;
                    if(!mpcnt[f[it]] || (ma[f[it]]==1 && p1<it && it<=p2))
                    {
                        cfcnt--;
                    }
                }
                p1++;
            }
            trace(ans)
        }
        cout<<ans<<endl;

    }
}