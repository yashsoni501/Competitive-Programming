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

ll t = 1;
int main()
{
    IOS
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string c,a;
        cin>>c>>a;
        ll ar[n];
        vl cnt[4];
        REP(i,n)
        {
            ar[i] = 2*(c[i]-'0') + (a[i]-'0');
            cnt[ar[i]].pb(i);
        }
        ll w = sz(cnt[0]), x=sz(cnt[1]),y = sz(cnt[2]),z=sz(cnt[3]);

        ll wl,xl,yl,zl;
        zl = z/2;

        yl = min(x,y);
        xl = x-yl;
        if(z%2)
        {
            if(y>x)
            {
                yl++;
            }
            else if(x > y)
            {
                xl--;
                zl++;
            }
            else
            {
                if(x>0)
                {
                    yl--;
                    zl++;
                }
            }          
        }
        while(xl+yl+zl>n/2)
        {
            if(xl>0 && zl<z)
            {
                xl--;
                zl++;
            }
            else
            {
                break;
            }
        }
        while(x-xl+y-yl+z-zl>n/2)
        {
            if(yl<y && zl<z)
            {
                yl++;
                zl--;
            }
            else
            {
                break;
            }
        }
        wl = n/2-xl-yl-zl;
        if(wl<0 || xl<0 || yl<0 || zl<0 || wl>w || xl>x || yl>y || zl>z)
        {
            cout<<-1<<endl;
        }
        else
        {
            REP(i,wl)
            {
                cout<<cnt[0][i]+1<<" ";
            }
            REP(i,xl)
            {
                cout<<cnt[1][i]+1<<" ";
            }
            REP(i,yl)
            {
                cout<<cnt[2][i]+1<<" ";
            }
            REP(i,zl)
            {
                cout<<cnt[3][i]+1<<" ";
            }
            cout<<endl;
        }
        
        // ll p=-1;
        // FOR(ti,(z+1)/2,(x+y+z)/2+1,1)
        // {
        //     if(2*ti+x+y-n >=0)
        //     {
        //         p=ti;
        //     }
        // }
        // if(p == -1)
        // {
        //     cout<<-1<<endl;
        //     return 0;
        // }
        
        // if(x+y<p)
        // {
        //     cout<<-1<<endl;
        //     return 0;
        // }

        // ll l2, r1;
        // l2 = 0, r1 = min(x,p);
        // if(x<p)
        // {
        //     l2 = p-x;
        // }
        // vl l,r;
        // REP(i,l2)
        // {
        //     l.pb(cnt[2][i]);
        // }
        // REP(i,p-l2)
        // {
        //     l.pb(cnt[3][i]);
        // }
        // REP(i,x-r1)
        // {
        //     l.pb(cnt[1][i]);
        // }
        // ll s = sz(l);
        // REP(i,n/2-s)
        // {
        //     l.pb(cnt[0][i]);
        // }
        // REP(i,n/2)
        // {
        //     cout<<l[i]+1<<" ";
        // }
        // cout<<endl;
    }
}