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

ll n,m;
pll l[200000];
ll ans[200000];
int main()
{
    IOS
    cin>>n>>m;
    ll su=0;
    REP(i,m)
    {
        cin>>l[i].ff;
        l[i].ss = i;       
        su+=l[i].ff;
    }
    // sort(l,l+m);

    if(su<n)    
    {
        cout<<-1<<endl;
        return 0;
    }
    bool b=1;
    // ll shft = n-m;
    ll mi = n+1;
    REP(i,m)   
    {
        ll x = n-i-l[i].ff+1;
        
        if(x<1)
        {
            b = 0;
            break;
        }
        // ans[l[i].ss] = x;
        mi = min(mi,x);
    }
    if(!b)  
    {
        cout<<-1<<endl;
        return 0;
    }
    ll shft = mi-1;
    mi = n+1;

    ll pi=0;
    REP(i,m)   
    {
        ll x = n-pi-l[i].ff+1;
        ll nx = max(max(x-shft,mi-l[i].ff),1);
        shft-=x-nx;
        // trace(x)    trace(nx)   trace(shft) trace(pi)
        ans[i] = nx;
        mi = min(nx,mi);
        pi+=x-nx+1;
    }

    REP(i,m)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    
}