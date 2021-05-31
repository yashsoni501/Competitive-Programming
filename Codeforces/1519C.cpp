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

ll t,n,u[300000],s[300000];
vl st[200004];
vector<vl> vtt;

bool comp(vl &a, vl &b)
{
    return sz(b)<sz(a);
}

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        vtt.clear();
        REP(i,n)    st[i].clear();
        REP(i,n)    cin>>u[i];
        REP(i,n)    cin>>s[i];
        ll sum=0;
        REP(i,n)
        {
            sum+=s[i];
            st[u[i]].pb(s[i]);
        }
        ll ind=0;
        REP(i,n+1)
        {
            if(sz(st[i]))
            {
                st[i].pb(0);
                sort(all(st[i]));
                vtt.pb(st[i]);
            }
        }
        // trace(ind)
        sort(all(vtt), comp);

        // cout<<"asdf:";
        // prv(vtt[0])
        FOR(i,1,n+1,1)
        {
            ll ans = 0;
            REP(ii,sz(vtt))
            {
                if(sz(vtt[ii])<i)
                {
                    ll x = sz(vtt)-1;
                    while(x>=ii)
                    {
                        sum-=vtt[x][sz(vtt[x])-1];
                        vtt.pop_back();
                        x--;
                    }
                    break;
                }
                ans+=vtt[ii][(sz(vtt[ii])-1)%i];
            }
            cout<<sum-ans<<" ";
        }
        cout<<endl;
    }
}