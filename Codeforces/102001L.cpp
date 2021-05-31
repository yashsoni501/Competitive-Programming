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

ll k;
string s;
vector<char> vc;

ll binary(vector<char> vc)
{
    ll ans = 0;
    REP(i,sz(vc))   
    {
        ans = 2*ans+vc[i]-'0';
    }
    return ans;
}

int main()
{
    IOS
    cin>>k>>s;
    bool boo=1;
    REP(i,sz(s))
    {
        if(boo && s[i]=='0') continue;
        boo=0;
        vc.pb(s[i]);
    }
    ll k2=k;
    ll cnt2=0,cnt=0;
    while(k2)
    {
        cnt++;
        cnt2++;
        k2/=2;
    }
    cnt = sz(vc)-cnt;
    REP(i,sz(vc))
    {
        if(cnt==0)  break;
        if(vc[i]=='1')
        {
            vc.erase(vc.begin()+i);
            i--;
            cnt--;
        }
    }
    if(binary(vc)<=k)   cout<<sz(s)-cnt2<<endl;
    else cout<<sz(s)-cnt2+1<<endl;
}