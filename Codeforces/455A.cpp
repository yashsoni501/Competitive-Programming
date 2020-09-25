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
ll n;
map<ll,ll> cnt;
int main()
{
    IOS
    cin>>n;
    ll tmp;
    REP(i,n)
    {
        cin>>tmp;
        cnt[tmp]++;
    }
    pll ar[cnt.size()];
    ll siz=cnt.size();
    ll ind=0;
    for(map<ll,ll>::iterator it=cnt.begin();it!=cnt.end();it++)
    {
        ar[ind].ff=it->ff;
        ar[ind].ss=it->ss;
        ind++;
    }

    sort(ar,ar+siz);
    ll dp[siz+1]={};
    dp[0]=0;
    dp[1]=ar[0].ff*ar[0].ss;
    for(int i=1;i<=siz;i++)
    {
        if(ar[i].ff!=ar[i-1].ff+1)
        {
            dp[i+1] = dp[i]+ar[i].ff*ar[i].ss;
        }
        else
        {
            dp[i+1] = max(dp[i],dp[i-1]+ar[i].ff*ar[i].ss);
        }
    }
    
    cout<<dp[siz]<<endl;
}