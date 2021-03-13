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
ll n,ar[102],x;
ll dp[102][102][102];
int main()
{
    IOS
    cin>>n>>x;
    REP(i,n)    cin>>ar[i];
    REP(i,101)
    {
        REP(j,101)
        {
            REP(k,101)
            {
                dp[i][j][k]=0;
            }
        }
    }
    REP(i,n+1)
    {
        dp[0][0][i] = 0;
    }
    REP(i,n)
    {
        REP(j,i)
        {
            REP(k,100)
            // if(dp[i][j][k]!=-1)
            {
                // cout<<"here\n";
                dp[i+1][j+1][(dp[i][j][k]+ar[i])%(j+1)] = max(dp[i][j][k]+ar[i],dp[i+1][j+1][(dp[i][j][k]+ar[i])%(j+1)]);
            }
        }
    }
    ll ans=1e18;
    REP(i,n)
    {
        REP(j,n)
        {
            REP(k,n)
            {
                cout<<dp[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    REP(i,n+1)
    {
        if(!i)  continue;
        if(dp[n][i][x%i]!=-1)
        ll ans = min(ans, (x-dp[n][i][x%i])/i);
    }
    cout<<ans<<endl;
}