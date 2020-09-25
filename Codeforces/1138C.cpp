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

ll n,m;
ll ar[1100][1100];
vl row[1100],col[1100];
set<ll> rows[1100],cols[1100];
ll ans[1100][1100];
int main()
{
    IOS
    cin>>n>>m;
    REP(i,n)    REP(j,m)    cin>>ar[i][j];
    REP(i,n)
    {
        REP(j,m)
        {
            rows[i].in(ar[i][j]);
            cols[j].in(ar[i][j]);
        }
        // sort(all(row[i]));
    }
    REP(i,n)
    {
        for(auto it:rows[i])
        {
            row[i].pb(it);
        }
    }
    REP(i,m)
    {
        for(auto it:cols[i])
        {
            col[i].pb(it);
        }
    }
    // REP(i,m)    sort(all(col[j]));
    REP(i,n)
    {
        REP(j,m)
        {
            ll tmp1 = lower_bound(all(row[i]), ar[i][j])-row[i].begin();
            ll tmp2 = lower_bound(all(col[j]),ar[i][j])-col[j].begin();
            ll a = sz(row[i]);
            ll b = sz(col[j]);
            // trace(i)    trace(j)    trace(tmp1) trace(tmp2) trace(a)    trace(b)
            if(tmp1>tmp2)
            {
                b += tmp1-tmp2;
            }
            else
            {
                a+=tmp2-tmp1;
            }
            ans[i][j] = max(a,b);
        }   
    }
    REP(i,n)
    {
        REP(j,m)   
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}