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

ll t,n,c[300000],ar[300000];
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>n;
        REP(i,n)    cin>>ar[i];
        bool bs=1;
        REP(i,n)    if(ar[i] != ar[(i+1)%n])    bs=0;
        if(bs)
        {
            cout<<1<<endl;
            REP(i,n)    cout<<"1 ";
            cout<<endl;
            continue;
        }
        if(n%2==0)
        {
            cout<<2<<endl;
            REP(i,n)    cout<<i%2+1<<" ";
            cout<<endl;
            continue;
        }
        bool s=0;
        int ind=0;
        REP(i,n)
        {
            if(ar[i]==ar[(i+1)%n])
            {
                s=1;
                ind=i;
                break;
            }
        }
        if(s)
        {
            c[ind] = 1;
            c[(ind+1)%n] = 1;
            int cl = 1;
            for(int j=ind+2;j<ind+n;j++)
            {
                c[j%n] = cl%2+1;
                cl++;
            }
            cout<<2<<endl;
            REP(i,n)    cout<<c[i]<<" ";
            cout<<endl;

        }
        else
        {
            cout<<3<<endl;
            REP(i,n-1)  cout<<i%2+1<<" ";
            cout<<3<<endl;
        }
        
    }   
}