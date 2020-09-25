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

ll t,n,x;
string w;
string s;
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        
        cin>>s;
        cin>>x;
        n = sz(s);
        w="";
        REP(i,n)    w+='-';
        bool boo=1;
        REP(i,x)
        {
            if(i+x<n)
                w[i+x] = s[i];
            else if(s[i]=='1')
            {
                boo=0;
                break;
            }
        }
        for(int i=n-1;i>n-x-1;i--)
        {
            if(i-x<0)
            {
                if(s[i]=='1')
                {
                    boo=0;
                    break;
                }
                continue;
            }
            if(w[i-x] != '-' && s[i] != w[i-x])
            {
                boo=0;
                break;
            }
            else
            {
                w[i-x] = s[i];
            }
        }
        // trace(w)
        FOR(i,x,n-x,1)
        {
            if(s[i]=='0')
            {
                if(w[i-x]=='1' || w[i+x] == '1')
                {
                    boo=0;
                    break;
                }
                if(w[i-x]=='-')
                    w[i-x]='0';
                if(w[i+x]=='-')
                    w[i+x]='0';
            }
            else
            {
                if(w[i-x]=='0' && w[i+x]=='0')
                {
                    boo=0;
                    break;
                }
                if(w[i-x]=='-')
                    w[i-x]='1';
                else if(w[i-x]=='0')
                {
                    w[i+x]='1';
                }
            }
        }
        REP(i,n)
        {
            if(w[i]=='-')   w[i]='1';
        }
        // trace(w)
        if(boo)
            cout<<w<<endl;
        else
        {
            cout<<-1<<endl;
        }
    }
}