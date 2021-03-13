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

ll n,k,q;
ll ar[5005];
ll dp[5005][5005];
int main()
{
    IOS
    cin>>n>>k>>q;
    REP(i,n)
    {
        cin>>ar[i+1];
        dp[i+1][k] = 1;
    }
    for(int i=k-1;i>=0;i--)
    {
        FOR(j,1,n+1,1)
        {
            dp[j][i] = add(dp[j-1][i+1],dp[j+1][i+1]);
        }
    }

    FOR(i,1,n+1,1)
    {
        ll sme = 0;
        FOR(j,0,k+1,1)
        {
            sme = add(sme,mul(dp[i][j],dp[i][k-j]));
            // trace(sme)
        }
        dp[i][k+1] = sme;
    }
    // REP(i,k+2)
    // {
    //     REP(j,n+2)
    //     {
    //         cout<<dp[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }

    ll sum = 0;
    FOR(i,1,n+1,1)
        sum = add(sum, mul(dp[i][k+1], ar[i]));
    ll a,b;
    while(q--)
    {
        cin>>a>>b;
        sum = add(sum, mul(dp[a][k+1], sub(b,ar[a])));
        ar[a] = b;
        cout<<sum<<endl;
    }
}