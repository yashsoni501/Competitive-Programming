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

ll n, sx,sy;
ll ar[4]={};
ll x,y;
int main()
{
    IOS
    cin>>n>>sx>>sy;
    REP(i,n)
    {
        cin>>x>>y;
        if(x>sx && y>sy)
        {
            ar[0]++;
            ar[3]++;
        }
        else if(x>sx && y<sy)
        {
            ar[2]++;
            ar[3]++;
        }
        else if(x<sx && y>sy)
        {
            ar[0]++;
            ar[1]++;
        }
        else if(x<sx && y<sy)
        {
            ar[1]++;
            ar[2]++;
        }
        else
        {
            if(x==sx)
            {
                if(y>sy)
                {
                    ar[0]++;
                }
                else
                {
                    ar[2]++;
                }
                

            }
            else
            {
                if(x>sx)
                {
                    ar[3]++;
                }
                else
                {
                    ar[1]++;
                }
            }
        }
    }    
    ll ma = max(max(ar[0],ar[1]),max(ar[2],ar[3]));
    cout<<ma<<endl;
    if(ma==ar[0])
    {
        cout<<sx<<" "<<sy+1<<endl;
    }
    else if(ma==ar[1])
    {
        cout<<sx-1<<" "<<sy<<endl;
    }
    else if(ma==ar[2])
    {
        cout<<sx<<" "<<sy-1<<endl;
    }
    else
    {
        cout<<sx+1<<" "<<sy<<endl;
    }
    
}