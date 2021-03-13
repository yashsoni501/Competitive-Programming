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

ll n;
map<ll,ll> vt[2000];
ll cost[2000][2000];
ll tmp;
ll maxx[2000];
int main()
{
    IOS
    cin>>n;
    REP(i,n)
    {
        REP(j,n)
        {
            if(i==j)    continue;
            cin>>tmp;
            vt[i][j] = tmp;
        }
    }
    REP(i,n)
    {
        REP(j,n)
        {
            if(i==j)
            {
                cost[i][j] = 1e9;
            }
            else
            {
                cost[i][j] = vt[i][j]+vt[j][i];
            }
        }
    }
    ll ma=1e9;
    REP(i,n)
    {
        ma=1e9;
        REP(j,n)
        {
            ma = min(ma,cost[i][j]);
        }
        maxx[i] = ma;
    }

    REP(i,n)
    {
        ll ans=-1;
        REP(j,n)
        {
            if(cost[i][j]==maxx[i] && cost[j][i] == maxx[j])
            {
                ans = j+1;
                break;
            }
            
        }
        cout<<ans<<endl;
    }

}