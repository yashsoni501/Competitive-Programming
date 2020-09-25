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

ll t=1;
ll n, ar[300000];
ll pref[300000], ecnt[300000],ocnt[300000];
map<ll, vl> ind;

ll par(ll a)
{
    return (a%2+2)%2;
}
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        // cout<<(-1)%2<<endl;
        ind.clear();
        REP(i,n)    cin>>ar[i];
        ll ma=0;
        pref[0]=0;
        ecnt[0]=0;
        ocnt[0]=0;
        REP(i,n)
        {
            pref[i+1]=pref[i]+ar[i];
            ecnt[i+1] = ecnt[i]+((par(ar[i])==0)?1:0);
            ocnt[i+1] = ocnt[i]+((par(ar[i])==1)?1:0);
        }   
        REP(i,n)
        {
            ind[ar[i]].pb(i);
        }
        // REP(i,n+1)  cout<<ocnt[i]<<" ";
        // cout<<endl;
        // REP(i,n+1)  cout<<ecnt[i]<<" ";
        // cout<<endl;
        for(auto it:ind)
        {
            ll tp = par(it.ff);
            // cout<<it.ff<<endl;
            // prv(it.ss)
            REP(i,sz(it.ss)-1)
            {
                ll x=it.ss[i+1];
                ll y=it.ss[i];
                if(tp==0)
                {
                    if(par(ecnt[x]-ecnt[y+1])==tp)
                    {
                        ma = max(ma, pref[x]-pref[y+1]);
                    }
                }
                else
                {
                    if(par(ocnt[x]-ocnt[y+1])==tp)
                    {
                        ma = max(ma, pref[x]-pref[y+1]);
                    }
                }
                // trace(ma)
            }
        }
        cout<<ma<<endl;
    }
}