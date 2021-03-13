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
ll arr[300000];
int main()
{
    IOS
    ll t,n;
    cin>>t;
    unordered_set<ll> st;
    vpll vl;
    while(t--)
    {
        vl.clear();
        st.clear();
        cin>>n;
        st.in(2);
        st.in(4);
        st.in(16);
        st.in(256);
        st.in(65536);
        FOR(i,3,n,1)
        {
            if(st.count(i)==0)
            {
                vl.pb({i,n});
            }
        }
        ll ar[] = {2,4,16,256,65536,200001};
        ll ind = lower_bound(ar,ar+6,n)-ar;
        ind--;
        vl.pb({n,ar[ind]});
        vl.pb({n,ar[ind]});
        for(int i=ind;i>0;i--)
        {
            vl.pb({ar[i],ar[i-1]});
            vl.pb({ar[i],ar[i-1]});
        }
        cout<<sz(vl)<<endl;
        for(auto it:vl)
        {
            cout<<it.ff<<" "<<it.ss<<endl;
        }
        // REP(i,n+1)
        // {
        //     arr[i] = i;
        // }
        // for(auto it:vl)
        // {
        //     ll x=it.ff;
        //     ll y=it.ss;
        //     arr[x] = (arr[x]+arr[y]-1)/arr[y];
        // }
        // FOR(i,1,n+1,1)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
    }
}