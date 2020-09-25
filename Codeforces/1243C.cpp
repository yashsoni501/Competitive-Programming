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

int main()
{
    IOS
    cin>>n;
    vl divi;
    for(ll i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            divi.pb(i);
            divi.pb(n/i);
        }
    }
    if(sz(divi)==0)
    {
        cout<<n<<endl;
        return 0;
    }
    ll tmp = divi[0],n2=n;
    bool b=1;
    while(n2>1)
    {
        if(n2%tmp!=0)
        {
            b=0;
            break;
        }
        n2/=tmp;
    }

    if(b)   cout<<tmp<<endl;
    else
    {
        cout<<1<<endl;
    }
    

}