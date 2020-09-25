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

ll t,n,ar[200000];
ll psum[200000];
vl sq;
map<ll,ll> ma;
int main()
{
    IOS
    for(ll i=0;i<3162;i++)
    {
        sq.pb(i*i);
    }
    // cin>>t;
    t=1;
    REP(te,t)
    {
        ma.clear();
        // cin>>n;
        n = 100000;
        REP(i,n)    ar[i]=100;
        // REP(i,n)    cin>>ar[i];
        psum[0]=0;
        REP(i,n)
        {
            psum[i+1] = psum[i]+ar[i];
        }
        REP(i,n+1)
        {
            if(i==0)    continue;
            ma[psum[i]]++;
        }
        // REP(i,n+1)
        // {
        //     cout<<psum[i]<<" ";
        // }
        // cout<<endl;
        // for(auto it:ma)
        // {
        //     cout<<it.ff<<" "<<it.ss<<endl;
        // }
        // cout<<"\n";
        ll cnt=0;
        // REP(i,n)
        // {
        //     if(binary_search(all(sq),ar[i]))    cnt++;
        // }
        // //trace(cnt)
        REP(i,sz(sq))
        {
            if((ma.rbegin())->ff<sq[i])    break;
            if(ma.find(sq[i])!=ma.end())    
            {
                //trace(sq[i])
                //trace(ma[sq[i]])
                cnt+=ma[sq[i]];
            }
        }
        //trace(cnt)
        //trace(cnt)
        REP(i,n)
        {
            if(!i)  continue;
            ma[psum[i]]--;
            if(ma[psum[i]]==0)
            {
                ma.erase(psum[i]);
            }
            // for(auto it:ma)
            // {
            //     cout<<it.ff<<" "<<it.ss<<endl;
            // }
            // cout<<"\n";     
            for(auto j:sq)
            {
                if(psum[i]+j>(ma.rbegin())->ff)    break;
                if(ma.find(j+psum[i])!=ma.end())    
                {
                    //trace(i)
                    //trace(j+psum[i])
                    //trace(psum[i])
                    cnt+=ma[j+psum[i]];
                }
            }
            //trace(cnt)
            // cout<<"here\n";
        }
        
        cout<<"Case #"<<te+1<<": "<<cnt<<endl;
    }
}