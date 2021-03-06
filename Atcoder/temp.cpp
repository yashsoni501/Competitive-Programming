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

ll n,k;
ll ar[200];
ll postf[200];

ll cnt=0;

ll arr[102][100005];

ll solve(ll i,ll ke)
{
    // cnt++;
    if(arr[i][ke]!=-1)   return arr[i][ke];
    if(i==n)    return 1;
    ll sum=0;
    for(int j=ar[i];j>=0;j--)
    {
        if(ke-j<=postf[i+1])
        {
            sum = (sum+solve(i+1,k-j))%MOD;
        }
        else
        {
            break;
        }
    }
    // trace(i)
    // trace(ke)
    // trace(sum)
    arr[i][ke] = sum;
    return sum;
}

int main()
{
    IOS
    cin>>n>>k;
    REP(i,n+1)
    {
        REP(j,k+1)
        {
            arr[i][j] = -1;
        }
    }
    REP(i,n)
    {
        cin>>ar[i+1];
    }   
    ll sum=0;
    for(int i=n;i>=1;i--)
    {
        sum+=ar[i];
        postf[i] = sum;
    }
    if(k>postf[1])
    {
        cout<<0<<endl;
    }
    else    cout<<solve(1,k)<<endl;
    cout<<"cnt "<<cnt<<endl;
    REP(i,n+1)
    {
        REP(j,k+1)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}