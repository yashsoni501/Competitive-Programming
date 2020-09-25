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
ll binpow(ll n, ll k)
{
    if(k==0)    return 1;
    if(k&1)
        return binpow(n, k-1)*n;
    ll r = binpow(n, k/2);
    return r*r;
}
#define int long long

struct node
{
    node *l;
    node *r;
    int qr, ql;
    int v;
    int lb;
};
node *ps = 0;
node *roots[2*100000+5];
void build(node *&cn, int ql, int qr)
{
    if (cn == 0)
    {
        cn = new node();
        cn->l = 0;
        cn->r = 0;
        cn->qr = qr;
        cn->ql = ql;
        cn->v = 0;
    }
    if (ql == qr)
    {
        cn->lb = 0;
        return;
    }
    build(cn->l, ql, (ql + qr) / 2);
    build(cn->r, (ql + qr) / 2 + 1, qr);
}
int k;
void insert(int v, node *&cn, node *cp, int ql, int qr)
{
    if (cn == 0)
    {
        cn = new node();
        cn->l = 0;
        cn->r = 0;
        cn->qr = qr;
        cn->ql = ql;
        cn->v = cp->v;
        cn->lb = cp->lb;
    }
    //(2k-n)ak
    if (ql != qr)
    {
        if (v >= ql && v <= (ql + qr) / 2)
        {
            insert(v, cn->l, cp->l, ql, (ql + qr) / 2);
            if (cp != 0)
                cn->r = cp->r;
            cn->v = add(cn->l->v, cn->r->v);
            trace(ql);
            trace(qr);
            trace(cn->v);
            return;
        }
        else
        {
            insert(v, cn->r, cp->r, (ql + qr) / 2 + 1, qr);
            if (cp != 0)
                cn->l = cp->l;
            cn->v = add(cn->l->v, cn->r->v);

            return;
        }
    }
    if(ql==qr)
    {
        cn->v=0;
        cn->lb++;
        cn->v = binpow(cn->lb, k);
    }
}
int v[2*100000+5];
signed main()
{
    IOS
    int n;
    cin >> n >> k;
    build(roots[0], 1, n);
    REP(i, n)
    {
        cin >> v[i];
        insert(v[i], roots[i+1], roots[i], 1, n);
    }

    int ans = 0;
    for(int i =1;i<=n;i++)
    {
        trace(roots[i]->v);
        ans = add(ans, mul((2*k-n), roots[i]->v));
    }
    cout << ans << "\n";
}