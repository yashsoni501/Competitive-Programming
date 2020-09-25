#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
#define ff first
#define sse second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define MOD 1000000007
#define INF 1e9
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
ll te,n,q,l,r,v,ind,thr,qt;
ll clr[100005];
ll qnt[100005];
ll tp;
unordered_map<ll,ll> shop;
pair<int, int> t[400001];

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

signed main()
{
    IOS
    cin>>te;
    while(te--)
    {
        shop.clear();
        cin>>n>>q;
        REP(i,n)
        {
            cin>>clr[i];
            shop[clr[i]] = i;
        }
        REP(i,n)
        {
            cin>>qnt[i];
        }
        build(clr,1,0,n-1);
        while(q--)
        {
            cin>>tp;
            if(tp==1)
            {
                cin>>l>>r>>qt;
                l--,r--;
                qnt[shop[get_max(1,0,n-1,l,r).ff]] += qt;
            }
            else
            {
                cin>>v>>ind>>qt>>thr;
                ind--;
                ll tmp = shop[get_max(1,0,n-1,max(ind-v,0), min(n-1,ind+v)).ff];
                if(clr[tmp]>=thr && qnt[tmp]>=qt)
                {
                    cout<<tmp+1<<endl;
                    qnt[tmp]-=qt;
                }
                else
                {
                    cout<<"No purchase"<<endl;
                }
            }
            // cout<<"tmpp: ";
            // REP(i,n)
            // {
            //     cout<<qnt[i]<<" ";
            // }
            // cout<<endl;
        }
    }
}