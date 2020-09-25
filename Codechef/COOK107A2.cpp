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

ll t,n,M;
struct node
{
    ll d,f,b;
};
ll m[200000];
node c[200000];
bool comp(node a,node c)
{
    if(a.f!=c.f)
        return a.f>c.f;
    return a.b<c.b;
}
ll sel[200000];
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        ll prof=0;
        cin>>n>>M;
        
        REP(i,M)    cin>>m[i+1];
        REP(i,n)
        {
            sel[i]=0;
            cin>>c[i].d>>c[i].f>>c[i].b;
        }
        //sort(c,c+n,comp);
        REP(i,n)
        {
            if(m[c[i].d]>0)   
            {
                m[c[i].d]--;
                prof+=c[i].f;
                sel[i]=c[i].d;
            }
            else
            {
                prof+=c[i].b;
            }
        }
        int ind=1;
        REP(i,n)
        {
            while(m[ind]==0)    ind++;
            if(sel[i]==0)
            {
                sel[i]=ind;
                m[ind]--;
            }
        }

        cout<<prof<<endl;
        REP(i,n)
            cout<<sel[i]<<" ";
        cout<<endl;
    }
}
