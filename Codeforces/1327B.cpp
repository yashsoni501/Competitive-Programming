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

ll t,n,k,tmp;
vl ar[200000],b[200000];
bool st[200000];

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool boo=0;
        pll ans;
        REP(i,n)
        {
            st[i]=0;
            ar[i].clear();
            b[i].clear();
        }
        REP(i,n)
        {
            cin>>k;
            REP(j,k)
            {
                cin>>tmp;
                ar[i].pb(tmp-1);
            }
            sort(all(ar[i]));
        }
        REP(i,n)
        {
            REP(j,sz(ar[i]))
            {
                if(sz(b[ar[i][j]])==0)
                {
                    b[ar[i][j]].pb(i);
                    st[i]=1;
                    break;
                }
            }
        }
        REP(i,n)
        {
            if(boo) break;
            if(sz(b[i])==0)
            {
                REP(j,n)
                {
                    if(st[j]==0)
                    {
                        boo=1;
                        ans={j+1, i+1};
                        break;
                    }
                }
            }
        }
        if(boo)
        {
            cout<<"IMPROVE\n"<<ans.ff<<" "<<ans.ss<<endl;
        }
        else
        {
            cout<<"OPTIMAL\n";
        }
        
    }   
}