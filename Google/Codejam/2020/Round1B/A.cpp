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

ll mod(ll x, ll y)
{
    // cout<<x<<" "<<y<<endl;
    ll m = x%y;
    m = (m+y)%y;
    return m;
}

ll t,n;
ll x,y;
int main()
{
    // IOS
    cin>>t;
    REP(te,t)
    {
        string xs="", ys="";
        cin>>x>>y; 
        ll tmp = x;
        x = y;
        y = tmp;
        ll xt = x;
        ll yt = y;

        bool boo=1;

        ll p = 1,p2 = 2;
        while(xt || yt)
        {
            trace(xt)
            trace(yt)

            if(xt == 0)
            {
                if(yt>0)
                {
                    yt-=p;
                    xs+='E';
                    if(yt<0)
                    {
                        boo=0;
                        break;
                    }
                }
                else
                {
                    yt+=p;
                    xs+='W';
                    if(yt>0)
                    {
                        boo=0;
                        break;
                    }
                }
                
            }
            else if(yt==0)
            {
                if(xt>0)
                {
                    xt-=p;
                    xs+='N';
                    if(xt<0)
                    {
                        boo=0;
                        break;
                    }
                }
                else
                {
                    xt+=p;
                    xs+='S';
                    if(xt>0)
                    {
                        boo=0;
                        break;
                    }
                }
                
            }
            else if(mod(xt,p) == 0 && mod(yt,p2)==0)
            {
                boo=0;
                break;
            }
            if(mod(xt,p2) == p && mod(yt,p2) == p)
            {
                boo=0;
                break;
            }
            if(mod(xt,p2) == p)
            {
                if(mod(yt,2*p2) == 0)
                {
                    if(xt>0)
                    {
                        xt-=p;
                        xs+='N';
                    } 
                    else
                    {
                        xt+=p;
                        xs+='S';
                    }
                }
                else
                {
                    if(mod(xt+p,2*p2)==p2)
                    {
                        xt-=p;
                        xs+='N';
                    }
                    else
                    {
                        xt+=p;
                        xs+='S';
                    }
                }
            }
            else if(mod(yt,p2) == p)
            {
                if(mod(xt,2*p2) == 0)
                {
                    if(yt>0)
                    {
                        yt-=p;
                        xs+='E';
                    } 
                    else
                    {
                        yt+=p;
                        xs+='W';
                    }
                }
                else
                {
                    if(mod(yt+p,2*p2)==p2)
                    {
                        yt-=p;
                        xs+='E';
                    }
                    else
                    {
                        yt+=p;
                        xs+='W';
                    }
                }
            }
            p *= 2;
            p2*= 2;
        }
        trace(xt)
        trace(yt)
        if(!boo)
        {
            cout<<"Case #"<<te+1<<": "<<"IMPOSSIBLE\n";        
        }
        else
        {
            trace(xs)
            cout<<"Case #"<<te+1<<": "<<xs<<endl;
            
        }   
    }
}