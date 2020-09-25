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
#define MOD 998244353
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

ll modPower(ll a, ll b) // return a^b % MOD where MOD is defined globally
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b%2 == 0)
    {
        ll tmp = modPower(a,b/2);
        return (tmp*tmp)%MOD;
    }
    else
    {
        ll tmp = modPower(a,(b-1)/2);
        return (((tmp*tmp)%MOD)*a)%MOD;
    }
}

ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}

ll t,m,n;
ll s[200000];
string p;

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        cin>>p;     
        ll su=0;
        REP(i,m+1)
        {
            s[i]=mul(mul(su,modPower(26,n-i)),modPower(26,n-i));
            if(i==m)    continue;
            s[i]=add(s[i],mul(n-i,mul(25*13,modPower(26,n-i-1))));
            su=mul(su,26);
            su=add(su,p[i]-'a');
        }
        REP(i,m)
        {
            s[i]=sub(s[i],s[i+1]);
        }
        REP(i,m+1)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }

}