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
int a[100000+5];
int ct[100000+5];
int ct2[100000+5];
signed main()
{
    IOS
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        REP(i, n)
        {
            cin >> a[i];
        }
        if(k>=n)
        {
            cout << (n*(n-1))/2<<"\n";
            continue;
        }
        sort(a, a+n);
        int ind = 0;
        ct[0] = 1;
        for(int i =1;i<n;i++)
        {
            if(a[i]!=a[i-1])
                ct[++ind] = 1;
            else
                ct[ind]++;
        }
        int siz = ind+1;
        sort(ct, ct+siz);
        REP(i, n)
            ct2[i]=0;
        REP(i, siz)
            ct2[ct[i]]++;
        int maxc = ct[ind];
        // trace(siz);
        // trace(ct2[1]);
        while(k>0 && maxc>1)
        {
            ct2[maxc]--;
            ct2[maxc-1]++;
            ct2[1]++;
            k--;
            if(ct2[maxc]==0)    maxc--;
        }
        // trace(maxc);
        int divc = 0;
        REP(i, maxc+1)
        {
            if(i==0)    continue;
            divc += ct2[i]*(n-i)*i;
            // trace(ct2[i]);
        }
        cout << (divc/2) << "\n";
    }
}