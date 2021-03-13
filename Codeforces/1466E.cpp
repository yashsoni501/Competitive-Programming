#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int ll
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
#define FOR(i,j,k,l) for(ll i=j;i<k;i+=l)
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

ll t,n,ar[1000000];
ll cof[65];
ll ans;
ll pow2[65];
ll pol1,pol2;
signed main()
{
    IOS
    cin>>t;
    pow2[0] = 1;
    REP(i,61)
    {
        pow2[i+1] = mul(pow2[i],2);
    }
    while(t--)
    {
        ans=0;
        cin>>n;
        REP(i,n)    cin>>ar[i];
        REP(i,61)
        {
            cof[i]=0;
        }
        REP(i,n)
        {
            REP(j,60)
            {
                if(ar[i] &(1ll<<j))   cof[j]++;
            }
        }
        // REP(i,4)
        // {
        //     cout<<cof[i]<<" ";
        // }
        // cout<<endl;
        REP(j,n)
        {
            pol1=0, pol2=0;
            REP(x,60)
            {
                if(ar[j] & (1ll<<x))
                {
                    pol1 = add(pol1, mul(cof[x], pow2[x]));
                }
            }
            REP(x,60)
            {
                if(ar[j] & (1ll<<x))
                {
                    pol2 = add(pol2, mul(n, pow2[x]));
                }
                else
                {
                    pol2 = add(pol2, mul(cof[x], pow2[x]));
                }
            }
            ll prod = mul(pol1, pol2);
            ans = add(ans, prod);
        }
        cout<<ans<<endl;
    }
}