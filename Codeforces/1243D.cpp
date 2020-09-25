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

struct node
{
    int d;
    vl adj;
};

ll n,m,a,b;
vpll pr;
bool vstd[200000];
node ad[100005];
ll parent[100005];
ll ranke[100005];

bool comp(node a,node b)
{
    return sz(a.adj)<sz(b.adj);
}


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    ranke[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranke[a] < ranke[b])
            swap(a, b);
        parent[b] = a;
        if (ranke[a] == ranke[b])
            ranke[a]++;
    }
}

int main()
{
    IOS
    cin>>n>>m;
    ll cnt=0;
    REP(i,n+1)    vstd[i]=0;
    REP(i,n)    ad[i+1].d=i+1;
    REP(i,n)    make_set(i+1);
    REP(i,m)
    {
        cin>>a>>b;
        // a=i+1;
        // b=a%(n-1)+1;
        ad[a].adj.pb(b);
        ad[b].adj.pb(a);
    }
    REP(i,n)
    {
        sort(all(ad[i].adj));
    }
    //sort(ad,ad+n,comp);
    for(int i=1;i<=n;i++)
    {
        ll ind = ad[i].d;
        if(!vstd[ind])
        {
            vstd[ind]=1;
            ll indi=0;
            for(int j=1;j<=n;j++)
            {
                if(i==j)    continue;
                if(!vstd[j] && !binary_search(all(ad[i].adj),j))
                {
                    vstd[j]=1;
                    union_sets(i,j);
                }
            }
        }
    }
    //cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(parent[i]==i)   { cnt++;
        //cout<<i<<" "<<parent[i]<<endl;
        }
    }
    cout<<cnt-1<<endl;
}