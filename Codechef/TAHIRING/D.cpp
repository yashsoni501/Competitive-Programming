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

ll n,s,e[100005];
ll pre[100005];
int main()
{
    IOS
    cin>>n>>s;
    REP(i,n)    cin>>e[i];
    pre[0]=0;
    REP(i,n)    pre[i+1] = pre[i]+i+1;
    ll p1=0,p2=-1;
    ll len=0;
    ll sum=0;
    while(p2<n-1)
    {
        if(sum <= s)
        {
            len = max(len,p2-p1+1);
            p2++;
            sum+=(pre[p2]-pre[p1]) + e[p2]+(p2+1)*(p2-p1+1);
        }
        else
        {
            sum -= e[p1] + (p2-p1)*(p1+1) + pre[p2+1]-pre[p1];
            p1++;
        }
        // trace(p1)   trace(p2)   trace(sum)
    }
    if(sum<=s)
    {
        len = max(len,p2-p1+1);
    }
    cout<<len<<endl;
}