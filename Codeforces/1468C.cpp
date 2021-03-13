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

struct comp1
{
    bool operator()(pll a, pll b)
    {
        return a.ff>b.ff;
    }
};

struct comp2
{
    bool operator()(pll a, pll b)
    {
        if(a.ss!=b.ss)
            return a.ss<b.ss;
        else
            return a.ff>b.ff;
    }
};

int main()
{
    // IOS
    priority_queue<pll,vector<pll>, comp1> p1;
    priority_queue<pll,vector<pll>, comp2> p2;
    ll q,tmp,m;
    set<ll> vis;
    cin>>q;
    ll ind=1;
    while(q--)
    {
        cin>>tmp;
        if(tmp==1)
        {
            cin>>m;
            p1.push({ind,m});
            p2.push({ind,m});
            ind++;
        }
        else if(tmp==2)
        {
            while(vis.count(p1.top().ff))
            {
                p1.pop();
            }
            cout<<p1.top().ff<<endl;
            vis.in(p1.top().ff);
        }
        else
        {
            while(vis.count(p2.top().ff))
            {
                p2.pop();
            }
            cout<<p2.top().ff<<endl;
            vis.in(p2.top().ff);
        }
        // trace(p2.top().ss);
        // trace(p1.top().ff);
    }
}