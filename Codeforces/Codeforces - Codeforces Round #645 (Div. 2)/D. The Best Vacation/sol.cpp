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

ll n,x;
ll d[500000];
ll d2[500000];
int main()
{
    IOS
    cin>>n>>x;
    REP(i,n)    cin>>d[i];
    REP(i,n)
    {
        d2[n+i] = d2[i] = d[i]*(d[i]+1)/2;
        d[n+i] = d[i];
    }
    vl sum,sum2;
    sum.pb(0);
    sum2.pb(0);
    partial_sum(d,d+2*n,back_inserter(sum));
    partial_sum(d2,d2+2*n,back_inserter(sum2));
    ll p1=0,p2=0;
    ll ma = -1;

    while(p1<n)
    {
        while(sum[p2]-sum[p1]<x)
        {
            p2++;
        }
        if(sum[p2]-sum[p1]>x)
        {
            p2--;
        }
        // trace(p1)   trace(p2)
        ll rem = x-(sum[p2]-sum[p1]);
        ll su = sum2[p2]-sum2[p1];
        su+=rem*(rem+1)/2;
        // trace(su)
        // cout<<endl;
        ma = max(ma,su);
        p1++;
    }
    p2 = 2*n,p1=2*n;
    while(p1>n)
    {
        while(sum[p1]-sum[p2]<x)
        {
            p2--;
        }
        if(sum[p1]-sum[p2]>x)
        {
            p2++;
        }
        // trace(p1)   trace(p2)
        
        ll rem = d[p2-1]-(x-(sum[p1]-sum[p2]));
        // trace(rem)
        ll su = sum2[p1]-sum2[p2-1];
        su-=rem*(rem+1)/2;
        // trace(su)
        // cout<<endl;
        ma = max(ma,su);
        p1--;
    }
    cout<<ma<<endl;
}