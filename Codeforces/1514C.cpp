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
#define FOR(i,j,k,l) for(ll i=j;i<k;i+=l)
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

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1) {
        // q is quotient
        int q = a / m;
        int t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}

void chk(vl ans, ll n)
{
    ll rt = 1;
    REP(i,sz(ans))    rt = (rt*ans[i])%n;
    trace(rt)
}

int main()
{
    IOS
    ll n;
    cin>>n;
    vl ans;
    ans.pb(1);
    bool vis[n]={};
    vis[1]=1;
    vl inv;
    FOR(i,2,n,1)
    {
        if(__gcd(i,n)!=1 || vis[i])  continue;
        // ans.pb(i);
        vis[i]=1;
        ll mi = modInverse(i,n);
        // trace(mi)
        if(!vis[mi])
        {
            vis[mi] = 1;
            ans.pb(i);
            ans.pb(mi);
        }
        else
        {
            vis[i]=0;
            if(mi==i)
            {
                if(!vis[n-i])
                {
                    vis[i]=1;
                    vis[n-i]=1;
                    inv.pb(i);
                    inv.pb(n-i);
                }
            }
        }
    }
    // FOR(i,2,n,1)
    // {
    //     if(vis[i])  continue;
    //     ll mi = modInverse(n-i,n);
    //     if()
    // }
    // prv(inv)
    if(sz(inv)%4==0)
    {
        REP(i,sz(inv))  ans.pb(inv[i]);
    }
    else if(sz(inv)%4==1)
    {
        REP(i,sz(inv)-1)  ans.pb(inv[i]);
    }
    else if(sz(inv)%4==2)
    {
        REP(i,sz(inv))  ans.pb(inv[i]);
        ans.pb(n-1);
    }
    else
    {
        REP(i,sz(inv)-1)  ans.pb(inv[i]);
        ans.pb(n-1);
    }
    
    sort(all(ans));
    cout<<sz(ans)<<endl;
    for(auto it:ans)    cout<<it<<" ";
    cout<<endl;
    // chk(ans,n);
}