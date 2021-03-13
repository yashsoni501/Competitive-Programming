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
ll dist(ll i, ll j, ll n)
{
    return min((i-j+n)%n, (j-i+n)%n);
}

ll t,w,n;
ll ar[300010];
ll pre[300010];
int main()
{
    IOS
    cin>>t;
    REP(te,t)
    {
        cin>>w>>n;
        REP(i,w)
        {
            cin>>ar[w+i];
            ar[w+i]--;
        }
        sort(ar+w, ar+2*w);
        REP(i,w)
        {
            ar[i] = ar[w+i]-n;
            ar[2*w+i] = ar[w+i]+n;
        }
        pre[0]=0;
        REP(i,3*w)
        {
            pre[i+1] = pre[i]+ar[i];
        }
        ll ma=1e15;
        // REP(i,3*w)
        // {
        //     cout<<ar[i]<<" ";
        // }
        // cout<<endl;
        FOR(i,w,2*w,1)
        {
            ll tar=ar[i];
            // trace(tar)
            ll sum = 0;
            ll lb = ar+i-lower_bound(ar, ar+2*w, tar-n/2);
            // trace(lb)
            sum += lb*tar-(pre[i]-pre[i-lb]);
            // trace(sum)
            ll ub = upper_bound(ar, ar+3*w, tar+(n-1)/2)-ar-i;
            // trace(ub)
            sum += pre[i+ub]-pre[i] - ub*tar;
            // trace(sum)
            ma = min(ma,sum);
        } 

        cout<<"Case #"<<te+1<<": "<<ma<<endl;
    }
}