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
tuple<int, int> pt[100000+5];
tuple<double, double> md[100000+5];
signed main()
{
    IOS
    int n;
    cin >> n;
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(8);

    REP(i, n)
    {
        int x, y;
        cin >> x >> y;
        pt[i] = make_tuple(x, y);
    }
    REP(i, n)
    {
        double xm = get<0>(pt[i]) + get<0>(pt[(i+1)%n]);
        double ym = get<1>(pt[i]) + get<1>(pt[(i+1)%n]);
        xm = xm/2;
        ym = ym/2;
        md[i] = make_tuple(xm, ym);
        // trace(i);
        // trace(xm);
        // trace(ym);
    }
    double area = 0;

    REP(i, n)
    {
        area += get<0>(md[i])*get<1>(md[(i+1)%n]) - get<0>(md[(i+1)%n])*get<1>(md[i]);
       // trace 
    }

    area = abs(area)/2;

    cout << area;

}