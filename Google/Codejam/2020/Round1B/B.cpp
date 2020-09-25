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
#define MOD 1000000000
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

ll t,n;
ll a,b;
bool fnd;
string s;
bool pd1(ll l, ll h)
{
    cout<<l<<" "<<h;
    cin>>s;
    if(s=="HIT")
    {
        return 1;
    }
    else if(s=="CENTER")
    {
        fnd=1;
        return 1;
    }
    else
    {
        return 0;
    }
    
}
bool pd2(ll l, ll h)
{
    cout<<l<<" "<<h;
    cin>>s;
    if(s=="HIT")
    {
        return 1;
    }
    else if(s=="CENTER")
    {
        fnd=1;
        return 1;
    }
    else
    {
        return 0;
    }
    
}
ll bsl(ll a, ll b)
{
    ll low = -MOD;
    ll high = a;
    ll mid = (low+high)/2;
    while(low<high)
    {
        if(fnd) return 0;
        if(pd1(mid,b))
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
        mid = (high+low)/2;
    }
    return low;
}

ll bsr(ll a, ll b)
{
    ll low = a;
    ll high = MOD;
    ll mid = (low+high+1)/2;
    while(low<high)
    {
        if(fnd) return 0;
        if(pd1(mid,b))
        {
            low = mid;
        }
        else
        {
            high = mid-1;
        }
        mid = (high+low+1)/2;
    }
    return low;
}

ll bsb(ll a, ll b)
{
    ll low = -MOD;
    ll high = b;
    ll mid = (low+high)/2;
    while(low<high)
    {
        if(fnd) return 0;
        if(pd1(a,mid))
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
        mid = (high+low)/2;
    }
    return low;
}

ll bst(ll a, ll b)
{
    ll low = b;
    ll high = MOD;
    ll mid = (low+high+1)/2;
    while(low<high)
    {
        if(fnd) return 0;
        if(pd1(b,mid))
        {
            low = mid;
        }
        else
        {
            high = mid-1;
        }
        mid = (high+low+1)/2;
    }
    return low;
}

int main()
{
    cin>>t>>a>>b;
    string s;
    REP(te,t)
    {
        pll pt;
        fnd = 0;
        for(ll i=-1;i<2;i++)
        {
            for(ll j=-1;j<2;j++)
            {
                cout<<i*(MOD/2)<<' '<<j*MOD/2<<endl;
                cin>>s;
                if(s=="MISS")
                {
                    continue;
                }
                else if(s=="CENTER")
                {
                    fnd=1;
                    break;
                }
                else
                {
                    pt = {i*MOD/2,j*MOD/2};
                }
            }
            if(fnd) break;
        }       
        if(fnd) continue;

        ll l,r,b,t;
        if(!fnd)
             l = bsl(pt.ff,pt.ss);
        if(!fnd)
         r = bsr(pt.ff,pt.ss);
        if(!fnd)
         t = bst(pt.ff,pt.ss);
        if(!fnd)
             b = bsb(pt.ff,pt.ss);
        if(!fnd)
        {
            cout<<(l+r)/2<<" "<<(t+b)/2;
            cin>>s;
            if(s=="CENTER")
            {
                continue;
            }
            cout<<(l+r+1)/2<<" "<<(t+b)/2;
            cin>>s;
            if(s=="CENTER")
            {
                continue;
            }
            cout<<(l+r)/2<<" "<<(t+b+1)/2;
            cin>>s;
            if(s=="CENTER")
            {
                continue;
            }
            cout<<(l+r+1)/2<<" "<<(t+b+1)/2;
            cin>>s;
            if(s=="CENTER")
            {
                continue;
            }
        }
    }
}