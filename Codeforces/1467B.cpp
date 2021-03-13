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

ll t,n;
ll ar[400000];
bool mi[400000];
bool ma[400000];
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        REP(i,n)    cin>>ar[i];
        REP(i,n)    ma[i]=0,mi[i]=0;
        ll cnt=0;
        FOR(i,1,n-1,1)
        {
            if(ar[i]>ar[i-1] && ar[i]>ar[i+1])  ma[i]=1,cnt++;
            if(ar[i]<ar[i-1] && ar[i]<ar[i+1])  mi[i]=1,cnt++;
        }
        // FOR(i,1,n-1,1)
        // {
        //     cout<<ma[i]<<" ";
        // }
        // cout<<endl;
        // FOR(i,1,n-1,1)
        // {
        //     cout<<mi[i]<<" ";
        // }
        // cout<<endl;
        if(cnt==0)
        {
            cout<<0<<endl;
            continue;
        }
        cnt--;
        bool boo=0;
        FOR(i,2,n-2,1)
        {
            if((ma[i] && mi[i+1] && mi[i-1]) || (mi[i] && ma[i+1] && ma[i-1]))
            {
                boo=1;
                cnt-=2;
                break;
            }
        }
        // trace(cnt)
        if(boo)
        {
            cout<<cnt<<endl;
            continue;
        }
        FOR(i,1,n-2,1)
        {
            if(ma[i] && mi[i+1])
            {
                if(i==1 || i==n-3)
                {
                    // cout<<"here1\n";
                    cnt--;
                    break;
                }
                if(ar[i-1]<=ar[i-2] || ar[i-1]<=ar[i+1])
                {

                    // cout<<"here2\n";
                    cnt--;
                    break;
                }
                if(ar[i+2]>=ar[i+3] || ar[i+2]>=ar[i])
                {
                    // cout<<"here3\n";

                    cnt--;
                    break;
                }
            }
            if(mi[i] && ma[i+1])
            {
                if(i==1 || i==n-3)
                {
                    cnt--;
                    break;
                }
                if(ar[i-1]>=ar[i-2] || ar[i-1]>=ar[i+1])
                {
                    cnt--;
                    break;
                }
                if(ar[i+2]<=ar[i+3] || ar[i+2]<=ar[i])
                {
                    cnt--;
                    break;
                }
            }
        }
        cout<<cnt<<endl;
    }
}