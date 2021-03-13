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

string conv(ll x)
{
    string p="";
    if(x==0)
    {
        p="0";
        return p;
    }
    while(x)
    {
        p += '0'+x%10;
        x/=10;
    }
    reverse(all(p));
    return p;
}

ll toInt(string a)
{
    ll it = 0;
    REP(i,sz(a))
    {
        it *=10;
        it+= a[i]-'0';
    }
    return it;
}

string proc(string a)
{
    string p = a,q=a;
    sort(all(p));
    sort(all(q), greater<char>());
    return conv(toInt(q)-toInt(p));
}

int main()
{
    IOS
    ll n,k;
    cin>>n>>k;
    string t = conv(n);
    REP(i,k)
    {
        t = proc(t);
    }
    cout<<t<<endl;
}