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

ll t=1;
ll n,k;
ll dp1[200000],dp2[200000];
ll p[100000];
unordered_map<ll,ll> ma;
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ma.clear();
        // REP(i,n)    cin>>ar[i];
        REP(i,k)    cin>>p[i];
        sort(p,p+k);
        REP(i,k-1)
        {
            ma[p[i+1]]=p[i];
        }
        dp1[0]=0;
        dp2[0]=0;
        dp1[1]=0;
        dp2[1]=1;
        dp1[2]=1;
        dp2[2]=1;
        FOR(i,3,n+1,1)
        {
            dp1[i] = min(dp1[i-1],dp1[i-2]);
            if(ma.count(i))
            {
                dp1[i] = min(dp1[i],dp1[ma[i]]);
            }
            dp2[i]=0;
            if(dp1[i-1]==dp1[i])
            {
                dp2[i]+=dp2[i-1];
            }
            if(dp1[i-2]==dp1[i])
            {
                dp2[i]+=dp2[i-2];
            }
            if(ma.count(i) && dp1[ma[i]]==dp1[i])
            {
                dp2[i]+=dp2[ma[i]];
            }
            dp1[i]++;
        }
        // REP(i,n+1)  cout<<dp1[i]<<" ";
        // cout<<endl;
        // REP(i,n+1) cout<<dp2[i]<<' ';
        // cout<<endl;
        cout<<dp2[n]<<' '<<dp1[n]<<endl;
    }
}