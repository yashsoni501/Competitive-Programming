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
ll t,n;
ll ar[200000];
ll xo[200000];
map<ll,vector<ll> > ma;
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        ma.clear();
        cin>>n;
        REP(i,n)    cin>>ar[i];
        xo[0]=0;
        REP(i,n)
        {
            //cin>>xo[i+1];
            xo[i+1]=ar[i]^xo[i];
        }
        REP(i,n+1)
        {
            //cout<<xo[i]<<" ";
            ma[xo[i]].pb(i);
        }
        //cout<<endl;
        ll ans=0;
        for(map<ll,vector<ll> >::iterator it=ma.begin();it!=ma.end();it++)
        {
            //trace(sz(it->ss));
            vector<ll> tmp;
            REP(i,sz(it->ss)-1)
            {
                tmp.pb((it->ss)[i+1]-(it->ss)[i]);
            }
            ll len = sz(tmp);
            REP(i,len)
            {
                ans+=tmp[i]*(i+1)*(len-i);
            }
            //trace(ans);
            ans-=(len*(len+1))/2;
        }
        cout<<ans<<endl;
    }
}
