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

ll k;
int main()
{
    IOS
    cin>>k;
    if(k==0)
    {
        cout<<"6 9\n1 4\n1 5\n1 6\n2 4\n2 5\n2 6\n3 4\n3 5\n3 6\n0\n";
        return 0;
    }
    
    ll num6 = k-1;
    ll n = 2*5+(k-1)*6;
    vl bpt;
    vpll edges;
    edges.pb({1,2});
    edges.pb({2,3});
    edges.pb({4,2});
    edges.pb({1,3});
    edges.pb({3,4});
    edges.pb({1,5});
    edges.pb({4,5});
    bpt.pb(2);
    edges.pb({6,7});
    edges.pb({7,9});
    edges.pb({8,9});
    edges.pb({9,10});
    edges.pb({6,8});
    edges.pb({8,10});
    edges.pb({7,10});
    bpt.pb(11);
    
    if(k==1)
    {
        edges.pb({6,5});
        bpt.pb(15);
    }
    else
    {
        edges.pb({13,5});
        bpt.pb(15);
        edges.pb({6*num6+10,6});
        bpt.pb(16);
        REP(i,k-2)
        {
            bpt.pb(17+i);
            edges.pb({10+6*i+6,10+6*(i+1)+3});
        }
        REP(i,num6)
        {
            ll sup = 10+6*i;
            edges.pb({sup+1,sup+6});
            edges.pb({sup+1,sup+5});
            edges.pb({sup+1,sup+4});
            edges.pb({sup+2,sup+6});
            edges.pb({sup+2,sup+5});
            edges.pb({sup+2,sup+4});
            edges.pb({sup+3,sup+5});
            edges.pb({sup+3,sup+4});
        }
    }
    
    
    cout<<n<<" "<<sz(edges)<<endl;
    REP(i,sz(edges))
    {
        cout<<edges[i].ff<<" "<<edges[i].ss<<endl;
    }
    cout<<2<<endl;
    REP(i,2)
    {
        cout<<bpt[i]<<endl;
    }
    // for(int i=15;i<25;i++)
    // {
    //     cout<<edges[i-1].ff<<" "<<edges[i-1].ss<<endl;
    // }

}