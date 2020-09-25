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

ll n, ar[300000];
map<ll,vl> ma;

ll upd(ll a, ll b, ll c)
{
    ll ans = (c-a)*(c-a-1)/2;
    ans-= (b-a)*(b-a-1)/2;
    return ans;
}

int main()
{
    // IOS
    cin>>n;
    REP(i,n)    cin>>ar[i];
    ll snlf = -1, snls = 0;
    ll l = 0;
    ll sum=0;
    ll ans=0;
    ma[0].pb(0);
    REP(i,n)
    {
        sum+=ar[i];
        ma[sum].pb(i+1);
    
        if(sz(ma[sum])>1)
        {
            if(ma[sum][sz(ma[sum])-2]>snlf)
            {
                snls = snlf;
                snlf = ma[sum][sz(ma[sum])-2];
            }
            else if(ma[sum][sz(ma[sum])-2]>snls)
            {
                snls = ma[sum][sz(ma[sum])-2];
            }

            // ans += upd(snlf,l,i+1);
            // trace(ans)  trace(upd(snlf,l,i+1)) trace(snlf)  trace(l) trace(i+1)
            // l=i+1;
        }
        ans+=i-snlf;
        // trace(ans)  trace(snlf)
        // ans+=upd(snlf, l, n);
    }
    cout<<ans<<endl;
}