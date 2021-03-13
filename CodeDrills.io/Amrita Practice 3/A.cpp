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
pll ar[20000];
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool bo=0;
        REP(i,n)
        {
            cin>>ar[i].ff>>ar[i].ss;
        }
        ll ans = 1e16;
        REP(i,n)
        {
            FOR(j,i+1,n,1)
            {
                if(ar[i].ff <= ar[j].ff && ar[i].ss <= ar[j].ss || ar[i].ff >= ar[j].ff && ar[i].ss >= ar[j].ss )
                {
                    bo=1;
                    ans = min(ans, abs(ar[i].ff * ar[i].ss - ar[j].ff*ar[j].ss ));
                }
            }
        }
        if(bo)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        
    }
}