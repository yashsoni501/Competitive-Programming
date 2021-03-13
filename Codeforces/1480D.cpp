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

ll n,ar[200000];
int main()
{
    IOS
    cin>>n;
    REP(i,n)    cin>>ar[i];
    ar[n] = -1;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    queue<pll> qu;
    ll ind=0;
    while(ind < n)
    {
        qu.push({ar[ind],ind});
        ind++;
        while(ar[ind] == ar[ind-1])
        {
            ind++;
        }
    }
    vector<ll> st1,st2;
    st1.pb(ar[0]);
    st2.pb(ar[1]);
    ll nxt = qu.front().ff;
    for(int i=2;i<n;i++)
    {
        if(qu.front().ss >= i)
        {
            qu.pop();
            nxt = qu.front().ff;
        }
        if(ar[i]!= nxt)
        {
            if(st1[sz(st1)-1] == nxt)
            {
                st1.pb(ar[i]);
            }
            else
            {
                st2.pb(ar[i]);
            }
        }
        else
        {
            if(st1[sz(st1)-1] != ar[i])
            {
                st1.pb(ar[i]);
            }
            else
            {
                st2.pb(ar[i]);
            }
            
        }
        
    }
    ind=0;
    ll ans=0;
    st1.pb(-1);
    st2.pb(-1);
    while(ind < sz(st1)-1)
    {
        ans++;
        ind++;
        while(st1[ind] == st1[ind-1])
        {
            ind++;
        }
    }
    ind=0;
    while(ind < sz(st2)-1)
    {
        ans++;
        ind++;
        while(st2[ind] == st2[ind-1])
        {
            ind++;
        }
    }
    cout<<ans<<endl;
}