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

ll t,n;
ll d;
ll ar[20000];
set<ll> poss;
vector<ll> vt;
vector<ll> tmp;
ll check(ll num)
{
    ll td=d;
    ll cnt=0;
    tmp.clear();
    REP(i,n)
    {
        if(ar[i]%num==0)
        {
            td-=ar[i]/num;
            cnt+=ar[i]/num-1;
            if(td==0)
            {
                return cnt;
            }
            if(td<0)
            {
                return cnt-td+1;
            }
        }
    }
    REP(i,n)
    {
        if(ar[i]%num!=0)
        {
            td-=ar[i]/num;
            cnt+=ar[i]/num;
            if(td==0)
            {
                return cnt;
            }
            if(td<0)
            {
                return cnt-td;
            }
        }
    }
    // trace(num)  trace(cnt) trace(td)
    return 1e10;
}

ll lcm(ll a,ll b)
{
    return a*b/__gcd(a,b);
}
int main()
{
    IOS
    cin>>t;
    REP(te,t)
    {
        poss.clear();
        vt.clear();
        cin>>n>>d;
        REP(i,n)    cin>>ar[i];
        ll x=1;
        REP(i,25)
        {
            x = lcm(x,i+1);
        }
        trace(x)
       
        REP(i,n)
        {
            ar[i]*=x;
        }
        sort(ar,ar+n);
        REP(i,n)
        {
            for(int j=1;j<=d;j++)
            {
                poss.in(ar[i]/j);
            }
        }
        // prv(poss)
        for(auto it:poss)
        {
            if(it!=0)
            {
                vt.pb(it);
            }
        }
        // prv(vt)
        ll ans=1e16;
        REP(i,sz(vt))
        {
            ans = min(ans, check(vt[i]));
        }
        cout<<"Case #"<<te+1<<": "<<ans<<endl;
    }    
}