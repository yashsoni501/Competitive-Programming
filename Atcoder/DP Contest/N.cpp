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

ll n,ar[500];
ll dp[500][500];

ll solve(ll a,ll b)
{
    // OTP("here")
    // trace(a) trace(b)
    if(dp[a][b]!=0) return dp[a][b];
    if(a==b-1)
    {
        dp[a][b] = ar[a]+ar[b];
        return ar[a]+ar[b];
    }
    if(a==b)
    {
        dp[a][a] = 0;
        return 0;
    }
    ll sum = 0;
    for(int i=a;i<=b;i++)
    {
        sum+=ar[i];
    }   
    ll ma = 1e15;
    for(int i=a;i<b;i++)
    {
        ma = min(ma,solve(a,i)+solve(i+1,b));
        // trace(solve(a,i)+solve(i+1,b))
    }
    dp[a][b] = ma+sum;
    return dp[a][b];
}

int main()
{
    IOS
    cin>>n;
    REP(i,n)
        cin>>ar[i];
    REP(i,n)
    {
        REP(j,n)
        {
            dp[i][j] = 0;
        }
    }
    cout<<solve(0,n-1)<<endl;
    // REP(i,n)
    // {
    //     REP(j,n)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}