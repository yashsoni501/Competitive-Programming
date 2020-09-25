#include<bits/stdc++.h>
using namespace std;
 
#define ll int
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define e6 1000000
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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = 1000005;
        bit.assign(n, 0);
    }

    void prt()
    {
        REP(i,sz(bit))
        {
            if(bit[i]!=0)
                cout<<i<<" ";
        }
        cout<<endl;
    }

    void init(vl a) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void bs(ll l, ll h, ll ele, FenwickTree &ft)
{
    ll mid = (h+l)/2;
    while(h-l>1)
    {
        if(ft.sum(mid)>=ele)
        {
            h = mid;
        }
        else
        {
            l = mid;
        }
        mid = (h+l)/2;
    }
    // trace(h)

    // trace(ft.sum(e6+1))
    ft.add(h,-1);
    // trace(ft.sum(e6+1))
}
void bs2(ll l, ll h, ll ele, FenwickTree &ft)
{
    ll mid = (h+l)/2;
    while(h-l>1)
    {
        if(ft.sum(mid)>=ele)
        {
            h = mid;
        }
        else
        {
            l = mid;
        }
        mid = (h+l)/2;
    }
    cout<<h<<endl;
}

ll n,q;
vl ar(1000005,0);
ll tmp;
FenwickTree ft(e6+5);
int main()
{
    IOS
    cin>>n>>q;
    REP(i,n)
    {
        cin>>tmp;
        ar[tmp]++;
    }
    ft.init(ar);
    // ft.prt();
    while(q--)
    {
        cin>>tmp;
        if(tmp>0)
        {
            ft.add(tmp,1);
        }
        else
        {
            bs(0,e6+1,-tmp,ft);
        }    
        // ft.prt();   
    } 
    if(ft.sum(e6+1)==0)
    {
        cout<<0<<endl;
    }
    else
    {
        bs2(0,e6+1,1,ft);
    }
    
}