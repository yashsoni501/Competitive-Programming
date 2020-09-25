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
#define PER(i,j) for(int i=j-1;i>=0;i--)
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

ll t,n,m,ar[2000][2000];
ll masum1[2000][2000];
ll masum2[2000][2000];
ll masum3[2000][2000];
ll masum4[2000][2000];
ll prefix[2000];
ll tmp[2000];
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        REP(i,n)    REP(j,m)
        {
            cin>>ar[i][j];
            ar[i][j]*=-1;
        }
        REP(i,n)
        {
            ll sum = 0;
            REP(j,m)
            {
                sum+=ar[i][j];
                tmp[j]=sum;
            }
            ll ma = -1e9;
            PER(j,m)
            {
                ma = max(ma,tmp[j]);
                masum1[i][j] = ma-tmp[j-1];
            }
        }
        REP(i,n)
        {
            ll sum = 0;
            PER(j,m)
            {
                sum+=ar[i][j];
                tmp[j]=sum;
            }
            ll ma = -1e9;
            REP(j,m)
            {
                ma = max(ma,tmp[j]);
                masum2[i][j] = ma-tmp[j+1];
            }
        }

        REP(j,m)
        {
            ll sum = 0;
            REP(i,n)
            {
                sum+=ar[i][j];
                tmp[i]=sum;
            }
            ll ma = -1e9;
            PER(i,n)
            {
                ma = max(ma,tmp[i]);
                masum3[i][j] = ma-tmp[i-1];
            }
        }
        REP(j,m)
        {
            ll sum = 0;
            PER(i,n)
            {
                sum+=ar[i][j];
                tmp[i]=sum;
            }
            ll ma = -1e9;
            REP(i,n)
            {
                ma = max(ma,tmp[i]);
                masum4[i][j] = ma-tmp[i+1];
            }
        }
        ll maxi=-1e9;
        REP(i,n)
        {
            REP(j,m)
            {
                maxi = max(maxi,masum1[i][j]+masum2[i][j]+masum3[i][j]+masum4[i][j]-3*ar[i][j]);
            }
        }
        /*
        REP(i,n)
        {
            REP(j,m)
                cout<<masum1[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        REP(i,n)
        {
            REP(j,m)
                cout<<masum2[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        REP(i,n)
        {
            REP(j,m)
                cout<<masum3[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        REP(i,n)
        {
            REP(j,m)
                cout<<masum4[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;*/
        cout<<-maxi<<endl;

    }
}