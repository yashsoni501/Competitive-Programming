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

ll t,n,ar[300000];
map<ll,ll> ma;
vl vt;
ll ps[300000];
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        ma.clear();
        cin>>n;
        REP(i,n)    cin>>ar[i],ma[ar[i]]++;
        vt.clear();
        for(auto it:ma)
        {
            vt.pb(it.ss);
        }

        sort(all(vt));
        ar[0]=0;
        ps[0]=0;
        ll ind = 0;
        FOR(i,1,n+1,1)
        {
            if(ind == sz(vt))
            {
                ar[i] = ar[i-1];
                ps[i] = ind;
            }
            else
            {
                ar[i] = ar[i-1];
                ps[i] = ps[i-1];
                while(ind<sz(vt) && vt[ind]<i)
                {
                    ar[i] += vt[ind];
                    ind++;
                    ps[i] = ind;
                }
            }
        }
        ll ans = 1e9;
        // prv(vt)
        // REP(i,n+1)    cout<<ar[i]<<" ";
        // cout<<endl;
        // REP(i,n+1)    cout<<ps[i]<<" ";
        // cout<<endl;
        REP(i,n+1)
        {
            ll a2 = ar[i] + n-ar[i]-(sz(vt)-ps[i])*i;
            // if(n-(n-ps[i])*i >=0)
                ans = min(ans,a2);
        }
        cout<<ans<<endl;
    }
}