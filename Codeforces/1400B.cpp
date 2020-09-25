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

ll t, p,f,cs,cw,s,w;
int main()
{
    IOS
    cin>>t;
    ll cnt;
    while(t--)
    {
        cnt=0;
        cin>>p>>f>>cs>>cw>>s>>w;
        if(s<w)
        {
            ll tmp = s;
            s=w;
            w=tmp;
            tmp=cs;
            cs=cw;
            cw=tmp;
        }
        ll cnt=0;
        for(int i=0;i<cw;i++)
        {
            if(w*i>p)
            {
                break;
            }
            ll xw = i;
            ll xs = min(cs,(p-w*i)/s);
            ll cst = cs-xs;
            ll yw = min(cw-i, f/w);
            ll ys = min((f-w*yw)/s, cst);
            cnt = max(cnt, xs+ys+xw+yw);
        }
        for(int i=0;i<cw;i++)
        {
            if(w*i>f)
            {
                break;
            }
            ll xw = i;
            ll xs = min(cs,(f-w*i)/s);
            ll cst = cs-xs;
            ll yw = min(cw-i, p/w);
            ll ys = min((p-w*yw)/s, cst);
            cnt = max(cnt, xs+ys+xw+yw);
        }
        cout<<cnt<<endl;
    }
}