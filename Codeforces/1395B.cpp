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

ll t=1;
ll n,m,x,y;
int main()
{
    IOS
    cin>>n>>m>>x>>y;
    vector<pll> vt;
    vt.pb({x,y});
    vt.pb({x,1});
    FOR(j,1,m+1,1)
    {
        if(j%2==0)
        {
            FOR(i,1,n+1,1)
            {
                if(!((vt[0].ff == i && vt[0].ss == j) || (vt[1].ff == i && vt[1].ss == j)))
                {
                    vt.pb({i,j});
                }
            }
        }
        else
        {
            for(ll i=n;i>0;i--)
            {
                if(!((vt[0].ff == i && vt[0].ss == j) || (vt[1].ff == i && vt[1].ss == j)))
                {
                    vt.pb({i,j});
                }
            }
        }
        
       
    }
    for(auto it:vt)
    {
        cout<<it.ff<<" "<<it.ss<<endl;
    }
}