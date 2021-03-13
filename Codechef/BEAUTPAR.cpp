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

ll t,n,k,a[1000000],b[1000000];
vpll ind;

vl lis(vpll const& a) {
    int n = a.size();
    ll INF = 1e15;
    vpll d(n+3, {INF,INF});
    d[0] = {0,0};

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1].ff < a[i].ff && a[i].ff > d[j].ff)
            d[j] = a[i];
    }
    // FOR(i,1,sz(d)-1,1)
    // REP(i,sz(d))
    // {
    //     cout<<d[i].ss<<" ";
    // }
    // cout<<endl;
    vl ans;
    FOR(i,0,sz(d),1)
    {
        if(d[i+1].ss == INF) break;
        ans.pb(d[i+1].ss-d[i].ss);
    }
    return ans;
}

signed main()
{
    IOS
    cin>>t;
    while(t--)
    {
        ind.clear();
        cin>>n>>k;
        REP(i,n)
        {
            cin>>a[i];
        }
        b[0] = 0;
        REP(i,n)
        {
            b[i+1] = b[i]+a[i];
        }
        // ind.pb({b[0],0});
        REP(i,n+1)
        {
            if(b[i]>0 && b[i]<b[n])
            {
                ind.pb({b[i],i});
            }
        }
        ind.pb({b[n],n});
        vl ans = lis(ind);
        if(sz(ans)<k)
        {
            cout<<"NO\n";
            continue;
        }
        else
        {
            cout<<"YES\n";
        }
        REP(i,k-1)
        {
            cout<<ans[i]<<" ";
        }

        ll sum=0;
        FOR(i,k-1,sz(ans),1)
        {
            sum+=ans[i];
        }
        cout<<sum<<endl;
    }
}