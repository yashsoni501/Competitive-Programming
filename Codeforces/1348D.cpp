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

ll t,n,d;
vl vt,vt2;

map<ll,vl> ma;
vl solve(ll x)
{
    if(ma.find(x)!=ma.end())
    {
        return ma[x];
    }
    if(x == 1)
    {
        vl tmp = {1};
        ma[x] = tmp;
        return tmp;
    }
    if(x%2==0)
    {
        vl tmp = solve(x/2);
        tmp.pb(x);
        ma[x] = tmp;
        return tmp;
    }
    vl tmp1 = solve((x+1)/2);
    vl tmp2 = solve((x-1)/2);
    if(sz(tmp1) > sz(tmp2))
    {
        tmp2.pb(x);
        ma[x] = tmp2;
        return tmp2;
    }
    else
    {
        tmp1.pb(x);
        ma[x] = tmp1;
        return tmp1;
    }
}

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        d=0;
        ma.clear();
        vt2.clear();
        vt.clear();
        cin>>n;
        vt = solve(n);
        // prv(vt)
        reverse(all(vt));
        REP(i,sz(vt)-1)
        {
            vt2.pb(vt[i]-vt[i+1]);
        }
        vt2.pb(1);
        cout<<sz(vt2)-1<<endl;
        for(int i=sz(vt2)-1;i>0;i--)
        {
            cout<<vt2[i-1]-vt2[i]<<" ";
        }
        cout<<endl;
    }
}