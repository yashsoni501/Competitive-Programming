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

int main()
{
    IOS
    ll n;
    ll ar[300];
    cin>>n;
    ll odd=0,eve=0;
    REP(i,n)
    {
        cin>>ar[i];
    }   
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    
    bool b[200]={};
    REP(i,n)
    {
        b[ar[i]]=1;
    }
    REP(i,n)
    {
        if(!b[i+1])
        {
            if(i%2==0)
            {
                odd++;
            }
            else
            {
                eve++;
            }
        }
    }
    vl af;
    ll cnt=0;
    REP(i,n)
    {
        // prv(af)
        if(ar[i]==0)
        {
            cnt++;
        }
        else
        {
            if(cnt!=0)
            {
                af.pb(cnt);
                cnt=0;
            }
            if(ar[i]%2==0)
            {
                af.pb(-1);
            }
            else
            {
                af.pb(0);
            }
        }
    }
    if(cnt!=0)
    {
        af.pb(cnt);
    }
    // prv(af)
    if(sz(af)==1)
    {
        cout<<1<<endl;
        return 0;
    }
    vl arr[4];
    pll ep[2]={{-1,-1},{-1,-1}};
    REP(i,sz(af))
    {
        if(i==0 && af[i]>0)
        {
            // arr[af[i+1]+1].pb(af[i]);
            ep[0]={af[i],af[i+1]+1};
        }
        else if(i==sz(af)-1 && af[i]>0)
        {
            // arr[af[i-1]+1].pb(af[i]);
            ep[1]={af[i],af[i-1]+1};
        }
        else
        {
            if(af[i]>0)
            {
                if(af[i-1]==af[i+1])
                {
                    arr[af[i-1]+1].pb(af[i]);
                }
                else
                {
                    arr[2].pb(af[i]);
                }
                
            }
        }
    }
    ll ans=0;
    REP(i,3)
    {
        // prv(arr[i])
        sort(all(arr[i]));
    }
    REP(i,sz(arr[0]))
    {
        if(eve>=arr[0][i])
        {
            eve-=arr[0][i];
        }
        else
        {

            ans+=2;
            odd-=arr[0][i]-eve;
            eve=0;
            
        }
    }
    REP(i,sz(arr[1]))
    {
        if(odd>=arr[1][i])
        {
            odd-=arr[1][i];
        }
        else
        {
            
            ans+=2;
            eve-=arr[1][i]-odd;
            odd=0;
        
        }
    }
    REP(i,sz(arr[2]))
    {
        ans++;
    }
    sort(ep,ep+2);
    REP(i,2)
    {
        if(ep[i].ff!=-1)
        {
            if(ep[i].ss==0)
            {
                if(eve>=ep[i].ff)
                {
                    eve-=ep[i].ff;
                }
                else
                {
                    ans++;
                }
                
            }
            else
            {
                if(odd>=ep[i].ff)
                {
                    odd-=ep[i].ff;
                }
                else
                {
                    ans++;
                }
                
            }
            
        }
    }
    REP(i,n-1)
    {
        if(ar[i]!=0 && ar[i+1]!=0)
        {
            if(ar[i]%2!=ar[i+1]%2)  ans++;
        }
    }
    cout<<ans<<endl;
}