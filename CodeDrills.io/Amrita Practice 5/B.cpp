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

ll t,n,m,k,q;
pll pt[100005];
vpll dist;
ll pref[100005];
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        dist.clear();
        REP(i,k)    dist.pb({-1,-1}), cin>>dist[i].ss, cin>>pt[i].ff>>pt[i].ss, dist[i].ff = n+m-pt[i].ff-pt[i].ss;
        sort(all(dist));
        pref[0] = dist[0].ss;
        REP(i,k-1)  pref[i+1] = max(pref[i], dist[i+1].ss);
        cin>>q;
        // REP(i,k)
        // {
        //     cout<<dist[i].ff<<" "<<dist[i].ss<<endl;
        // }
        while(q--)
        {
            ll tm;
            cin>>tm;
            ll ind = upper_bound(all(dist), mp(tm+1, -1ll))-dist.begin()-1;
            cout<<(ind+1)*pref[ind]<<endl;
        }
    }
}