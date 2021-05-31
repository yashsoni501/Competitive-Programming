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

ll fac[10000007];
ll ma[10000007];
void sieve()
{
    REP(i,10000002)
    {
        fac[i] = i;
    }
    FOR(i,2,10000002,1)
    {
        // if(fac[i]==i)
        {
            FOR(j,2*i,10000002,i)
            {
                fac[j]+=i;
            }
        }
        fac[i]++;
    }
}

int main()
{
    IOS
    sieve();
    // cout<<"svdone\n";
    // REP(i,9)    cout<<fac[i]<<" ";
    // cout<<endl;
    // unordered_map<ll,ll> ma;
    // cout<<fac[18]<<endl;
    REP(i,10000002)
    {
        if(fac[i] < 10000001 && ma[fac[i]]==0)
        {
            ma[fac[i]]=i;
        }
    }
    // cout<<"madoine\n";
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(ma[n]!=0) cout<<ma[n]<<endl;
        else
        {
            cout<<"-1\n";
        }
    }
}