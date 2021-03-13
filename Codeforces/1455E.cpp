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

ll dist(pll p1, pll p2)
{
    return abs(p1.ff-p2.ff)+abs(p1.ss-p2.ss);
}

ll comp1(pll p1, ll p[][2], ll ar[], ll s)
{
    ll cal1 = dist({p[ar[1]][0],p[ar[1]][1]}, {p1.ff,p1.ss-s})+dist({p[ar[2]][0],p[ar[2]][1]}, {p1.ff-s,p1.ss-s})+dist({p[ar[3]][0],p[ar[3]][1]}, {p1.ff-s,p1.ss});
     
    return cal1;
}
ll comp2(pll p1, ll p[][2], ll ar[], ll s)
{
    ll cal2 = dist({p[ar[1]][0],p[ar[1]][1]}, {p1.ff,p1.ss-s})+dist({p[ar[2]][0],p[ar[2]][1]}, {p1.ff+s,p1.ss-s})+dist({p[ar[3]][0],p[ar[3]][1]}, {p1.ff+s,p1.ss});
    
    return cal2;
}
ll comp3(pll p1, ll p[][2], ll ar[], ll s)
{
    ll cal3 = dist({p[ar[1]][0],p[ar[1]][1]}, {p1.ff,p1.ss+s})+dist({p[ar[2]][0],p[ar[2]][1]}, {p1.ff+s,p1.ss+s})+dist({p[ar[3]][0],p[ar[3]][1]}, {p1.ff+s,p1.ss});
    
    return cal3;
}
ll comp4(pll p1, ll p[][2], ll ar[], ll s)
{
    ll cal4 = dist({p[ar[1]][0],p[ar[1]][1]}, {p1.ff,p1.ss+s})+dist({p[ar[2]][0],p[ar[2]][1]}, {p1.ff-s,p1.ss+s})+dist({p[ar[3]][0],p[ar[3]][1]}, {p1.ff-s,p1.ss});
    
    return cal4;
}
ll ts1(ll p[][2], ll ar[], ll l, ll h, pll p1)
{
    ll mid = (l+h)/2;
    while(h-l>1)
    {
        if(comp1(p1, p, ar, mid) > comp1(p1, p, ar, mid+1))
        {
            l = mid;
        }
        else 
        {
            h = mid;
        }
        mid = (l+h)/2;
    }
    trace(l)    trace(h)

    return min(comp1(p1, p, ar, l), comp1(p1, p, ar, h));
}
ll ts2(ll p[][2], ll ar[], ll l, ll h, pll p1)
{
    ll mid = (l+h)/2;
    while(h-l>1)
    {
        if(comp2(p1, p, ar, mid) > comp2(p1, p, ar, mid+1))
        {
            l = mid;
        }
        else 
        {
            h = mid;
        }
        mid = (l+h)/2;
    }
    trace(l)    trace(h)

    return min(comp2(p1, p, ar, l), comp2(p1, p, ar, h));
}
ll ts3(ll p[][2], ll ar[], ll l, ll h, pll p1)
{
    ll mid = (l+h)/2;
    while(h-l>1)
    {
        if(comp3(p1, p, ar, mid) > comp3(p1, p, ar, mid+1))
        {
            l = mid;
        }
        else 
        {
            h = mid;
        }
        mid = (l+h)/2;
    }
    trace(l)    trace(h)
    return min(comp3(p1, p, ar, l), comp3(p1, p, ar, h));
}
ll ts4(ll p[][2], ll ar[], ll l, ll h, pll p1)
{
    ll mid = (l+h)/2;
    while(h-l>1)
    {
        if(comp4(p1, p, ar, mid) > comp4(p1, p, ar, mid+1))
        {
            l = mid;
        }
        else 
        {
            h = mid;
        }
        mid = (l+h)/2;
    }
    trace(l)    trace(h)
    return min(comp4(p1, p, ar, l), comp4(p1, p, ar, h));
}
ll func(ll p[][2], ll ar[])
{
    ll ret1 = abs(p[ar[0]][0] - p[ar[1]][0]);
    ll ret2 = abs(p[ar[0]][1] - p[ar[1]][1]);
    pll p1 = {p[ar[1]][0],p[ar[0]][1]};
    pll p2 = {p[ar[1]][1],p[ar[0]][0]};
    ll pp2[4][2];
    for(int i=0;i<4;i++)
    {
        pp2[i][0] = p[i][1];
        pp2[i][1] = p[i][0];
    }
    ll ans1 = min(min(ts1(p, ar, 0, 2e9,p1),ts2(p, ar, 0, 2e9,p1)),min(ts3(p, ar, 0, 2e9,p1),ts4(p, ar, 0, 2e9,p1)))+ret1;
    ll ans2 = min(min(ts1(pp2, ar, 0, 2e9,p2),ts2(pp2, ar, 0, 2e9,p2)),min(ts3(pp2, ar, 0, 2e9,p2),ts4(pp2, ar, 0, 2e9,p2)))+ret1;
    return min(ans1,ans2);
}

ll t;
ll p[4][2];

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        REP(i,4)
        {
            cin>>p[i][0]>>p[i][1];
        }
        ll ar[] = {0,1,2,3};
        ll ans = 1e15;
        REP(i,24)
        {
            ans = min(ans, func(p, ar));
            next_permutation(ar,ar+4);
            trace(ans)
        }
        cout<<ans<<endl;
    }
}