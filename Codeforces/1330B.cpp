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

ll t,ar[400000],n;   
bool c[400000];
bool checkp(ll *ar, int len)
{
    // set<ll> st;
    REP(i,len)
    {
        c[i+1]=0;
    }
    REP(i,len)
    {
        c[ar[i]]=1;
    }

    REP(i,len)
    {
        if(!c[i+1]) return 0;
    }
    return 1;
}

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        REP(i,n)    cin>>ar[i];
        ll ma = -1;
        REP(i,n)    ma = max(ma,ar[i]);
        ll p1 = ma;
        ll p2 = n-ma;
        
        bool b1=0,b2=0;
        int cnt=0;
        
        if(checkp(ar,p1)&&checkp(ar+p1,p2))
        {
            b1=1;
            cnt++;
        }
        if(checkp(ar,p2)&&checkp(ar+p2,p1))
        {
            b2=1;
            cnt++;
        }
        if(cnt==2 && p1==p2)
        {
            cout<<1<<endl;
            cout<<p1<<" "<<p2<<endl;
            continue;
        }
        cout<<cnt<<endl;
        if(b1)  cout<<p1<<" "<<p2<<endl;
        if(b2)  cout<<p2<<" "<<p1<<endl;
        
    }
}