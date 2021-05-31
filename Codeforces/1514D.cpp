#include<bits/stdc++.h>
#include<random>
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

ll n,q;
ll l,r;
ll ar[300006];
map<ll, vl> ma;
int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    IOS
    cin>>n>>q;
    REP(i,n)    cin>>ar[i];
    REP(i,n)    ma[ar[i]].pb(i);
    while(q--)
    {
        cin>>l>>r;
        l--,r--;
        ll ans=1;
        REP(i,20)
        {
            ll ind = uniform_int_distribution<int>(l, r)(rng);
            ll cnt = upper_bound(all(ma[ar[ind]]), r)-lower_bound(all(ma[ar[ind]]), l);
            ll siz= r-l+1;
            if(2*cnt>siz+1)
            {
                ans = siz-(siz-cnt)*2;
                // ll a=siz-cnt;   //other
                // ll b=cnt;       //mode
                // if(b>=2*a)  ans = b-a;
                // else
                // {
                //     ans = (b+1)/2;
                // }
                
                // cout<<"here\n";
                break;
            }
        }
        cout<<ans<<endl;
    }
}