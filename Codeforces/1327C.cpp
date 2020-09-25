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

ll n,m,k,t1,t2;
pll s[300],f[300];
bool b[300];

int main()
{
    IOS
    cin>>n>>m>>k;
    REP(i,k)
    {
        cin>>t1>>t2;
        s[i] = {t1,t2};
    }
    REP(i,k)
    {
        cin>>t1>>t2;
        f[i] = {t1,t2};
    }
    string s="";
    ll cnt=0;

    // cout<<n+m-2+n*m-1<<endl;
    REP(i,n-1)
    {
        s+='U';
        cnt++;
    }

    REP(i,m-1)
    {
        s+='L';
        cnt++;
    }
    REP(i,n)
    {
        if(i%2==0)
        REP(j,m-1)
        {
            s+='R';
            cnt++;
        }
        else
        {
            REP(j,m-1)
            {
                s+='L';
                cnt++;
            }
        }
        
        if(i!=n-1)
        {
            s+='D';
            cnt++;
        }
    }
    cout<<cnt<<endl;
    cout<<s<<endl;
}