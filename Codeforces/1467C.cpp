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

ll n[3];
ll mi[3][2];
ll tmp;
ll sum = 0;
ll s1[3]={};
int main()
{
    IOS
    REP(i,3)    cin>>n[i];
    REP(i,3)
    {
        mi[i][0] = mi[i][1] = 1e10;
        REP(j,n[i])
        {
            cin>>tmp;
            sum+=tmp;
            s1[i]+=tmp;
            if(tmp<=mi[i][0])
            {
                mi[i][1] = mi[i][0];
                mi[i][0] = tmp;
            }
            else if(tmp<mi[i][1])
            {
                mi[i][1] = tmp;
            }
        }
    }
    ll mini1 = 1e10;
    ll mini2 = 1e10;
    // REP(i,3)
    // {
    //     cout<<mi[i][0]<<" "<<mi[i][1]<<endl;
    // }
    REP(i,3)
    {
        if(n[i]==1)
        {
            mini1 =  min(mini1,mi[i][0]);
        }
        else if(n[i]==2)
        {
            mini1 = min(mini1,mi[i][0]+mi[i][1]);
        }
        else
        {
            mini1 = min(mini1,s1[i]);
        }
    }
    REP(i,3)
    {
        mini2 = min(mini2,mi[i][0]+mi[(i+1)%3][0]);
    }
    // trace(mini1)    trace(mini2)
    // trace(sum)
    cout<<sum-min(2*mini2,2*mini1)<<endl;
}