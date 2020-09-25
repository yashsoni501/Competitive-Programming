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
int p[100+5];
int w[100+5];

signed main()
{
    int n;
    cin >> n;
    p[0] = w[0] = 0;
    REP(i, n)
    {
        cout << "1 " << (i+1) << " 10000\n";
        cin >> p[i+1];
    }

    REP(i, n)
    {
        int low = 1;
        int high = 10000;
        while(high != low)
        {
            int mid = (high+low)/2;
            cout << "1 " << (i+1) << " " << mid <<"\n";
            int pi;
            cin >> pi;
            if(pi!=p[i+1])
                low = mid+1;
            else
                high = mid;
        }
        w[i+1] = (low+high)/2;
    }

    cout << "2\n";
    REP(i, n)
        cout << w[i+1] - w[i] << " ";
    cout << "\n";
    REP(i, n)
        cout << p[i+1] - p[i] << " ";
    cout << "\n";
}