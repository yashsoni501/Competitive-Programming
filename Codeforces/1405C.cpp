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

ll t=1,n,k;
string s;
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        bool boo=1;
        cin>>n>>k;
        cin>>s;
        ll c1=0,c0=0;

        REP(i,k)
        {
            ll j=i;
            c1=0,c0=0;
            while(j<n)
            {
                if(s[j]=='0')   c0++;
                if(s[j]=='1')   c1++;
                j+=k;
            }
            if(c1&&c0)  boo=0;
            j=i;
            while(j<n)
            {
                if(c1)  s[j]='1';
                else if(c0)    s[j]='0'; 
                j+=k;          
            }
        }
        c0=c1=0;
        REP(i,k)
        {
            if(s[i]=='0')   c0++;
            if(s[i]=='1')   c1++;
        }
        if(c0>k/2 || c1>k/2)    boo=0;
        cout<<(boo?"YES":"NO")<<endl;
    }
}   