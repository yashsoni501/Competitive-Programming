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

ll t,r,c;
char ar[40][40];
set<pll> based;
map<char,set<pll>> pbas;
map<char,set<pll>> pubs;
set<char> ch;

bool subset(set<pll> base, set<pll> s)
{
    for(auto it:s)
    {
        if(base.find(it)==base.end())   return 0;
    }

    return 1;
}

void rem(set<pll> &base, set<pll> &s)
{
    for(auto it:s)
    {
        base.erase(it);
    }
}

void add(set<pll> &base, set<pll> &s)
{
    for(auto it:s)
    {
        base.in(it);
    }
}

int main()
{
    IOS
    cin>>t;
    REP(te,t)
    {
        pbas.clear();
        pubs.clear();
        ch.clear();
        based.clear();
        cin>>r>>c;
        REP(i,r)
        {
            REP(j,c)
            {
                cin>>ar[i][j];
                ch.in(ar[i][j]);
            }
        }

        REP(i,r-1)
        {
            REP(j,c)
            {
                if(ar[i][j]!=ar[i+1][j])
                {
                    pubs[ar[i][j]].in({i,j});
                }
            }
        }

        FOR(i,1,r,1)
        {
            REP(j,c)
            {
                if(ar[i][j]!=ar[i-1][j])
                {
                    pbas[ar[i][j]].in({i-1,j});
                }
            }
        }

        // for(auto it:ch)
        // {

        // }
        // for(auto it:pubs['O'])
        // {
        //     cout<<it.ff<<" "<<it.ss<<endl;
        // }
        // cout<<"\n";
        string st="";
        bool b;
        while(sz(ch))
        {
            b=0;
            for(auto it:ch)
            {
                if(subset(based,pubs[it]))
                {
                    rem(based, pubs[it]);
                    add(based, pbas[it]);
                    st+=it;
                    b=1;
                    ch.erase(it);
                    break;
                }
            }
            // for(auto it:based)
            // {
            //     cout<<it.ff<<" "<<it.ss<<endl;
            // }
            
            // cout<<"\n";
            if(!b)
            {
                break;
            }
        }
        // trace(st)
        if(sz(ch))
        {
            cout<<"Case #"<<te+1<<": "<<-1<<endl;
        }
        else
        {
            cout<<"Case #"<<te+1<<": "<<st<<endl;        
        }
    }
}