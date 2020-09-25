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

ll ar[100];

ll fact(ll n,ll x,ll y)
{
    ll tm = y-x;
    ll ans=tm;
    FOR(i,1,tm+1,1)
    {
        if(tm%i==0 && tm/i<=n-1)
        {
            ans = i;
            return ans;
        }
    }
    return ans;
}

int main()
{
    IOS
    ll t,x,y,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>y;
        // ll d=(y-x+n-2)/(n-1);
        ll d = fact(n,x,y);
        // trace(d)
        REP(i,n)
        {
            ar[i]=x+i*d;
        }
        ll xt,yt;
        REP(i,n)
        {
            if(ar[i]==y)
            {
                yt=n-i-1;
            }
        }
        xt = x/d;
        if(x%d==0)  xt--;
        REP(i,n)
        {
            cout<<ar[i]-min(xt,yt)*d<<" ";
        }
        cout<<endl;
    }
}