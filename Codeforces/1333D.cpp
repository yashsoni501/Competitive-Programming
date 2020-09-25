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

ll n,k;
vector<ll> vt[4000000];
vector<pll> vr,tvr;
char s[5000];
ll ind[5000];
int main()
{
    IOS
    cin>>n>>k;
    // cin>>s;
    ll cnt=0;
    REP(i,n)
    {
        cin>>s[i];
        if(s[i]=='R')
        {
            cnt++;
        }
    }
    cnt=n-1;
    ll maxk=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='R')
        {
            ind[i] = cnt--;
            maxk+=cnt+1-i;
            vr.pb({i,cnt+1});
        }
    }

    reverse(all(vr));
    if(k>maxk)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll steps = 0;
    cnt=0;
    ll kl=k;
    ll tmaxk = maxk;

    REP(i,sz(vr))
    {
        tvr.pb(vr[i]);
    }
    while(tmaxk)
    {
        steps++;
        for(int i=0;i<sz(vr)-1;i++)
        {
            if(tvr[i].ff<tvr[i].ss && tvr[i].ff!=tvr[i+1].ff-1)
            {
                tmaxk--;    
                tvr[i].ff++;
            }

        }
        ll ind = sz(vr)-1;

        if(tvr[ind].ff<tvr[ind].ss)
        {
            tmaxk--;
            tvr[ind].ff++;
        }
    }
    while(maxk)
    {
        // trace(maxk)
        for(int i=0;i<sz(vr)-1;i++)
        {
            if(vr[i].ff<vr[i].ss && vr[i].ff!=vr[i+1].ff-1)
            {
                if(maxk>kl)
                {
                    vt[cnt].pb(vr[i].ff);
                    // cnt++;
                    maxk--; 
                }
                else
                {
                    vt[cnt].pb(vr[i].ff);
                    cnt++;
                    maxk--;
                    kl--;
                }
                vr[i].ff++;
            }
        }
        ll ind = sz(vr)-1;
        if(vr[ind].ff<vr[ind].ss)
        {
            if(maxk+steps>kl)
            {
                vt[cnt].pb(vr[ind].ff);
                // cnt++;
                maxk--; 
            }
            else
            {
                vt[cnt].pb(vr[ind].ff);
                cnt++;
                maxk--;
                kl--;
                steps--;
            }
            vr[ind].ff++;
        }

        if(sz(vt[cnt]))
        {
            cnt++;
            kl--;
            steps--;
        }
    }
    // trace(cnt) trace(kl) trace(steps)
    if(cnt!=k)  
    {
        cout<<-1<<endl;
        return 0;
    }

    REP(i,k)
    {
        cout<<sz(vt[i])<<" ";
        sort(all(vt[i]));
        REP(j,sz(vt[i]))
        {
            cout<<vt[i][j]+1<<" ";
        }
        cout<<endl;
    }
}