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
ll t,n,p[300000],c[300000];
ll p2[300000];
ll app[300000];
bool boo[300000];
void apply(ll *p1,ll *p2)
{
    REP(i,n)
    {
        app[i+1] = p2[p1[i+1]];
    }
    REP(i,n)
    {
        p1[i+1] = app[i+1];
    }
}
void power(ll *p, ll *p2, ll k)
{
    if(k==1)    
    {
        REP(i,n)
            p2[i+1] = p[i+1];
        return;
    }
    power(p,p2,k/2);
    apply(p2,p2);
    if(k%2)
    {
        apply(p2,p);
    }
}

bool pred(ll *p)
{
    REP(i,n)    boo[i+1] = 0;
    for(int i=1;i<=n;i++)
    {
        ll x = p[i];
        if(!boo[x])
        {
            boo[x] = 1;
            while(c[x] == c[p[x]])
            {
                x = p[x];
                if(boo[x])  return 1;
                boo[x] = 1;
            }
        }
    }
    return 0;
}

ll binsearch(ll *p, ll s, ll e)
{
    ll mid = (s+e)/2;
    
    while(s<e)
    {
        // trace(mid)
        power(p,p2,mid);
        if(pred(p2))
        {
            e = mid;
        }
        else
        {
            s = mid+1;
        }
        mid = (s+e)/2;
    }
    // trace(mid)
    return mid;
}


int main()
{
    IOS 
    // cin>>t;/
    t=1;
    while(t--)
    {
        cin>>n;
        REP(i,n)    cin>>p[i+1];
        // REP(i,n)    cin>>c[i+1];

        REP(i,n)    p2[i+1] = p[i+1];
        REP(i,2)
        {
            apply(p2,p);
        }
        REP(i,n)    cout<<p2[i+1]<<" ";
        cout<<endl;
        power(p,p2,2);
        REP(i,n)    cout<<p2[i+1]<<" ";
        cout<<endl;
    }
    
}