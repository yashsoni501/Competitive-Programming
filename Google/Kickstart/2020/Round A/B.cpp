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

ll t,n,p,k;
ll ar[60][60],dp[60][2000];
int main()
{
    IOS
    cin>>t;
    REP(te,t)
    {
        cin>>n>>k>>p;
        ll tmp;
        REP(i,n)
        {
            ll sum=0;
            ar[i][0] = 0;
            REP(j,k)
            {
                cin>>tmp;
                sum+=tmp;
                ar[i][j+1] = sum;
            }
        }

        REP(i,p+1)
        {
            if(i<=k)
            {
                dp[0][i] = ar[0][i];
            }
            else
            {
                dp[0][i] = dp[0][i-1];
            }
        }
        REP(i,n)
        {
            if(!i)  continue;
            ll ma = 0;
            REP(j,p+1)
            {
                dp[i][j]=0;
                REP(l,j+1)
                {
                    if(l<=k)
                    {
                        dp[i][j] = max(dp[i-1][j-l]+ar[i][l],dp[i][j]);
                    }
                    else
                    {
                        dp[i][j] = max(dp[i-1][j-l]+ar[i][k],dp[i][j]); 
                    }
                }
            }
        }
        
        // REP(i,n)
        // {
        //     REP(j,p+1)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        cout<<"Case #"<<te+1<<": "<<dp[n-1][p]<<endl;
    }
}