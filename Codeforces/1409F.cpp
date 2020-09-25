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

ll pre[300],pos[300];
ll calc(string r, ll n, string t)
{
    pre[0]=0;
    // trace(r)    trace(t)
    REP(i,n)
    {
        pre[i+1] = pre[i]+(r[i]==t[0]);
    }
    // REP(i,n)    cout<<pre[i]<<" ";
    // cout<<endl;
    ll cnt=0;
    REP(i,n)    
    {
        if(r[i]==t[1])
        {
            cnt+=pre[i];
        }
    }
    return cnt;
}

ll n,k;
string s,t;
int main()
{
    IOS
    // cout<<calc("aabb", 4, "ab")<<endl;
    cin>>n>>k;
    cin>>s>>t;
    REP(i,n)
    {
        if(s[i]!=t[0] && s[i]!=t[1])    s[i] = '_';
    }
    string r=s;
    while(k--)
    {
        r = s;
        ll ma=-1,ina=-1,mb=-1,inb=-1;
        REP(i,n)
        {
            r[i] = t[0];
            ll vat = calc(r,n,t);
            if(vat>ma)
            {
                ma = vat, ina=i;
            }
            r[i] = s[i];
        }
        for(int i=n-1;i>-1;i--)
        {
            r[i] = t[1];
            ll vat=calc(r,n,t);
            if(vat>mb)
            {
                mb=vat;
                inb=i;
            }
            r[i]=s[i];
        }
        if(ma>mb)
        {
            s[ina]=t[0];
        }
        else if(ma<mb)
        {
            s[inb]=t[1];
        }
        else
        {
            if(count(all(s), t[0])>count(all(s), t[1]))
            {
                s[inb]=t[1];
            }
            else
            {
                s[ina]=t[0];
            }
            
        }
        
        // trace(ma)   trace(mb)   trace(ina)  trace(inb)
        // trace(s)
    }
    cout<<calc(s,n,t)<<endl;
}