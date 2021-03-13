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

ll t;
ll n,m;
ll ar[2000][2000];
ll br[2000][2000];
int main()
{
    IOS
    cin>>t;
    REP(te,t)
    {
        cin>>n;
        REP(te,t)
        {
            REP(i,2*n)
            {
                REP(j,2*n)
                {
                    ar[i][j] = 0;
                }
            }
        }
        REP(i,n)
        {
            REP(j,n)
            {
                cin>>ar[i][n-j-1];
            }
        }
        // REP(i,n)    
        // {
        //     REP(j,n)
        //     {
        //         cout<<ar[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        ll ma = -1;
        REP(i,2*n)
        {
            ll sum=0;
            REP(j,i+1)
            {
                sum+= ar[j][i-j];
            }
            ma = max(ma,sum);
        }
        cout<<"Case #"<<te+1<<": "<<ma<<endl;
    }
}