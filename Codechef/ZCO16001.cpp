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

ll n, a[20000], b[200000], aa[200000], bb[20000];
ll k;
int main()
{
    IOS
    cin>>n>>k;
    REP(i,n)    cin>>a[i], aa[i]=a[i];
    REP(i,n)    cin>>b[i], bb[i]=b[i];

    sort(a,a+n, greater<ll>());
    sort(aa,aa+n,greater<ll>());
    sort(b,b+n,greater<ll>());
    sort(bb,bb+n,greater<ll>());
    
    ll skew = a[0]+b[0];
    ll maxa=a[0], maxb = b[0];
    a[n] = aa[n] = b[n] = bb[n] = -1;
    REP(i,k)
    {
        maxa = max(a[0], b[0]);
        maxb = max(b[i+1], a[n-1-i]);
        skew = min(skew, maxa+ maxb);
    }   
    REP(i,k)
    {
        maxa = max(b[0], a[0]);
        maxb = max(a[i+1], b[n-1-i]);
        skew = min(skew, maxa+ maxb);
    }
    cout<<skew<<endl;
}