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

ll nod(ll x)
{
    ll cnt=0;
    while(x)
    {
        cnt++;
        x/=10;
    }
    return cnt;
}

ll dp1[10][2];
ll dp2[10][2];

ll ans(ll x)
{
    ll nd = nod(x);
    dp1[0][0] = 0;
    dp1[0][1] = 0;
    dp2[0][0] = 0;
    dp2[0][1] = 0;
    for(int i=1;i<nd+1;i++)
    {
        dp1[i][0] = dp1[i-1]
    }
}

// bool chk(ll x, ll y)
// {
//     if(x==0) return 1;
//     ll nd = nod(x); 
//     // trace(nd)
//     ll tm = 1;
//     ll t2 = 1;
//     REP(p,nd-1)
//     {
//         tm*=10;
//         t2*=5;
//     }
//     if((x/tm)%2 == (y%2))
//     {
//         return chk(x%tm, y+1);
//     }
//     return 0;
// }

int main()
{
    IOS
    ll t;

    cin>>t;
    REP(te, t)
    {
        ll l,r;
        cin>>l>>r;
        
        cout << "Case #"<<te+1<<": "<<ans(r,1)-ans(l-1,1)<<endl;   
        // ll tmp=0;
        // FOR(i,l,r+1,1)
        // {
        //     if(chk(i,1))
        //     {
        //         tmp++;
        //     }
        // }
        // cout<<tmp;
    }
}