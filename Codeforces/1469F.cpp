#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
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

#define MAXN 1000000
ll t[4*MAXN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = 0;
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}

ll n,k,lt[300000];
signed main()
{
    // IOS
    cin>>n>>k;
    REP(i,n)
    {
        cin>>lt[i];
    }
    if(k==2)
    {
        cout<<2<<endl;
        return 0;
    }
    sort(lt,lt+n);
    ll nown = 1;
    ll ind = 0;
    while(ind<n)
    {
        nown += lt[ind]-2;
        ind++;
        if(nown >=k)
        {
            break;
        }
    }
    if(ind==n && nown <k)
    {
        cout<<-1<<endl;
        return 0;
    }
    build(1,0,MAXN);
    update(1,0,MAXN,0,0,1);
    // cout<<get(1,0,MAXN,0)<<endl;
    // cout<<get(1,0,MAXN,1)<<endl;
    ll ind2=0;
    ll dep = MOD;
    nown = 1;
    ll sum=0;
    for(int i=n-1;i>=0;i--)
    {
        while(get(1,0,MAXN,ind2)==0)
        {
            ind2++;
        }
        if(ind2 >= dep-2)
        {
            break;
        }
        ll x = lt[i];
        ll x1 = (x-1)/2;
        ll x2 = x/2;
        update(1,0,MAXN,ind2,ind2,-1);
        update(1,0,MAXN,ind2+2,ind2+1+(x-1)/2,1);
        update(1,0,MAXN,ind2+2,ind2+1+x/2,1);
        // REP(i,7)
        // {
        //     trace(get(1,0,MAXN,i))
        // }
        // cout<<"over\n";
        nown += x-2;
        if(dep != MOD)
        {
            // cout<<"drowning\n";
            sum = sum-1+min((dep-ind2-1),x1) + min((dep-ind2-1),x2);
            // trace(sum)
            // trace(get(1,0,MAXN,dep))
            while(sum-get(1,0,MAXN,dep) >=k)
            {
                sum-=get(1,0,MAXN,dep);
                dep--;
            }
        }
        if(dep == MOD && nown >= k )
        {
            sum = 0;
            dep = 0;
            // trace(nown)
            while(sum <k)
            {
        // cout<<"here\n";
                dep++;
                sum+=get(1,0,MAXN,dep);
            //     trace(sum)
            // trace(dep)
            }
            // cout<<"out\n";
        }
        
        // trace(nown)
        // trace(dep)
        // trace(sum)
    }
    // REP(i,7)
    // {
    //     trace(get(1,0,MAXN,i))
    // }
    // ll ans = 0;
    // ll sum = 0;
    // trace(ind)
    // while(sum<k)
    // {
    //     ans++;
    //     sum+=get(1,0,MAXN,ans);
    //     trace(ans)
    //     trace(sum)
    // }
    // cout<<ans<<endl;
    cout<<dep<<endl;
}