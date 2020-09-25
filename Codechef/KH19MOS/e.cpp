#include <bits/stdc++.h>
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
#define prv(a)            \
    for (auto x : a)      \
        cout << x << ' '; \
    cout << '\n';
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define OTP(s) cout << s << endl;
#define FOR(i, j, k, l) for (int i = j; i < k; i += l)
#define REP(i, j) FOR(i, 0, j, 1)
inline ll add(ll a, ll b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
inline ll sub(ll a, ll b)
{
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}
inline ll mul(ll a, ll b) { return (ll)((ll)a * b % MOD); }
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

ll min(ll a, ll b)
{
    return a > b ? b : a;
}
ll max(ll a, ll b)
{
    return a > b ? a : b;
}

int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int bs = 0, gs = 0;
        REP(i, sz(s))
        {
            if (s[i] == 'b')
                bs++;
            else   
                gs++;
        }
        ll b = max(bs,gs);
        ll a = min(bs,gs);
        ll exb = b-a-1;
        ll ans;
        if(a==b)
        {
            ans = a*(a+1)*(2*a+1)/3-a*a;
        }
        else
        {
            ll x = exb/2, y = (exb+1)/2;
            ans = a*(a+1)*(2*a+1)/3;
            ans += a*a*x+a*(x*(x+1))/2;
            ans += a*a*y+a*(y*(y+1))/2;
        }
        cout<<ans<<endl;
    }

}