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
// #define endl "\n"
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

ll t=1;
ll n, ar[20000];
bool vis[20000];
int main()
{
    cin>>n;
    ll tmp1,tmp2;
    ll p1=1,p2=2;
    FOR(i,1,n,1)
    {
        cout<<"? "<<p1<<" "<<p2<<endl;
        cin>>tmp1;
        cout<<"? "<<p2<<" "<<p1<<endl;
        cin>>tmp2;

        if(tmp1<tmp2)
        {
            ar[p2]=tmp2;
            if(p1>p2)
            {
                p2=p1+1;
            }
            else
            {
                p2++;
            }
        }
        else
        {
            ar[p1]=tmp1;
            if(p2>p1)
            {
                p1=p2+1;
            }
            else
            {
                p1++;
            }
        }
    }
    REP(i,n)
    {
        vis[ar[i+1]]=1;
    }
    ll mis=0;
    REP(i,n)
    {
        if(!vis[i+1])
        {
            mis=i+1;
            break;
        }
    }
    REP(i,n)    if(ar[i+1]==0)  {
        ar[i+1]=mis;
        break;
    }
    cout<<"! ";
    REP(i,n)    cout<<ar[i+1]<<" ";
    cout<<endl;
}