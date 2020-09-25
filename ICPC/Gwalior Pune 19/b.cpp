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

#define int long long
int ps[200000+5];
signed main()
{
    IOS
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        REP(i, n)
            cin >> ps[i+1];
        REP(i, n)
            ps[i+1] += ps[i];
        for(int i = n+1; i<=100000+1;i++)
        {
            int s= ps[i-1] - ps[i-1-n];
            ps[i] = ps[i-1] + (s/n);
        }

        int q;
        cin >> q;
        while(q--)
        {
            int l;
            cin >> l;
            if(l>1e5) l=1e5;
            cout << ps[l]-ps[l-1] << "\n";
        }
        
    }
}