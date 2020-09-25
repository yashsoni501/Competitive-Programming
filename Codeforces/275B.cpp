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

int main()
{
    IOS
    ll n,m;
    cin>>n>>m;
    bool ar[50][50];
    REP(i,n)
    {
        REP(j,m)
        {
            char a;
            cin>>a;
            ar[i][j] = (a=='W')?0:1;
        }
    }   
    REP(i,n)
    {
        bool a=0,b=0;
        REP(j,m)
        {
            if(ar[i][j] && !a)
            {
                a=1;
            }
            else if(a && !ar[i][j])
            {
                b=1;
            }
            else if(ar[i][j] && b)
            {
                cout<<"NO\n";
                return 0;
            }
        }
    }
    REP(j,m)
    {
        bool a=0,b=0;
        REP(i,n)
        {
            if(ar[i][j] && !a)
            {
                a=1;
            }
            else if(a && !ar[i][j])
            {
                b=1;
            }
            else if(ar[i][j] && b)
            {
                cout<<"NO\n";
                return 0;
            }
        }
    }

    vpll pts;
    REP(i,n)
    {
        REP(j,m)
        {
            if(ar[i][j])
            {
                pts.pb({i,j});
            }
        }
    }
    REP(i,sz(pts))
    {
        for(int j=i+1;j<sz(pts);j++)
        {
            if(!ar[pts[i].ff][pts[j].ss] && !ar[pts[j].ff][pts[i].ss])
            {
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
}