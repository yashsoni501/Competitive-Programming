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


ll n,a[100000],b[100000];
ll ab[5005][5005];
ll pref[100000];
int main()
{
    IOS
    cin>>n;
    REP(i,n)    cin>>a[i];
    REP(i,n)    cin>>b[i];
    ll prod=0;
    REP(i,n)    REP(j,n)    ab[i+1][j] = a[i]*b[j];
    REP(i,n)    prod+=a[i]*b[i];
    // REP(i,n+1)
    // {
    //     REP(j,n+1)  cout<<ab[i][j]<<" ";
    //     cout<<endl;
    // }
    REP(i,n)
    {
        for(int j=n-1;j>0;j--)
        {
            ab[i+2][j-1] += ab[i+1][j];
        }
    }
    // REP(i,n+1)
    // {
    //     REP(j,n+1)  cout<<ab[i][j]<<" ";
    //     cout<<endl;
    // }
    REP(i,n+1)  pref[i+1]=pref[i]+a[i]*b[i];
    ll ma=0;
    REP(i,n)
    {
        FOR(j,i+1,n,1)
        {
            ma = max(ab[j+1][i]-ab[i][j+1] - (pref[j+1]-pref[i]) , ma);
            // trace(ma)
        }
    }
    cout<<prod+ma<<endl;
}