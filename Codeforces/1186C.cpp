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

string a,b;

bool xoro(char a,char b)
{
    return a!=b;
}

ll match(string x,string y)
{
    ll cnt=0;
    REP(i,(ll)x.length())
    {
        if(x[i]!=y[i])  cnt++;
    }
    return cnt;
}
deque<ll> qu;
int main()
{
    IOS
    cin>>a>>b;
    ll ini=match(a.substr(0,b.size()),b);
    //cout<<ini<<endl;
    ll cnt=0;
    if(ini%2==0)    cnt++;
    ll difcnt=0;
    bool prv_fnd=0;
    if(ini%2==0)    prv_fnd=1;
    qu.pb(0);
    REP(i,(ll)b.size()-1)
    {
        ll tmp=xoro(a[i],a[i+1]);
        qu.pb(tmp);
        difcnt+=tmp;
    }
    for(int i=1;i<(ll)(a.size()-b.size()+1);i++)
    {
        ll tmp=qu.front();
        qu.pop_front();
        difcnt-=tmp;
        tmp=xoro(a[i+b.size()-1],a[i+b.size()-2]);
        difcnt+=tmp;
        qu.pb(tmp);
        if((prv_fnd==1 && difcnt%2==0) || (prv_fnd==0 && difcnt%2==1))   cnt++,prv_fnd=1;
        else
        {
            prv_fnd=0;
        }
        
    }   
    cout<<cnt<<endl;
}