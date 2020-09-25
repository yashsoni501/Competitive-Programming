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
int dp0[100000+5];
int cc[100000+5];
int dp1[100000+5];

vector<int> G[100000+5];

int dfs0(int c, int p)
{
    int lc = 0;
    for(int x:G[c])
    {
        if(x==p)    continue;
        int s = dfs0(x, c);
        dp0[c] = max(dp0[c], s);
        cc[c]++;
        lc += s;
    }
    lc+=1;
    dp1[c] = lc;
    return lc; 
}

void dfs1(int c, int p, int cv)
{
    if(cv!=-1)
    {
        dp0[c] = max(dp0[c], cv);
        dp1[c] += cv;
        cc[c]++;
    }

    for(int x:G[c])
    {
        if(x==p)    continue;
        dfs1(x, c, dp1[c] - dp1[x]);
    }
}

signed main()
{
    IOS
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        REP(i, n-1)
        {
            int x, y;
            cin >> x >> y;
            x--;y--;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        REP(i,n)
        {
            dp0[i]=dp1[i]=cc[i]=0;
        }
        string ans;
        if(n&1)
        {
            REP(i, n)
             ans+='0';
            cout << ans << "\n";
            continue;
        }
        dfs0(0, -1);
        dfs1(0, -1, -1);

        REP(i, n)
        {
            if(cc[i]==1)
            {
                if(dp0[i]==1)
                    ans+='1';
                else
                    ans+='0';
            }
            else
            {
                int k = dp0[i];
                if(k<(n>>1))
                {
                    ans+='1';
                }
                else
                    ans+='0';
            }

            // trace(i);
            // for(auto x : dp0[i])
            //     trace(x);
        }
        cout << ans << "\n";
    }
}