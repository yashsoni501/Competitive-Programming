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

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy, ll &lxx,ll &rxx) {
    ll x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    trace(x)    trace(y)
    a /= g;
    b /= g;
    trace(g)
    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    ll rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    lxx = lx;
    rxx = rx;
    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

int main()
{
    IOS
    ll n,p,w,d,x,y,z;
    cin>>n>>p>>w>>d;
    ll gc = gcd(w,d,x,y);
    trace(x)    trace(y)
    ll lx,rx,ly,ry;
    ll tmp = find_all_solutions(w,d,p,0,n,0,n,lx,rx);
    trace(tmp)
    if(tmp == 0)
    {
        cout<<-1<<endl;
        return 0;
    }
    ly = (p-rx*w)/d;
    ry = (p-lx*w)/d;
    trace(lx)   trace(rx)   trace(ly)   trace(ry)
    bool found = 0;
    for(ll i=0;;i++)
    {
        x = lx+i*d/gc;
        if(x>rx)
            break;
        
        y = (p-x*w)/d;
        trace(x)    trace(y)    trace(n-x-y)
        if(n-x-y>=0)
        {
            z=n-x-y;
            found = 1;
            break;
        }
    }
    if(!found)  cout<<-1<<endl;
    else    cout<<x<<" "<<y<<" "<<z<<endl;
}