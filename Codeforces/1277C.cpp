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

int main()
{
    IOS
    ll t;
    string s;
    cin>>t;
    while(t--)
    {
        vl vc;
        string x="";
        cin>>s;
        int n=sz(s);
        pair<char,int> arr[n];
        REP(i,n)
        {
            arr[i].ff=s[i];
            arr[i].ss=i+1;
        }
        REP(i,sz(s)-4)
        {
            if(s[i]=='t' && s[i+1]=='w'&& s[i+2]=='o' && s[i+3]=='n' && s[i+4]=='e')
            {
                arr[i+2].ss=0;
                vc.pb(i+3);
            }
        }
        REP(i,n-2)
        {
            if((s[i]=='o' && s[i+1]=='n' && s[i+2]=='e')) 
            {
                if(arr[i].ss)
                {
                    vc.pb(i+2);
                    arr[i+1].ss=0;
                }
            }
            if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o')
            {
                if(arr[i+2].ss)
                {
                    vc.pb(i+2);
                    arr[i+1].ss=0;
                }
            }
        }
        cout<<sz(vc)<<endl;
        REP(i,sz(vc))
        {
            cout<<vc[i]<<" ";
        }
        cout<<endl;
    }
    
}