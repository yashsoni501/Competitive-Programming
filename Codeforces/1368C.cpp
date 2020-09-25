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


ll n,k;
set<pll> st;
int main()
{
    IOS
    cin>>n;
    bool boo=0;
    if(n%2)
    {
        n--;
        boo=1;
    }
    REP(i,2*n+1)
    {
        st.in({i,0});
        if(i%2)
        {
            st.in({i,2});
            st.in({i,-2});
            st.in({i,-1});
            st.in({i,1});
        }
        else if(i%4 == 2)
        {
            st.in({i,2});
            st.in({i,-2});
        }
        
    }
    st.in({-1,0});
    st.in({-2,0});
    st.in({2*n+1,0});
    st.in({2*n+2,0});

    st.in({-2,-1});
    st.in({-2,-2});
    st.in({-2,-3});
    st.in({-2,-4});

    st.in({2*n+2,-1});
    st.in({2*n+2,-2});
    st.in({2*n+2,-3});
    st.in({2*n+2,-4});

    for(int i=-1;i<=2*n+1;i++)
    {
        st.in({i,-4});
    }

    if(boo)
    {
        st.in({-2,1});
        st.in({-3,1});
        st.in({-3,0});
    }
    cout<<sz(st)<<endl;
    for(auto it:st)
    {
        cout<<it.ff<<" "<<it.ss<<endl;
    }
}