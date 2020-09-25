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

ll n2,m,a2[3000],b2[3000];
// set<ll> a,b;
int main()
{
    IOS
    cin>>n2>>m;
    REP(i,n2)
    {
        cin>>a2[i];
    }
    REP(i,n2)
    {
        cin>>b2[i];
    }
    sort(a2,a2+n2);
    sort(b2,b2+n2);
    ll mi = 1e10;
    REP(i,n2)
    {
        ll x2=(m+b2[i]-a2[0])%m;
        bool bb=1;
        REP(j,n2)
        {
            if((m+b2[(i+j)%n2]-a2[j])%m!=x2)
            {
                bb=0;
                break;
            }
        }
        if(bb)
        {
            mi = min(mi,x2);
            return 0;
        }
    }
    cout<<mi<<endl;

}