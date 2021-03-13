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

ll dist(pll a, pll b)
{
    return abs(a.ff-b.ff)+abs(a.ss-b.ss);
}

bool comp(pll a, pll b)
{
    if(a.ss != b.ss)    
        return a.ss < b.ss;
    else
    {
        return a.ff < b.ff;
    }
}

vpll vt;
ll x,y;
int main()
{
    IOS
    ll t;
    cin>>t;
    REP(te, t)
    {
        ll n;
        cin>>n;
        vt.clear();
        REP(i,n)
        {
            cin>>x>>y;
            vt.pb({x,y});
        }
        sort(all(vt));
        ll X1=0, Y1=0;
        ll X2=0, Y2=0;
        X1 = vt[(n-1)/2].ff;
        X2 = vt[n/2].ff;
        sort(all(vt), comp);
        Y1 = vt[(n-1)/2].ss;
        Y2 = vt[n/2].ss;
        sort(all(vt));
        X1-=n/2;
        X2-=n/2;
        // cout<<"pr "<<X<<" "<<y<<endl;
        ll ans1=0;
        ll ans2=0;
        ll ans3=0,ans4=0;
        ll X=X1,Y=Y1;
        REP(i,n)
        {
            ans1 += dist(vt[i], {X,Y});
            X++;
        }
        X = X1, Y = Y2;
        REP(i,n)
        {
            ans2 += dist(vt[i], {X,Y});
            X++;
        }
        X = X2, Y = Y1;
        REP(i,n)
        {
            ans3 += dist(vt[i], {X,Y});
            X++;
        }
        X = X2, Y = Y2;
        REP(i,n)
        {
            ans4 += dist(vt[i], {X,Y});
            X++;
        }
        // trace(ans1)
        // trace(ans2)
        // trace(ans3)
        // trace(ans4)
        cout << "Case #"<<te+1<<": "<<min(min(ans1, ans2), min(ans3,ans4))<<endl;
    }
}