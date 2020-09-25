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
#define INF 1e15
ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}

ll n,w;
ll dp[200][100001];
ll we[200],v[200];

int main()
{
    IOS
    cin>>n>>w;
    ll vi=0;
    REP(i,n)
    {
        cin>>we[i+1]>>v[i+1];
        vi+=v[i+1];
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=vi;j++)
        {
            if(j==0)
            {
                dp[i][j] = 0;
            }
            if(i==0)
            {
                dp[i][j] = INF;
            }
            else if(v[i]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], we[i] + dp[i-1][j-v[i]]);
            }
        }
    }
    ll ans=0;
    for(int i=vi;i>=0;i--)
    {
        if(dp[n][i]<=w)
        {
            ans = i;
            break;
        }
    }
    REP(i,n+1)
    {
        REP(j,vi+1)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    
}