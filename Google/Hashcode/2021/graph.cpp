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

struct streets
{
    ll b,e,l;
    string name;
};

struct path
{
    ll p;
    vector<string> str;
};

ll dd,ii,ss,vv,ff;
streets street[100003];
path car[1003];
map<ll,vector<string> > inp;
map<ll,vector<string> > otp;
map<ll,ll> deg;
int main()
{
    // IOS
    srand(time(0));
    cin>>dd>>ii>>ss>>vv>>ff;
    REP(i,ss)
    {
        cin>>street[i].b>>street[i].e;
        cin>>street[i].name>>street[i].l;
        otp[street[i].b].pb(street[i].name);
        inp[street[i].e].pb(street[i].name);
        deg[street[i].e]++;
        deg[street[i].b]++;
        if(street[i].b == 499)
        {
            cout<<street[i].e<<endl;
        }
    }
    ll cnt=0;
    vector<string> vt;
    REP(i,vv)
    {
        cin>>car[i].p;
        car[i].str.resize(car[i].p);
        REP(j,car[i].p)
        {
            cin>>car[i].str[j];
        }
        if(car[i].str[0].substr(0,3) == "ejj")
        {
            cnt++;
            vt.pb(car[i].str[0]);
        }
    }
    trace(cnt)
    sort(all(vt));
    for(auto it:vt)
    {
        cout<<it<<endl;
    }
    // REP(i,500)
    // {
    //     cout<<i<<" "<<deg[i]<<endl;
    // }
}