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

ll t,a,b,c,d,x,y,x1,x2,y1,y2;
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        bool bo = 1;
        if(abs(b-a)>x2-x1)
        {
            bo=0;
        }
        if(abs(c-d)>y2-y1)
        {
            bo=0;
        }
        if(b>a)
        {
            if(b-a>x2-x)
            {
                bo=0;
            }
        }
        else
        {
            if(a-b>x-x1)
            {
                bo=0;
            }
        }
        if(c>d)
        {
            if(c-d>x-x1)    bo=0;
        }
        else
        {
            if(d-c>x2-x)    bo=0;
        }
    if(bo)
        cout<<"YES\n";
    else
    cout<<"NO\n";
    }
}