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

ll dist(pll a, pll b)
{
    return abs(a.ff-b.ff)+abs(a.ss-b.ss);
}

int main()
{
    IOS
    ll t,n,k,x,y;
    pll ar[200];
    vl adj[200];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        REP(i,n)    adj[i].clear();
        REP(i,n)
        {
            cin>>ar[i].ff>>ar[i].ss;
        }
        REP(i,n)
        {
            FOR(j,i+1,n,1)
            {
                if(dist(ar[i],ar[j])<=k)
                {
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
            }
        }
        bool boo=0;
        REP(i,n)
        {
            if(sz(adj[i])==n-1)
            {
                boo=1;
            }
        }
        if(boo)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        
    }
}