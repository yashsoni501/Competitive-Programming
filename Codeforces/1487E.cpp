#include<bits/stdc++.h>
using namespace std;

#define INF 1e14
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

ll n[4];
ll m[3];
ll ar[4][160000];
map<ll, vl> ml[3];
ll x,y;
map<ll,ll> dp[4];
vl dp2[4];
int main()
{
    // IOS
    REP(i,4)    cin>>n[i];
    REP(i,4)
    {
        REP(j,n[i])
        {
            cin>>ar[i][j];
        }
    }
    // cout<<"n done\n";
    REP(i,3)
    {
        cin>>m[i];
        REP(j,m[i])
        {
            cin>>x>>y;
            ml[i][x-1].pb(y-1);
        }
    }

    REP(i,n[3])
    {
        dp[3][ar[3][i]]++;
        dp2[3].pb(ar[3][i]);
    }
    for(int ft=3;ft>=1;ft--)
    {
        REP(i,n[ft-1])
        {
            for(auto it:ml[ft-1][i])
            {
                dp[ft][dp2[ft][it]]--;
                if(dp[ft][dp2[ft][it]]==0)
                {
                    dp[ft].erase(dp2[ft][it]);
                }
            }
            ll cost = ar[ft-1][i];
            if(sz(dp[ft])==0)    cost = INF;
            else
            {
                cost += dp[ft].begin()->ff;
            }
            dp[ft-1][cost]++;
            dp2[ft-1].pb(cost);
            for(auto it:ml[ft-1][i])
            {
                dp[ft][dp2[ft][it]]++;
            }
        }
    }
    ll ans = INF;
    REP(i,n[0])
    {
        ans = min(ans, dp2[0][i]);
    }
    if(ans == INF)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
    // cout<<dp2[2][0]<<endl;
}