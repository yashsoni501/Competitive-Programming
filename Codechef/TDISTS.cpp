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
#define FOR(i,j,k,l) for(ll i=j;i<k;i+=l)
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

ll t, x,y;
vl sq;

ll sqrt(ll n)
{
    if(!binary_search(all(sq), n))  return -1;
    return lower_bound(all(sq),n)-sq.begin();
}

vpll tree;

bool constree(ll a, ll b)
{
    tree.clear();
    if(a==0 || b==0)    return 0;
    a--;
    ll cur=2;
    REP(i,b)
    {
        tree.pb({1,cur++});
    }
    REP(i,a)
    {
        tree.pb({2,cur++});
    }
    return 1;
}

void printTree()
{
    cout<<tree.size()+1<<endl;
    for(auto it:tree)
    {
        cout<<it.ff<<" "<<it.ss<<endl;
    }
}

int main()
{
    IOS
    REP(i,100005)
    {
        sq.pb(i*i);
    }
    // cin>>x>>y;
    // constree(x,y);
    // printTree();
    // return 0;
    // REP(i,10)   cout<<sq[i]<<" ";
    // cout<<endl;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        // trace(binary_search(all(sq), x+y) )
        if(!binary_search(all(sq), x+y) || sqrt(x*x-y*y)==-1)
        {
            cout<<"NO\n";
            continue;
        }
        ll nd = lower_bound(all(sq),x+y)-sq.begin();
        ll n2 = x+sqrt(x*x-y*y);
        if(n2%2)
        {
            cout<<"NO\n";
            continue;
        }
        n2/=2;
        if(sqrt(n2) == -1)
        {
            cout<<"NO\n";
            continue;
        }
        ll n = sqrt(n2);
        ll m = sqrt(x-n2);
        if(m == -1)
        {
            cout<<"NO\n";
            continue;
        }
        // cout<<m<<" "<<n<<endl;
        if(constree(m,n))
        {
            if(nd!=tree.size()+1)   cout<<1/0<<endl;
            cout<<"YES\n";
            printTree();
        }
        // else if(constree(n,m))
        // {
        //     // if(nd!=tree.size()+1)   cout<<1/0<<endl;
        //     cout<<"YES\n";
        //     printTree();
        // }
        else
        {
            cout<<"NO\n";
        }
    }
}