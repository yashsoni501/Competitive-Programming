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
ll tmp;


ll t,n;
vl ar;

double dp[5010][5010];
ll pre[5010];
double compute(ll st, ll en)
{
    if(dp[st][en] != -1)
    {
        return dp[st][en];
    }
    ll len = en-st+1;
    if(len == 1)
    {
        return 0;
    }

    double ans = pre[en+1]-pre[st];
    // trace(ans)
    FOR(i, st, en, 1)
    {
        ans += (compute(st,i)+compute(i+1,en))/(len-1);
    }
    dp[st][en] = ans;
    
    return ans;
}


int main()
{
    IOS
    cin>>t;
    cout<<fixed<<setprecision(9);
    REP(te,t)
    {
        ar.clear();
        cin>>n;
        REP(i,n+1)
        {
            REP(j,n+1)
            {
                dp[i][j] = -1;
            }
        }
        REP(i,n)
        {
            cin>>tmp;
            ar.pb(tmp);
        }
        pre[0] = 0;
        REP(i,n)
        {
            pre[i+1] = pre[i]+ar[i];
        }

        // double ans = compute(ar, n);
        double ans = compute(0, n-1);
        // REP(i,n)
        // {
        //     REP(j,n)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //         cout<<endl;
        // }
        cout<<"Case #"<<te+1<<": "<< ans <<endl;
    }
}