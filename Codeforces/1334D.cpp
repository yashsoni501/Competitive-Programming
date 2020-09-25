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

ll t,n,l,r,l2,r2;
ll ar[500000];
ll arr[500000];
ll fndo(ll ind)
{
    ll *f = lower_bound(arr,arr+n,ind);
    return f-arr+1;
}
ll fnde(ll ind)
{
    ll *f = lower_bound(arr,arr+n,ind);
    return n-(*f-ind);
}

ll fnd(ll ind)
{
    if(ind == n*n-n+1)  return 1;
    if(ind%2==0)
    {
        return fnde((ind+1)/2);
    }
    else
    {
        return fndo((ind+1)/2);
    }
    
}

int main()
{
    // IOS
    cin>>t;
    n=0;
    while(t--)
    {
        cin>>n>>l>>r;
        ll sum=0;
        REP(i,n)
        {
            sum+=n-i-1;
            arr[i] = sum;
        }
        for(ll i=l;i<=r;i++)
        {
            cout<<fnd(i)<<" ";
        }
        cout<<endl;
    }
    
}   