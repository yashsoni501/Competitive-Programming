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
vector<int> asd;
void generate1(int numbits, int acc, int maxb)
{
    if (numbits <= 0)
    {
        asd.push_back(acc);
    }
    for (int bit = 0; bit < maxb; ++bit)
    {
        if (acc < (1 << bit))
        {
            generate1(numbits - 1, acc | (1 << bit), maxb);
        }
    }
}

signed main()
{
    IOS int n, k;
    cin >> n >> k;
    generate1(n, 0 ,n + k);
    int lcost = LLONG_MAX;
    int ls;
    trace(asd.size());
    for (int x : asd)
    {
        
        int lc = 0;
        int oc = 0;
        for (int i = 0; i < n + k; i++)
        {
            for (int j = 0; j < n + k; j++)
            {
                if (((x>>i)&1) && (((~x) >> j) & 1))
                {
                        lc += abs(j - i);
                }
            }
            if((x>>i)&1)
                oc++;
        }
        if(oc != n) continue;
        lcost = min(lc, lcost);
        // for (int i = 0; i < n + k; i++)
        // {
        //     if (x & (1 << i))
        //         cout << 1;
        //     else
        //         cout << 0;
        // }
        // cout << "\n" << ls << "\n";

        if (lcost == lc)
            ls = x;
    }

    for (int i = 0; i < n + k; i++)
    {
        if (ls & (1 << i))
            cout << 1;
        else
            cout << 0;
    }
    cout << "\n" << lcost << "\n";
}