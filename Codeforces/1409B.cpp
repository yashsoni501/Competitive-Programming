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

int main()
{
    IOS
    ll t,a,b,x,y,n;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>x>>y>>n;
        ll a1=a,b1=b;
        a=max(a-n,x);
        ll n2=n-(a1-a);
        b=max(b-n2,y);
        ll l=a*b;

        a=a1,b=b1;
        b=max(b-n,y);
        n2=n-(b1-b);
        a=max(a-n2,x);
        ll m=a*b;
        // if(a<b)
        // {
        //     ll n2=n-min(n,a-x);
        //     a=max(x,a-n);

        //     n=n2;
        //     b = max(y,b-n2);
        // }
        // else
        // {
        //     ll n2=n-min(n,b-y);
        //     b=max(y,b-n);

        //     n=n2;
        //     a = max(x,a-n2);
        // }
        cout<<min(l,m)<<endl;
    }
}