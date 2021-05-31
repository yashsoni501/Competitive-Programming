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

ll n,m,a[100050],b[100050];
ll prea[100050];
ll preb[100050];

int main()
{
    IOS
    cin>>n>>m;
    REP(i,n)    cin>>a[i];
    REP(i,n)    cin>>b[i];
    ll sum=0;
    REP(i,n)    sum+=a[i];
    while(sum>m)
    {
        sum-=a[n-1];
        n--;
    }
    stack<ll> mini;
    mini.push(n-1);
    ll cur=mini[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(b[i]>=cur)
        {
            cur = b[i];
            mini.push(i);
        }
    }
    REP(i,n)
    {
        prea[i+1] = pre[i]+a[i];
        preb[i+1] = pre[i]+b[i];
    }
    prea[n+1]=m+1;
    preb[n+1]=m+1;
    ll t=0;
    ll aind=0,bind=0;
    ll blcnt=0;
    ll wasted = 0;
    while(t<m+1)
    {
        if(t-wasted == preb[mini.top()+1])
        {
            if(blcnt>0)
            {
                wasted+=mini.top();
                blcnt--;
            }
            else
            {
                mini.pop();
                bind++;
            }
        }
        else if(aind < n && prea[aind+1] >= preb[bind+1]+wasted)
        {
            t=pref[aind+1];
            aind++;
            blcnt++;
        }
        else if(bind==mini.top())
        {
            t = preb[bind+1]+wasted;
        }
        else
        {
            
        }
        
    }
}