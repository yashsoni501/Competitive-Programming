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
#define INF 1e15
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

ll n,ar[4000];
ll dp[3001][3001];
ll ind1,ind2;
ll lst=0;

ll value(ll x, ll y)
{
    if(dp[x][y]!=INF)
    {
        return dp[x][y];
    }
    // cnt++;
    if(x==y)
    {
        dp[x][y]=ar[x];
        return dp[x][y];
    }
    if(y-x==1)
    {
        dp[x][y] = max(ar[x],ar[y])-min(ar[x],ar[y]);
        return dp[x][y];
    }
    
    dp[x][y] = max(ar[x]-value(x+1,y),ar[y]-value(x,y-1));
    return dp[x][y];
}

int main()
{
    IOS
    cin>>n;
    REP(i,n)
    {
        cin>>ar[i];
    }
    REP(i,n)
    {
        REP(j,n)
        {
            dp[i][j]=INF;
        }
    }
    cout<<value(0,n-1)<<endl;
    // trace(cnt)
}