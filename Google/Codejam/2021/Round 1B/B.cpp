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

ll t,n,a,b;
ll u[100];

ll dp[100005];

ll uu(ll i)
{
    if(i>0 && i<=n) return u[i];
    return 0;
}

bool pos(ll mid, ll n)
{
    dp[mid]=1;
    REP(i,mid)  dp[i]=0;
    for(int i=mid;i>0;i--)
    {
        dp[i]-=uu(i);
        if(dp[i]<0) return 0;
        if(i-a>0)
        dp[i-a]+=dp[i];
        if(i-b>0)
        dp[i-b]+=dp[i];
    }
    return 1;
}


int main()
{
    IOS
    cin>>t;
    REP(te,t)
    {
        cin>>n>>a>>b;
        REP(i,n)    cin>>u[i+1];
        // while(u[n]==0)  n--;
        // if(a!=1 || b!=2)    return 0;
        ll ans=-1;
        FOR(i,n,10000,1)
        {
            if(pos(i,n))
            {
                ans = i;
                break;
            }
        }
        if(ans == -1)
        {
            cout<<"Case #"<<te+1<<": "<<"IMPOSSIBLE"<<endl;
        }
        else
            cout<<"Case #"<<te+1<<": "<<ans<<endl;
    }
}