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

ll t,n,ar[1000000];
vl br;
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        br.clear();
        cin>>n;
        REP(i,n)    cin>>ar[i];
        REP(i,n-1)
        {
            if(ar[i]>ar[i+1])   br.pb(i+1);
        }
        
        if(sz(br)<3 || n<10)
        {
            cout<<"0 0 0"<<endl;
            continue;
        }
        ll to,g,b,s;
        to = 0;
        REP(i,sz(br))
        {
            if(br[i]<=n/2)
                to=br[i];
        }
        REP(i,sz(br))   cout<<br[i]<<" ";
        cout<<endl;
        trace(to)
        g = br[0];
        for(int i=1;i<sz(br);i++)
        {
            s = br[i]-br[0];
            b= to-g-s;
            if(g<s && g<b && g>0&&b>0&&s>0)
            {
                break;
            }
        }
        if(g<s&&g<b&&g>0&&b>0&&s>0)
        {
            cout<<g<<" "<<s<<" "<<b<<endl;

        }
        else cout<<"0 0 0\n";
    }
}