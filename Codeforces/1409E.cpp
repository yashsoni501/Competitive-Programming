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
#define prv(a) for(auto xsdf : a) cout << xsdf << ' ';cout << '\n';
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

ll t,n,k,xi,yi;
vl x;
ll mar[300000];
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        x.clear();
        REP(i,n)
        {
            cin>>xi;
            x.pb(xi);
        }
        REP(i,n)    cin>>yi;
        // prv(x)
        sort(all(x));
        // prv(x)
        ll ans=0;
        mar[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            mar[i] = max(mar[i+1],upper_bound(all(x), x[i]+k)-(x.begin()+i));
        }
        // cout<<"mar ";
        // REP(i,n)    cout<<mar[i]<<' ';
        // cout<<endl;
        REP(i,n)
        {
            ll ind = upper_bound(all(x),x[i]+k)-x.begin();
            // trace(ind)
            if(ind==n)
            {
                ans = max(ans, ind-i);
            }
            else
            ans = max(ans, ind-i+mar[ind]);
            // trace(ans)
        }
        cout<<ans<<endl;
    }
}   