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

ll n;
ll c[3][200000];
ll ar[200000];
ll colr[200000];
vector<ll> adj[200000];
int main()
{
    IOS
    cin>>n;
    REP(i,n)
    {
        cin>>c[0][i];
    }
    REP(i,n)
    {
        cin>>c[1][i];
    }
    REP(i,n)
    {
        cin>>c[2][i];
    }

    REP(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    REP(i,n)
    {
        if(sz(adj[i+1])>2)
        {
            cout<<-1<<endl;
            return 0;
        }
    }

    ll st = -1,prev=-1;
    for(int i=1;i<=n;i++)
    {
        if(sz(adj[i])==1)
        {
            st = i;
            break;
        }
    }


    ar[0] = st;
    prev = st;
    ll cur = adj[st][0];
    ar[1] = cur;
    ll ind=2;
    while(ind<n)
    {
        if(adj[cur][0]==prev)
        {
            prev = cur;
            cur = adj[cur][1];
        }
        else
        {
            prev = cur;
            cur = adj[cur][0];
        }
        ar[ind++] = cur;
    }

    ll cost = 1e15;
    char s[6][4] = {"123","132","213","231","312","321"};
    REP(i,6)
    {
        ll cst = 0;
        REP(j,n)
        {
            cst += c[s[i][j%3]-'1'][ar[j]-1];
        }
        if(cost>cst)
        {
            cost = cst;
            ind = i;
        }
    }

    cout<<cost<<endl;
    REP(i,n)
    {
        colr[ar[i]-1] = s[ind][i%3]-'0';
    }
    REP(i,n)
    {
        cout<<colr[i]<<" ";
    }
    cout<<endl;
}
