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
ll n,s[200000];
ll tmp[200000];
ll t[2][17][200000];
ll q,l,r;
int main()
{
    //IOS
    cin>>n;
    REP(i,n)
    {
        cin>>s[i];
    }
    ll len=n,ind=0;
    REP(i,n)
    {
        tmp[i]=s[i];
    }
    
    while(len>1)
    {
        ll sum=0;
        cout<<ind<<endl;
        REP(i,len/2)
        {
            sum+=(tmp[2*i]+tmp[2*i+1]>=10)?1:0;
            tmp[i]=(tmp[2*i]+tmp[2*i+1])%10;
            t[0][ind][i]=sum;
            cout<<t[0][ind][i]<<" ";
        }
        cout<<endl;
        REP(i,len/2)
            cout<<tmp[i]<<" ";
        cout<<endl;
        ind++;
        len/=2;
    }

    len=n-1,ind=0;
    REP(i,n-1)
    {
        tmp[i]=s[i+1];
    }
    while(len>1)
    {
        ll sum=0;
        cout<<ind<<endl;
        trace(len);
        //ll x=(ind==0)?1:0;
        REP(i,len/2)
        {
            sum+=(tmp[2*i]+tmp[2*i+1]>=10)?1:0;
            tmp[i]=(tmp[2*i]+tmp[2*i+1])%10;
            t[1][ind][i]=sum;
            cout<<t[1][ind][i]<<" ";
        }
        cout<<endl;
        REP(i,len/2)
            cout<<tmp[i]<<" ";
        cout<<endl;
        ind++;
        len/=2;
    }
    cin>>q;
    while(q--)
    {
        ll ans=0;
        cin>>l>>r;
        l--;
        r--;
        ll id=0,tp=(l)%2;
        if(l%2)
        {
            l--;
            r--;
        }
        while(r-l>=1)
        {
            r/=2,l/=2;
            if(l>0)
                ans+=t[tp][id][r]-t[tp][id][l-1];
            else
            {
                ans+=t[tp][id][r];
            }
            
            id++;
        }
        cout<<ans<<endl;
    }
    
}