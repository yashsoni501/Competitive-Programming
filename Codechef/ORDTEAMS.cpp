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

struct nd
{
    ll a,b,c;
};

bool comp(nd x,nd y)
{
    if(x.a!=y.a)
        return x.a<y.a;
    if(x.b!=y.b)
        return x.b<y.b;
    if(x.c!=y.c)
        return x.c<y.c;
}

int n,m,t;
int main()
{
    //IOS
    cin>>t;
    while(t--)
    {
        nd ar[3];
        REP(i,3)
            cin>>ar[i].a>>ar[i].b>>ar[i].c;

        sort(ar,ar+3,comp);
        if(ar[1].b>ar[2].b || ar[0].b>ar[1].b)
        {
            cout<<"no"<<endl;
            continue;
        }
        if(ar[1].c>ar[2].c || ar[0].c>ar[1].c)
        {
            cout<<"no"<<endl;
            continue;
        }
        if((ar[0].a==ar[1].a && ar[0].b==ar[1].b && ar[0].c==ar[1].c) || (ar[2].a==ar[1].a && ar[2].b==ar[1].b && ar[2].c==ar[1].c))
        {
            cout<<"no"<<endl;
            continue;
        }
        cout<<"yes"<<endl;
    }
}