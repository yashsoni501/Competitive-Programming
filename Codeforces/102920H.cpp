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

ll n[3];
ll ar[100000][3];
int main()
{
    IOS
    bitset<60001> a("0");
    bitset<60001> b("0");
    bitset<60001> c("0");
    bitset<60001> a2("0");
    bitset<60001> c2("0");

    REP(i,3)
    {
        cin>>n[i];
        REP(j,n[i])
        {
            cin>>ar[j][i];
            ar[j][i] += 30000;
        }

    }
    REP(i,n[0])
    {
        a.set(ar[i][0]);
        a2.set(ar[i][0]);
    }
    REP(i,n[1])
    {
        b.set(ar[i][1]);
    }
    REP(i,n[2])
    {
        c.set(ar[i][2]);
        c2.set(ar[i][2]);
    }

    ll ans = (a&b&c).count();
    REP(rt,30001)
    {
        a <<= 1;
        c >>= 1;

        ans += (a&b&c).count();
    }
    // trace(ans)
    REP(rt,30001)
    {
        c2 <<= 1;
        a2 >>= 1;

        ans += (a2&b&c2).count();
    }
    cout<<ans<<endl;
}