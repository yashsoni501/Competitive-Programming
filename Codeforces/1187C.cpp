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
ll ar[100000];
int main()
{
    //IOS
    ll n,m;
    cin>>n>>m;
    vector<pll> vc[2];
    REP(i,m)
    {
        ll t,l,r;
        cin>>t>>l>>r;
        vc[t].pb(mp(l,r));
    }
    sort(all(vc[0]));
    sort(all(vc[1]));
	//cout<<"here2"<<endl;
    if(sz(vc[0])==0)
    {
        cout<<"YES"<<endl;
        REP(i,n)    cout<<1<<" ";
        cout<<endl;
        return 0;
    }

    REP(i,n+1)
    {
        ar[i]=-10000;
    }
    //cout<<"here"<<endl;
    ll cnt=2000;
    REP(i,sz(vc[0]))
    {
        if(ar[vc[0][i].ff]!=-10000)
        {
            cnt=ar[vc[0][i].ff];
        }
        for(int j=vc[0][i].ff;j<=vc[0][i].ss;j++)
        {
            ar[j]=cnt--;
        }
    }
    //cout<<"here"<<endl;
    REP(i,n)
    {
        if(ar[i+1]!=-10000)
        {
            REP(j,i)
            {
                ar[j+1]=ar[i+1];
            }
            break;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(ar[i]==-10000)
        {
            ar[i]=ar[i-1];
        }
    }
    bool chk=1;
    REP(i,sz(vc[1]))
    {
        if(!chk)    break;
        for(int j=vc[1][i].ff;j<vc[1][i].ss;j++)
        {
            if(ar[j]>ar[j+1])
            {
                chk=0;
                break;
            }
        }
    }
    if(chk)
    {
        cout<<"YES"<<endl;
        REP(i,n)
        {
            cout<<ar[i+1]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
}
