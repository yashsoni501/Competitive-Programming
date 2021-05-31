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
#define PRT(te,sttt)    cout<<"Case #"<<te+1<<": "<<(sttt)<<endl;
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

ll t;

bool valid(vl vt, ll ar[])
{
    ll a=ar[vt[0]];
    ll b=ar[vt[1]];
    ll c=ar[vt[2]];

    ll ss = a/1000000000;
    ll mm = ss/60;
    ll hh = mm/60;
    ss%=60;
    mm%=60;
    if(b/1000000000/720!=mm) return 0;
    if(c/1000000000/720!=ss)    return 0;
    if(((b-(b/1000000000/720)*720*1000000000)/720000000000 != ss))  return 0;
    if((a-hh*1000000000*3600)/1000000000!=mm)   return 0;
    return 1;
}
int main()
{
    IOS
    cin>>t;
    ll a[3];
    ll h,s,n,m;
    int hh, mm, ss;
    REP(te,t)
    {
        REP(i,3)    cin>>a[i];
        vl vt = {0,1,2};
        vl rt;
        REP(i,6)
        {
            if(valid(vt, a))
            {
                rt = vt;
                break;
            }
            next_permutation(all(vt));
        }
        ss = a[rt[0]]/1000000000;
        hh = ss/3600;
        mm = ss/60;
        ss %=60;
        mm %=60;
        ll ns = a[rt[2]]-ss*1000000000*720;

        cout<<"Case #"<<te+1<<": "<<hh<<" "<<mm<<" "<<ss<<" "<<ns<<endl;
    }
}