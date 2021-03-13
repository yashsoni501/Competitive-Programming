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

ll n,t;
pll ln[600][2];
pll st;
vector<ll> tim;
vpll pos;
bool type[600];
vl ins[600];
bool dir[600];

pll intersection(pll a[2],pll b[2])
{
    pll pt;
    if(a[0].ff == a[1].ff)
    {
        pt = {a[0].ff, b[1].ss};
    }
    else
    {
        pt = {a[0].ss, b[1].ff};
    }
    if(pt.ff < a[0].ff || pt.ff > a[1].ff)
    {
        return {-1,-1};
    }
    if(pt.ff < b[0].ff || pt.ff > b[1].ff)
    {
        return {-1,-1};
    }
    if(pt.ss < a[0].ss || pt.ss > a[1].ss)
    {
        return {-1,-1};
    }
    if(pt.ss < b[0].ss || pt.ss > b[1].ss)
    {
        return {-1,-1};
    }

    return pt;
}

int main()
{
    IOS
    cin>>n>>t;
    REP(i,n)
    {
        cin>>ln[i][0].ff>>ln[i][0].ss;
        cin>>ln[i][1].ff>>ln[i][1].ss;
        sort(ln[i], ln[i]+2);
        type[i] = 0;        // hori
        if(ln[i][0].ff == ln[i][1].ff)
        {
            type[i] = 1;    // verti
        }
    }
    st = ln[0][0];
    tim.pb(0);
    pos.pb(st);
    REP(i,n)
    {
        FOR(j,i+1,1,n)
        {
            if(type[i] == type[j])
            {
                continue;
            }
            pll pt = intersection(ln[i],ln[j]);
            if(pt.ff == -1)
            {
                continue;
            }
            if(type[i]==0)
            {
                ins[i].pb(pt.ss);
            }
            else
            {
                ins[i].pb(pt.ff);
            }
        }
    }
    REP(i,n)
    {
        sort(all(ins[i]));
    }
    
}
