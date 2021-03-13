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

ll t,n,m;
ll ar[300000];
vl vt1,vt2;
int main()
{
    // IOS
    // srand(0);
    cin>>t;
    while(t--)
    {
        n=rand()%25+1;
        m=10;
        REP(i,n){
            // cin>>ar[i];
            ar[i] = rand()%20-9;
        }
        vt1.clear();
        vt2.clear();

        ll sum = 0;
        REP(i,n)
        {
            sum += ar[i];
            if(sz(vt1)==0 || vt1[sz(vt1)-1] < sum)
            {
                vt1.pb(sum);
                vt2.pb(i);
            }
        }

        ll ma = vt1[sz(vt1)-1];
        vt1.pb(2e9);
        ll x;
        REP(i,m)
        {
            ll ans1;
            // cin>>x;
            x = rand()%50-20;
            if(x <= ma)
            {
                ll it = lower_bound(all(vt1),x)-vt1.begin();
                ans1 = vt2[it];
            }
            else
            {
                if(sum<=0)  
                {
                    ans1 = -1;
                }
                else
                {
                    ll r = (x+sum-1-ma)/sum;
                    ll lft = x-r*sum;
                    if(lft == 0)
                    {
                        ans1 = r*n-1;
                    }
                    else
                    {
                        ll it = lower_bound(all(vt1),lft)-vt1.begin();
                        // trace(r)
                        // trace(it)
                        ans1 = r*n+vt2[it];
                    }
                }
            }
            ll sx = ar[0];
            ll ans2 = 0;
            ll id = 1;
            while(sx < x && id < 5000)
            {
                ans2++;
                sx += ar[id%n];
                id++;
            }
            if(id == 5000)
            {
                ans2 = -1;
            }
            if(ans1 != ans2)
            {
                cout<<"n x "<<n<<" "<<x<<endl;
                REP(i,n)
                {
                    cout<<ar[i]<<" ";
                }
                cout<<endl;
                trace(ans1)
                trace(ans2)
                trace(sum)
            }
        }
        // cout<<endl;
    }
}