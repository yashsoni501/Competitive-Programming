#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238
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

ll n,h;
pll ar[300000];

double distance(pll a, pll b)
{
    return sqrt((a.ff-b.ff)*(a.ff-b.ff) + (a.ss-b.ss)*(a.ss-b.ss));
}

double angle(pll A, pll B, pll C)
{
    pll a, b;
    a.ff = B.ff-A.ff;
    a.ss = B.ss-A.ss;

    b.ff = C.ff-B.ff;
    b.ss = C.ss-B.ss;

    return acos(-((a.ff*b.ff+a.ss*b.ss)/distance(A,B)/distance(B,C)));
}

int main()
{
    IOS
    cin>>n>>h;
    REP(i,n)
    {
        cin>>ar[i].ff>>ar[i].ss;
    }
    cout<<fixed<<setprecision(8);
    double dist=0;
    pll eye = {ar[n-1].ff, ar[n-1].ss+h};
    double highang = 0;
    double prevang = 0;
    for(int i=n-2;i>=0;i--)
    {
        double thisang = angle(ar[i], eye, ar[n-1]);
        // trace(thisang)
        // trace(highang)
        // trace(prevang)
        if(thisang - highang > -1e-10)
        {
            if(prevang - highang > -1e-10)
                dist += distance(ar[i],ar[i+1]);
            else
            {
                double ang1 = thisang-highang;
                double ang2 = angle(ar[i+1],ar[i],eye);
                double ang3 = PI-ang1-ang2;
                dist += sin(ang1)/sin(ang3)*distance(ar[i],eye);
            }
        }
        prevang = thisang;
        highang = max(highang, thisang);
        
    }
    cout<<dist<<endl;
}