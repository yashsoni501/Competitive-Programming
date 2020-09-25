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
double q[3000][3000];
double p[10000];
int main()
{
    IOS
    cin>>n;
    REP(i,n)
    {
        cin>>p[i+1];
    }
    double prod=1;

    q[0][0]=1;
    FOR(i,1,n+1,1)
    {
        prod*=0;
        q[0][i]=prod;
    }
    prod=1;
    REP(i,n)
    {
        prod*=p[i+1];
        q[i+1][0] = prod;
    }
    FOR(i,1,n+1,1)
    {
        FOR(j,1,i+1,1)
        {
            q[i][j] = p[i]*q[i-1][j] + (1-p[i])*q[i-1][j-1];
        }
    }
    // REP(i,n+1)
    // {
    //     REP(j,n+1)
    //     {
    //         cout<<q[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    double ans = 0;
    REP(i,(n-1)/2+1)
    {
        ans+=q[n][i];
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
}