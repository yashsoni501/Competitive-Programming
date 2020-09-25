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

ll t,n;
ll dp[20000][4];
ll ar[20000];
int main()
{
    IOS
    cin>>t;
    REP(te,t)
    {
        cin>>n;
        REP(i,n)    cin>>ar[i];
        REP(i,n)
        {
            REP(j,4)    dp[i][j] = 1e6;
        }
        REP(i,4)    dp[0][i] = 0;
        REP(i,n)
        {
            if(!i)  continue;
            REP(j,4)
            {
                REP(k,4)
                {
                    if(ar[i] == ar[i-1])
                    {
                        if(k==j)
                        {
                            dp[i][j] = dp[i-1][k];
                        }
                        else
                        {
                            dp[i][j] = min(dp[i][j], dp[i-1][k]+1);
                        }
                    }
                    else if(ar[i-1] > ar[i])
                    {
                        if(k<j)
                        {
                            dp[i][j] = min(dp[i-1][k], dp[i][j]);
                        }
                        else
                        {
                            dp[i][j] = min(dp[i-1][k]+1,dp[i][j]);
                        }
                    }
                    else
                    {
                        if(k>j)
                        {
                            dp[i][j] = min(dp[i-1][k], dp[i][j]);
                        }
                        else
                        {
                            dp[i][j] = min(dp[i-1][k]+1,dp[i][j]);
                        }
                    }
                }
            }
        }
        ll ans = 1e6;
        REP(i,4)    ans = min(ans, dp[n-1][i]);
        cout<<"Case #"<<te+1<<": "<<ans<<endl;
    }
}