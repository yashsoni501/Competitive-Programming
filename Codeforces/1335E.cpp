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

ll n,a[1000000];
vector<ll> ar[210];
int main()
{
    IOS
    
    ll t=1;
    cin>>t;
    while(t--)
    {
        REP(i,205)  ar[i].clear();

        cin>>n;
        REP(i,n)    cin>>a[i];

        REP(i,n)    ar[a[i]].pb(i);

        ll ma = 1;
        REP(i,201)  ma = max(ma, sz(ar[i]));
        REP(i,201)
        {
            REP(j,sz(ar[i])/2)
            {
                ll l1 = ar[i][j];
                ll l2 = ar[i][sz(ar[i])-j-1];
                REP(k,201)
                {
                    ll tmp1 = lower_bound(all(ar[k]), l2) - upper_bound(all(ar[k]), l1);
                    ma = max(ma, 2*(j+1) + tmp1);
                }
            }
        }    
        cout<<ma<<endl;
    }   
}