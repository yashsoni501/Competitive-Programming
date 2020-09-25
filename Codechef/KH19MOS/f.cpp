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
int tab[100000+5][2];

int cans(int n, int k, int msize)
{
    int jc =0;
    REP(i, n)
    {
        int ljc = 0;
        if(msize == 1 && tab[i][1])
            return -1;
        int os = 0;
        int ts = 0;
        int tsj = msize/2;
        int osj = msize - 2*(tsj);
        // trace(tsj);
        // trace(osj);
        while(os + osj < tab[i][0] && ts + tsj< tab[i][1])
        {
            ljc+=1;
            os+=osj;
            ts+=tsj;
        }
        while(os < tab[i][0] || ts < tab[i][1])
        {
            int dts = tab[i][1] - ts;
            dts = min(dts, tsj);
            int dos = msize-2*dts;
            dos = min(dos, tab[i][0] - os);
            ljc+=1;
            os+=dos;
            ts+=dts;
        }
        jc += ceil(((double)(ljc))/k);
    }
    return jc;
}

int main()
{
    IOS
    int t;
    cin >> t;
    while(t--)
    {
        int n, j, k;
        cin >> n >> k >> j;
        int slow = 1;
        REP(i, n)
        {
            tab[i][0]=tab[i][1]=0;
        }

        REP(i, n)
        {
            int t, v;
            cin >> t >> v;
            t--;
            tab[t][v-1]++;
            if(v==2)    slow=2;
        }

        int shigh = 2*100000+1;
        while(shigh-slow!=0)
        {
            int smid = (slow+shigh)/2;
            // trace(shigh);
            // trace(cans(n, k, smid));
            // trace(slow);
            if(cans(n, k, smid) > j)
                slow = smid+1;
            else
                shigh = smid;
        }

        cout << (slow+shigh)/2 << "\n";
    }
}