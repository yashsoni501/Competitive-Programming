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

vector<pll> pr[4001];

string s,t;
int dp[4001][4001];
char ans[4001];
int ind=0;
int main()
{
    IOS
    cin>>s>>t;
    REP(i,sz(s)+1)
    {
        dp[i][0]=0;
    }
    REP(i,sz(t)+1)
    {
        dp[0][i]=0;
    }
    REP(i,sz(s))
    {
        REP(j,sz(t))
        {
            if(s[i]==t[j])
            {
                dp[i+1][j+1] = dp[i][j]+1;
                pr[dp[i+1][j+1]].pb(mp(i,j));
            }
            else
            {
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }        
        }
    }
    ll cnt=dp[sz(s)][sz(t)];
    if(cnt==0)  return 0;
    ans[cnt]='\0';
    pll top = pr[cnt][sz(pr[cnt])-1];
    // cout<<top.ff<<" "<<top.ss<<endl;
    ans[cnt-1] = s[top.ff];
    for(int i=cnt-1;i>0;i--)
    {
        REP(j,sz(pr[i]))
        {
            if(pr[i][j].ff<top.ff && pr[i][j].ss<top.ss)
            {
                top = pr[i][j];
                // cout<<top.ff<<" "<<top.ss<<endl;
                ans[i-1] = s[top.ff];
                break;
            }
        }
    }
    // REP(i,sz(s)+1)
    // {
    //     REP(j,sz(t)+1)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"done\n";
    cout<<ans<<endl;
}