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

ll n,k;
vl m,c;
vector<vl> sol(300000);

void solve(ll mid)
{
    REP(i,mid)
    {
        sol[i].clear();
    }
    ll ind=0;
    REP(i,n)
    {
        sol[ind%mid].pb(m[i]);
        // if(c[m[i]]<sz(sol[ind%mid]))    return 0;
        ind++;
    }
}

bool chk(ll mid)
{
    if(mid==0)  return 0;
    // vector<vl> sol();
    REP(i,mid)
    {
        sol[i].clear();
    }
    ll ind=0;
    REP(i,n)
    {
        sol[ind%mid].pb(m[i]);
        if(c[m[i]]<sz(sol[ind%mid]))    return 0;
        ind++;
    }
    return 1;
}

ll bs(ll l, ll h)
{
    while(h-l>1)
    {
        ll mid = (l+h)/2;
        if(chk(mid))
        {
            h = mid;
        }
        else
        {
            l = mid;
        }
    }
    return h;
}

int main()
{
    IOS
    c.pb(0);
    cin>>n>>k;
    REP(i,n)
    {
        ll tmp;
        cin>>tmp;
        m.pb(tmp);
    }
    REP(i,k)
    {
        ll tmp;
        cin>>tmp;
        c.pb(tmp);
    }
    sort(all(m), greater<ll>());
    // trace(chk(0))
    // return 0;
    ll ans = bs(-1,n+1);
    solve(ans);
    cout<<ans<<endl;
    REP(i,ans)
    {
        cout<<sz(sol[i])<<" ";
        REP(j,sz(sol[i]))
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    } 
    
}