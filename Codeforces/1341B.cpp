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

ll t,n,k,ar[300000];
ll pref[300000];
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        REP(i,n)
        {
            cin>>ar[i];
        
            pref[i]=0;
        }
        REP(i,n-1)
        {
            if((!i))    continue;
            if(ar[i-1]<ar[i] && ar[i]>ar[i+1])
            {
                pref[i] = pref[i-1]+1;
            }
            else
            {
                pref[i] = pref[i-1];
            }
        }
        pref[n-1] = pref[n-2];
        ll ma=-1,ind=0;
        for(int i=0;i<n-k+1;i++)
        {
            if(pref[i+k-2]-pref[i]>ma)
            {
                ma = pref[i+k-2]-pref[i];
                ind = i+1;
            }
        }
        // REP(i,n)
        // {
        //     cout<<pref[i]<<" ";
        // }
        // cout<<endl;
        cout<<ma+1<<" "<<ind<<endl;
    }
}