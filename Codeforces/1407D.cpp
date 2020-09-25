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
#define MAXN 300001
#define INF 1e10
#define int long long
ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}

// ll t=1;

pair<int, int> t[4*MAXN];
pair<int, int> t2[4*MAXN];

ll n,h[400000];
ll dp[400000];
pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}


pair<int, int> combine2(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return b;
    if (b.first > a.first)
        return a;
    return make_pair(a.first, a.second + b.second);
}

void build2(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t2[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t2[v] = combine2(t2[v*2], t2[v*2+1]);
    }
}

pair<int, int> get_min(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t2[v];
    int tm = (tl + tr) / 2;
    return combine2(get_min(v*2, tl, tm, l, min(r, tm)), 
                   get_min(v*2+1, tm+1, tr, max(l, tm+1), r));
}

ll bs_min(ll l, ll h2, ll ind, ll fnd)
{
    ll tmp = get_min(1,0,n-1, 0, ind-1).ff;
    ll cmp=h[ind];
    if(tmp>h[ind])
    {
        cmp = tmp;
    }
    ll mid = (h2+l)/2;
    while(h2-l>1)
    {
        if(get_min(1,0,n-1, mid, ind-1).ff > cmp)
        {
            h2=mid;
        }
        else
        {
            l=mid;
        }
        mid = (h2+l)/2;
    }
    return l;
}

ll bs_max(ll l, ll h2, ll ind, ll fnd)
{
    ll tmp = get_max(1,0,n-1, 0, ind-1).ff;
    ll cmp=h[ind];
    if(tmp<h[ind])
    {
        cmp = tmp;
    }
    ll mid = (h2+l)/2;
    while(h2-l>1)
    {
        if(get_max(1,0,n-1, mid, ind-1).ff < cmp)
        {
            h2=mid;
        }
        else
        {
            l=mid;
        }
        mid = (h2+l)/2;
    }
    if(h[h2]==h[ind])   return h2;
    else return l;
}

signed main()
{
    IOS
    cin>>n;
    REP(i,n)    cin>>h[i];
    build(h,1,0,n-1);
    build2(h,1,0,n-1);
    
    dp[0]=0;
    FOR(i,1,n,1)
    {
        dp[i]=dp[i-1]+1;
        if(h[i-1]==h[i])    continue;
        else if(h[i-1]>h[i])
        {
            trace(bs_min(-1, i, i-1, h[i]))
            dp[i] = min(dp[i], dp[bs_min(-1, i, i-1, h[i])]+1); //t2
        }
        else
        {
            trace(bs_max(-1, i, i-1, h[i]))
            dp[i] = min(dp[i], dp[bs_max(-1, i, i-1, h[i])]+1); //t
        }
        REP(i,n+1)  cout<<dp[i]<<" ";
        cout<<endl;
    }
    REP(i,n+1)  cout<<dp[i]<<" ";
    cout<<endl;
    cout<<dp[n-1]<<endl;
}