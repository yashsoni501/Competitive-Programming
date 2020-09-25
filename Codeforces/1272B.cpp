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
    ll q;
    string s;
    cin>>q;
    int ar[4];
    while(q--)
    {
        ar[0]=ar[1]=ar[2]=ar[3]=0;
        cin>>s;
        int n = sz(s);
        REP(i,sz(s))
        {
            if(s[i]=='U')   ar[0]++;
            if(s[i]=='L')   ar[1]++;
            if(s[i]=='D')   ar[2]++;
            if(s[i]=='R')   ar[3]++;
        }
        ar[0]=ar[2]=min(ar[0],ar[2]);
        ar[1]=ar[3]=min(ar[1],ar[3]);
        int ns = ar[0]+ar[1]+ar[2]+ar[3];
        if(ar[0]==0)
        {
            if(ar[1]==0)
            cout<<0<<endl;
            else
            {
                cout<<2<<endl;
                cout<<"LR"<<endl;
            }
            continue;
        }
        if(ar[1]==0)
        {
            if(ar[0]==0)
            cout<<0<<endl;
            else
            {
                cout<<2<<endl;
                cout<<"UD"<<endl;
            }
            continue;
        }
        string st="ULDR";
        cout<<ns<<endl;
        REP(i,4)
        {
            REP(j,ar[i])
            {
                cout<<st[i];
            }
        }
        cout<<endl;
    }
}