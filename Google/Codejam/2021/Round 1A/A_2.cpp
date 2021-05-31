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
#define PRT(te,sttt)    cout<<"Case #"<<te+1<<": "<<(sttt)<<endl;
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
ll toInt(string s)
{
    ll t = 0;
    ll j=0;
    while(j<sz(s))
    {
        t = 10*t+(s[j++]-'0');
    }
    return t;
}
string toString(ll a)
{
    if(a==0)    return "0";
    string re = "";
    while(a)
    {
        re += a%10+'0';
        a/=10;
    }
    reverse(all(re));
    return re;
}
ll t;
ll n;
ll ar[1000];
int main()
{
    IOS
    cin>>t;
    REP(te,t)
    {
        cin>>n;
        ll ans = 0;
        REP(i,n)    cin>>ar[i];
        REP(i,n-1)
        {
            int id = 0;
            int pd = 10;
            if(ar[i] > ar[i+1])
            {
                while(ar[i+1]*pd+id<= ar[i])
                {
                    id++;
                    if(id == 10)    pd*=10;
                    if(id == 100)    pd*=10;
                }
                ans++;
                if(id>10)   ans++;
                if(id>100)   ans++;
                ar[i+1] = ar[i+1]*pd+id;
            }
            else if(ar[i]==ar[i+1])
            {
                ar[i+1]*=10;
                ans++;
            }
        }
        PRT(te,ans);
        REP(i,n)    cout<<ar[i]<<" ";
        cout<<endl;
    }
}