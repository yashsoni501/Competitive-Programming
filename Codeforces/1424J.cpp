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

ll sieve[1500000];
ll prime[1500000];
void sieveof(ll n)
{
    for(int i=2;i<n;i++)
    {
        if(!prime[i])
        {
            FOR(j,2*i,n,i)
            {
                if(sieve[j]==0)
                {
                    sieve[j]=i;
                }
                prime[j] = 1;
            }
        }
    }
}
ll n, ar[1500000];
ll ms[1500000];
int main()
{
    IOS
    sieveof(100);
   
    ar[0]=0;
    ar[1]=1;
    int sq=2;
    FOR(i,2,1000005,1)
    {
        ar[i] = ar[i-1];
        if(!prime[i])
        {
            ar[i]++;
        }
        if(sq*sq==i)
        {
            sq++;
            ar[i]--;
        }
    }
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<ar[n]<<endl;
    }
    // REP(i,11)
    // {
    //     cout<<ar[i]<<endl;
    // }
}