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

ll T,n;
ll w,h,l,u,r,d;

bool isH(pll p)
{
    if(p.ff>=l && p.ff<=r && p.ss>=u && p.ss<=d) return 1;
    return 0;
}

bool isB(pll p)
{
    if(p.ss==h)    return 1;
    return 0;
}

bool isR(pll p)
{
    if(p.ff==w)    return 1;
    return 0;
}

queue<pll> qu;
map<pll, double> pro;
set<pll> vis;

int main()
{
    IOS
    cin>>T;
    REP(te,T)
    {   
        // qu.clear();
        pro.clear();
        vis.clear();

        cin>>w>>h>>l>>u>>r>>d;
        
        qu.push({1,1});
        pro[{1,1}] = 1;
        if(w==1 || h==1)    
        {
            cout<<"Case #"<<te+1<<": "<<0<<endl;
            continue;
        }
        
        while(!qu.empty())
        {
            pll to = qu.front();
            qu.pop();
            // cout<<to.ff<<" "<<to.ss<<endl;
            if(pro[to]>1e-5 && vis.find(to)==vis.end())
            {
                vis.in(to);
                if(to.ff == w && to.ss == h)
                {
                    continue;
                }
                else if(isB(to))
                {
                    pll t = {to.ff+1,to.ss};
                    if(!isH(t))
                    {
                        pro[t] += pro[to];
                        qu.push(t);
                    }
                }
                else if(isR(to))
                {
                    pll t = {to.ff, to.ss+1};
                    if(!isH(t))
                    {
                        pro[t] += pro[to];
                        qu.push(t);
                    }
                }
                else
                {
                    pll t1 = {to.ff+1,to.ss};
                    pll t2 = {to.ff, to.ss+1};

                    if(!isH(t1))
                    {
                        pro[t1] += pro[to]/2;
                        qu.push(t1);
                    }
                    if(!isH(t2))
                    {
                        pro[t2] += pro[to]/2;
                        qu.push(t2);
                    }
                }
            }
        }

        // REP(i,w)
        // {
        //     REP(j,h)
        //     {
        //         cout<<pro[{i+1,j+1}]<<"\t";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        double ans = 1-pro[{l,u}];
        if(pro.find({w,h})!=pro.end())
        {
            cout<<"Case #"<<te+1<<": "<<pro[{w,h}]<<endl;
            continue;
        }
        for(int i=l;i<=r;i++)
        {
            ans-=pro[{i,u-1}]/2;
        }
        for(int i=u;i<=d;i++)
        {
            ans-=pro[{l-1,i}]/2;
        }
        cout<<"Case #"<<te+1<<": "<<ans<<endl;
    }    
}   