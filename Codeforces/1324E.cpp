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

ll n,h,l,r;

ll a[5000],lo[4000],hi[4000],dp[2500][2]; // 0 = no 1 = time--
int main()
{
    IOS
    cin>>n>>h>>l>>r;
    REP(i,n)    cin>>a[i];
    ll t=0;
    REP(i,n)
    {
        t = (t+a[i])%h;
        lo[i] = (t-r+h)%h;
        hi[i] = (t-l+h)%h;
    }
    t=0;
    REP(i,n)
    {
        t = (t+a[i])%h;
        ll rem = 
        if(t>=l && t<==r)
        {
            dp[i][0] = 1;
            dp[i][1] = 0;
        }
        else if((t-1+h)%h>=l && (t-1+h)%h<=r)
        {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        else
        {
            dp[i][0] = dp[i][1] = 0;
        }
        REP(j,i)
        {
            if(dp[j][i])
        }
        
    }

}