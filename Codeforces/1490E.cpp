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

ll t,n;
ll ar[300000];
ll br[300000];
map<ll,ll> ma;
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        ma.clear();
        REP(i,n)
        {
            cin>>ar[i];
            ma[ar[i]]++;
        }
        // sort(ar,ar+n);
        ll sum = 0;
        ll mx = 0;
        vpll vt;
        for(auto it:ma)
        {
            vt.pb(it);
            sum += it.ff*it.ss;
        }
        // reverse(all(vt));
        ll ans  = -1;
        for(int i=sz(vt)-1;i>=0;i--)
        {
            sum -= vt[i].ff*vt[i].ss;
            // trace(sum)
            // trace(vt[i].ff)
            if(vt[i].ff > sum)
            {
                ans = vt[i].ff;
                break;
            }
        }
        vl vs;
        REP(i,n)
        {
            if(ar[i] >= ans)    vs.pb(i+1);
        }
        cout<<sz(vs)<<endl;
        for(auto it:vs) cout<<it<<" ";
        cout<<endl;
    }
}