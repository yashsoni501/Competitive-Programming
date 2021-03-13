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

ll t,n;
char ar[350][350];

ll chk1(ll x, ll y)
{
    FOR(i,0,3,1)
    {
        if(ar[x+i][y]!='X')     return 0;
    }
    return 1;
}

ll chk2(ll x, ll y)
{
    FOR(i,-1,2,1)
    {
        if(ar[x+i][y]!='X')     return 0;
    }
    return 1;
}

ll chk3(ll x, ll y)
{
    FOR(i,-2,1,1)
    {
        if(ar[x+i][y]!='X')     return 0;
    }
    return 1;
}

ll chk4(ll x, ll y)
{
    FOR(i,0,3,1)
    {
        if(ar[x][y+i]!='X')     return 0;
    }
    return 1;
}

ll chk5(ll x, ll y)
{
    FOR(i,-1,2,1)
    {
        if(ar[x][y+i]!='X')     return 0;
    }
    return 1;
}

ll chk6(ll x, ll y)
{
    FOR(i,-2,1,1)
    {
        if(ar[x][y+i]!='X')     return 0;
    }
    return 1;
}

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        REP(i,n)
        {
            REP(j,n)
            cin>>ar[i][j];
        }
        ll macnt=-1;
        pll xy = {-1,-1};
        while(1)
        {
            macnt = 0;
            xy = {-1,-1};
            REP(i,n)
            {
                REP(j,n)
                {
                    ll cnt=0;
                    if(i<n-2)   cnt+=chk1(i,j);
                    if(i<n-1 && i>0)    cnt+=chk2(i,j);
                    if(i>1)     cnt+=chk3(i,j);

                    if(j<n-2)   cnt+=chk4(i,j);
                    if(j<n-1 && j>0)    cnt+=chk5(i,j);
                    if(j>1)     cnt+=chk6(i,j);

                    if(cnt>macnt)
                    {
                        macnt = cnt;
                        xy = {i,j};
                    }
                }
            }
            if(macnt == 0)  break;
            ar[xy.ff][xy.ss] = 'O';
            REP(i,n)
            {
                REP(j,n)    cout<<ar[i][j];
                cout<<endl;
            }
            cout<<endl;
        }
        REP(i,n)
        {
            REP(j,n)    cout<<ar[i][j];
            cout<<endl;
        }
    }
}