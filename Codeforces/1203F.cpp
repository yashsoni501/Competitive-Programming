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

ll n,r;
vector<pll> ne;
map<ll,ll> po;
int main()
{
    IOS
    cin>>n>>r;
    REP(i,n)
    {
        ll x,y;
        cin>>x>>y;
        if(y>=0)
        {   
            po.in(mp(x,y));
        }
        else
        {
            ne.pb(mp(x,y));
        }
    }
    bool p=1;
    for(map<ll,ll>::iterator it=po.begin();it!=po.end();it++)
    {
        if(r>=it->ff)
        {
            r+=it->ss;
        }
        else
        {
            p=0;
            break;
        }
    }

    while(sz(ne))
    {
        if(r<0)
        {
            p=0;
            break;
        }
        ll maxi=-1;
        vector<pll> vc;
        REP(j,sz(ne))
        {
            maxi=max(maxi,ne[j].ff);
        }
        if(r<maxi)
        {
            p=0;
            break;
        }
        REP(i,sz(ne))
        {
            if(r-ne[i].ss>=maxi)
            {
                vc.pb(ne[i]);
            }
        }
        if(sz(vc)==0)
        {
            ll mi=1e9,inde=-1;
            REP(i,sz(ne))
            {
                if(ne[i].ss<mi)
                {
                    mi=ne[i].ss;
                    inde=i;
                }
            }
            r-=ne[inde].ss;
            ne.erase(ne.begin()+inde);
            continue;
        }
        ll mini=1e9;
        REP(i,sz(vc))
        {
            mini=min(mini,vc[i].ss);
        }
        r-=mini;
        maxi=-1;
        ll ind=-1;
        REP(i,sz(ne))
        {
            if(ne[i].ss==mini && ne[i].ff>maxi)
            {
                ind=i;
                maxi=ne[i].ff;
            }
        }
        ne.erase(ne.begin()+ind);
    }
    if(p &&r>=0)    cout<<"YES"<<endl;
    else
    {
        cout<<"NO"<<endl;
    }
    
}