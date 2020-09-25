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
#define int long long
int dp[1 << 20];
int mat[20][20];
int n, k;

signed main()
{
    IOS int t;
    cin >> t;
    //t=1;
    while (t--)
    {
       cin >> n >> k;
      // n=20, k = 5;
        int tc=0;
        REP(i, n)
        REP(j, n)
        {
        cin >> mat[i][j];
        //mat[i][j] = rand()%100;
        tc+=mat[i][j];
        }
        tc=tc/2;
        int ans  = LLONG_MAX;
        REP(i, 1 << n)
        dp[i] = 0;
        for (int kon = 0; kon <= k; kon++)
        {
            for (int j = 0; j < (1 << (n - k)); j++)
            {
                int m = (j << k);
                if (kon)
                    m = m | (1 << (kon - 1));
                int s = m;
                while (s)
                {
                    int m2 = m ^ s;
                    int c1 = dp[m];
                    int c2 = dp[m2];
                    int lc = 0;
                    for (int lkl = 0; lkl < n; lkl++)
                    {
                        for (int lk = lkl+1; lk < n; lk++)
                        {
                            if((s & (1<<lkl)) && (m2&(1<<lk)))
                            {
                                lc+=mat[lkl][lk];
                                // trace(lkl);
                                // trace(lk);
                            }
                        }
                    }
                    dp[m] = max(dp[m] , c1+c2+lc);
                    s = (s - 1) & m;
                }
                // trace(m);
                ans = min(ans, tc-dp[m]);
            }
        }
        cout << ans << "\n";
    }
}