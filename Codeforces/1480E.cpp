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

    vector<pll> qu;
    ll ind=0;
    while(ind < n)
    {
        qu.pb({ar[ind],ind});
        ind++;
        while(ar[ind] == ar[ind-1])
        {
            ind++;
        }
    }
    if(sz(qu)==1)
    {
        cout<<2<<endl;
        return 0;
    }
    ll ans;
    if(sz(qu)==2)
    {
        ans=0;
        if(qu[1].ss-qu[0].ss > 1)   ans+=2;
        else
        {
            ans+=1;
        }
        if(n-qu[1].ss > 1)   ans+=2;
        else
        {
            ans+=1;
        }
        cout<<ans<<endl;
        return 0;
    }
    if(qu[1].ss-qu[0].ss > 1)
    {
        ans=2;
    }
    else
    {
        ans=1;
    }
    REP(i,sz(qu)-1)
    {
        if(!i)  continue;
        if(qu[i+1].ss-qu[i].ss > 1 && !(i>2 && qu[i].ss-qu[i-1].ss==1 && qu[i-2].ff == qu[i].ff))
        {
            ans+=2;
        }
        else
        {
            ans+=1;
        }
    }
    if(n-qu[n-1].ss > 1 && !(qu[n-1].ss-qu[n-2].ss==1 && qu[n-3].ff == qu[n-1].ff))
    {
        ans+=2;
    }
    else
    {
        ans++;
    }
    cout<<ans<<endl;
}