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
int inp[100][100];
int dp[100][100]; // minimum cost to reach i,j cell
int n;
vector<int> row[10001][101]; // store ac
vector<int> col[10001][101];
map<int, tuple<int, int>> ps;

int recur(int x, int y)
{
    if (dp[x][y] != -1)
        return dp[x][y];
    if (inp[x][y] == 1)
        return 0;
    int minpc = LONG_LONG_MAX;
    int k = inp[x][y];
    k--;
    // trace(k);
    // trace(n);
    REP(i, n)
    {

        if (row[k][i].size() == 0)
            continue;
        auto po = upper_bound(all(row[k][i]), y);
        if (po != row[k][i].end())
        {
            minpc = min(minpc, recur(i, *po) + abs(x - i) + abs(y - (*po)));
        }
        if (po != row[k][i].begin())
        {
            po--;
            minpc = min(recur(i, *po) + abs(x - i) + abs(y - (*po)), minpc);
        }
    }
    REP(i, n)
    {

        if (col[k][i].size() == 0)
            continue;
        auto po = upper_bound(all(col[k][i]), x);
        if (po != col[k][i].end())
        {
            minpc = min(minpc, recur(*po, i) + abs(x - (*po)) + abs(y - i));
        }
        if (po != col[k][i].begin())
        {
            po--;
            minpc = min(minpc, recur(*po, i) + abs(x - (*po)) + abs(y - i));
        } // int chk =  recur(*po, i) + abs(x - (*po)) + abs(y - i);
        // trace(chk);
    }

    dp[x][y] = minpc;
    return minpc;
}

signed main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> n >> k;
        REP(i, n)
        {
            REP(j, k + 1)
            {
                row[j][i].clear();
                col[j][i].clear();
            }
        }
        vector<tuple<int, int>> st;
        ps.clear();
        REP(i, n)
        {
            REP(j, n)
            {
                cin >> inp[i][j];
                if (inp[i][j] == k)
                    st.push_back(make_tuple(i, j));
                row[inp[i][j]][i].push_back(j);
                col[inp[i][j]][j].push_back(i);
                dp[i][j] = -1;
            }
        }

        REP(i, n)
        {
            REP(j, k + 1)
            {
                sort(row[j][i].begin(), row[j][i].end());
                sort(col[j][i].begin(), col[j][i].end());
            }
        }

        int gmin = LLONG_MAX;

        for (auto pt : st)
        {
            gmin = min(gmin, recur(get<0>(pt), get<1>(pt)));
        }

        cout << gmin << "\n";
    }
}