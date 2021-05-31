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
int sgn(ll x)
{
    return (x > 0) - (x < 0);
}

ll n;
vpll xv;

struct crash
{
    ll lid;
    ll rid;
    ll num;
    ll den;
};

struct comp
{
    bool operator()(crash const& c1, crash const& c2)
    {
        return c1.num*c2.den<c2.num*c1.den;
    }
};
ll x,v;
int main()
{
    IOS
    set<int> st;
    set<int> sr;
    priority_queue<crash, vector<crash>, comp> pq;
    cin>>n;
    st.in(n+1);
    st.in(0);
    sr.in(-0);
    sr.in(-n-1);
    REP(i,n)
    {
        cin>>x>>v;
        st.in(i+1);
        sr.in(-i-1);
        xv.pb({x,v});
    }
    REP(i,n-1)
    {
        crash c = {i+1,i+2, (xv[i+1].ff-xv[i].ff)*sgn(xv[i+1].ss-xv[i].ss), abs(xv[i+1].ss-xv[i].ss)};
        if(sgn(xv[i+1].ss-xv[i].ss)<0)
            pq.push(c);
    }
    while(!pq.empty())
    {
        crash top = pq.top();
        pq.pop();
        // trace(top.lid)
        // trace(top.rid)
        // for(auto it:st) cout<<it<<" ";
        // cout<<endl;
        if(!st.count(top.lid) || !st.count(top.rid))    continue;
        st.erase(top.lid);
        sr.erase(-top.lid);
        st.erase(top.rid);
        sr.erase(-top.rid);
        ll rt = *st.upper_bound(top.rid);
        ll lt = -1*(*sr.upper_bound(-top.lid));
        if(lt!=0 && rt!=n+1)
        {
            crash newtop = {lt,rt,(xv[rt-1].ff-xv[lt-1].ff)*sgn(xv[rt-1].ss-xv[lt-1].ss), abs(xv[rt-1].ss-xv[lt-1].ss)};
            if(sgn(xv[rt-1].ss-xv[lt-1].ss)<0)
                pq.push(newtop);
        }
    }
    cout<<sz(st)-2<<endl;
    for(auto it:st)
    {
        if(it!=0 && it!=(n+1))
        cout<<it<<" ";
    }
    cout<<endl;
}