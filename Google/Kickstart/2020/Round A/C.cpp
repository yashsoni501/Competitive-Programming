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

ll t,n,k;
map<pll,ll> ma;

typedef pair<pll, ll> plll;
class comp
{
public:

  bool operator() (const plll& lhs, const plll&rhs) const
  {
    return lhs.ss<rhs.ss;
  }
};
int main()
{
    IOS
    cin>>t;
    REP(te,t)
    {
        priority_queue<plll,vector<plll>,comp> pq;
        ma.clear();
        // cin>>n>>k;
        n=2,k=
        ll tmp,tmp2;
        REP(i,n)
        {
            cin>>tmp;
            
            if(i)
            {
                ma[{(i-1)*1e10,i*1e10}] = tmp-tmp2;
                pq.push({{(i-1)*1e10,i*1e10},tmp-tmp2});
            }
            tmp2 = tmp;
        }
        while(k)
        {
            plll p = pq.top();
            pq.pop();
            ll a = p.ff.ff;
            ll b = p.ff.ss;
            ll c = p.ss;
            // trace(a)    trace(b)    trace(c)
            if(c==1)
                break;
            ll mid = (a+b)/2;
            ma.erase({a,b});
            ma[{a,mid}] = c/2;
            ma[{mid+1,b}] = c-c/2;
            pq.push({{a,mid},c/2});
            pq.push({{mid+1,b},c-c/2});
            k--;
        }
        plll p = pq.top();
        ll ans = p.ss;

        cout<<"Case #"<<te+1<<": "<<ans<<endl;       
    }
}