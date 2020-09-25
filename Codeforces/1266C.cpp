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

bool sieve[3500000]={};
vl prime;
ll grid[500][500];
ll r,c;

int main()
{
    IOS
    for(int i=2;i<3500000;i++)
    {
        if(sieve[i]==0)
        {
            for(int j=2*i;j<3500000;j+=i)
            {
                sieve[j]=1;
            }
        }
    }
    for(int i=2;i<3500000;i++)
    {
        if(sieve[i]==0)
        {
            prime.pb(i);
        }
    }
    // cout<<sz(prime)<<endl;
    cin>>r>>c;
    if(r==1 && c==1)
    {
        cout<<0<<endl;
        return 0;
    }

    int R = min(r,c);
    int C = max(r,c);
    REP(i,R)
    {
        REP(j,C)
        {
            grid[i][j] = 1;
            
        }
    }
    // REP(i,R)
    // {
    //     REP(j,C)
    //     {
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    ll ind=1;
    for(int i=R-1;i>=0;i--)
    {
        REP(j,C)
        {
            grid[i][j]*=ind;
        }
        ind++;
    }
    for(int i=C-1;i>=0;i--)
    {
        REP(j,R)
        {
            grid[j][i]*=ind;
        }
        ind++;
    }
    if(r==R)
    {
        REP(i,R)
        {
            REP(j,C)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        REP(i,C)
        {
            REP(j,R)
            {
                cout<<grid[j][i]<<" ";
            }
            cout<<endl;
        }
    }
    
    
}