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
ll n,a[1000000];
map<ll,ll> mt,x;
int main()
{
    IOS

    map<ll,ll> mx;

    cin>>n;
    REP(i,n)
    {
        cin>>a[i];
    }
    ll ans=1;
    REP(i,n)
    {
        mt[a[i]]++;
        x[mt[a[i]]]++;
        if(mt[a[i]]>1)
        {
            x[mt[a[i]]-1]--;
            if(x[mt[a[i]]-1]==0)  x.erase(mt[a[i]]-1);
        }
        if( (sz(x)==1 && x.find(1)!=x.end()))
        {
            ans=i+1;
        }
        if(sz(x)==2)
        {
            map<ll,ll>::iterator it;
            ll ar[2][2];
            ll ind=0;
            for(it=x.begin();it!=x.end();it++,ind++)
            {
                ar[ind][0]=it->ff; 
                ar[ind][1]=it->ss;  
            }
            if(abs(ar[0][0]-ar[1][0])==1 && (ar[0][1]==1 || ar[1][1]==1))
            {
                ans=i+1;
            }
            if(x.find(1)!=x.end() && x[1]==1)
            {
                ans=i+1;
            }
        }
    }
    map<ll,ll>::iterator it;
    cout<<ans<<endl;
}