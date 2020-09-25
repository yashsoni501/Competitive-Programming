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
ll n,I;
ll ar[1000000];
vpll vp;
ll modPower(ll a, ll b) // return a^b % MOD where MOD is defined globally
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b%2 == 0)
    {
        ll tmp = modPower(a,b/2);
        return (tmp*tmp)%MOD;
    }
    else
    {
        ll tmp = modPower(a,(b-1)/2);
        return (((tmp*tmp)%MOD)*a)%MOD;
    }
}
ll findr(ll I)
{
    return modPower(2,I);
}
int main()
{
    IOS
    set<ll> st;
    cin>>n>>I;
    I*=8;
    I/=n;

    REP(i,n)    cin>>ar[i];
    sort(ar,ar+n);

    vp.pb(mp(ar[0],0));
    for(int i=1;i<n;i++)
    {
        if(ar[i]==ar[i-1])  continue;
        vp.pb(mp(ar[i],i));
    }
    vp.pb(mp(2e9,n));

    ll r = findr(I);

    ll mini=1e7;
    REP(i,sz(vp)-1)
    {
        mini = min(mini,vp[i].ss+n-vp[i+min(r,sz(vp)-i-1)].ss);
        //cout<<i<<" "<<mini<<endl;
    }
    cout<<mini<<endl;
}
