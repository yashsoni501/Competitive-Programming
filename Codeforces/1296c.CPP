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

void updatepos(pll &p, char c)
{
    if(c=='L')
    {
        p.ff--;
    }
    else if(c=='R')
    {
        p.ff++;
    }
    else if(c=='U')
    {
        p.ss++;
    }
    else
    {
        p.ss--;
    }
    
}

int main()
{
    IOS
    ll t,n;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        map<pll, ll> mapp;
        pll a = {0,0};
        pll ind={-1,-1};
        ll ma=1e9;

        mapp[{0,0}]=-1;
        REP(i,sz(s))
        {
            updatepos(a,s[i]);
            // cout<<a.ff<<" "<<a.ss<<endl;
            if(mapp.find(a)!=mapp.end())
            {
                if(i-(mapp.find(a)->ss)<ma)
                {
                    ma = i-mapp.find(a)->ss;
                    ind = {mapp.find(a)->ss+2,i+1};
                }
            }else
            {
                mapp[a]=i;
            }
        }
        if(ind!=mp((ll)-1,(ll)-1))
        {
            cout<<ind.ff<<" "<<ind.ss<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        
    }   
}