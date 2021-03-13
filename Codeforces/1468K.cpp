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

void update(pll &cood, char c)
{
    if(c=='L')
    {
        cood.ff--;
    }
    else if(c=='R')
    {
        cood.ff++;
    }
    else if(c=='U')
    {
        cood.ss++;
    }
    else
    {
        cood.ss--;
    }
}

void update2(pll &cood, char c, pll obst)
{
    if(c=='L' && !(obst.ff == (cood.ff-1) && obst.ss == cood.ss))
    {
        cood.ff--;
    }
    else if(c=='R' && !(obst.ff == (cood.ff+1) && obst.ss == cood.ss))
    {
        cood.ff++;
    }
    else if(c=='U' && !(obst.ss == (cood.ss+1) && obst.ff == cood.ff))
    {
        cood.ss++;
    }
    else if(c=='D' && !(obst.ss == (cood.ss-1) && obst.ff == cood.ff))
    {
        cood.ss--;
    }
}

pll obs(pll obst, string s)
{
    if(obst.ff == 0 && obst.ss == 0)
    {
        return {-1,-1};
    }
    pll cood = {0,0};
    REP(i,sz(s))
    {
        update2(cood, s[i], obst);
    }
    return cood;
}

int main()
{
    IOS
    ll t;
    string s;
    vpll path;
    cin>>t;
    while(t--)
    {
        pll cood = {0,0};
        path.clear();
        cin>>s;
        REP(i,sz(s))
        {
            update(cood, s[i]);
            path.pb(cood);
        }
        // REP(i,sz(path))
        // {
        //     cout<<path[i].ff<<" "<<path[i].ss<<endl;
        // }
        pll ans = {0,0};
        for(auto pt:path)
        {
            pll endpt = obs(pt, s);
            // trace(pt.ff)
            // trace(pt.ss)
            // trace(endpt.ff)
            // trace(endpt.ss)

            if(endpt.ff==0 && endpt.ss==0)
            {
                ans = pt;
                break;
            }
        }
        cout<<ans.ff<<" "<<ans.ss<<endl;
    }
}