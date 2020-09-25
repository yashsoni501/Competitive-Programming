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
    int t;
    string s;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>s;
        n=sz(s);
        if(s[0]=='?')
        {
            if(s[1]!='a')
                s[0]='a';
            else if(s[1]!='b')
                s[0]='b';
            else
            {
                s[0]='c';
            }
        }
        for(int i=1;i<n-1;i++)
        {
            if(s[i]=='?')
            {
                if(s[i+1]!='a'&&s[i-1]!='a')
                    s[i]='a';
                else if(s[i+1]!='b'&&s[i-1]!='b')
                    s[i]='b';
                else
                {
                    s[i]='c';
                }
            }
        }
        if(s[n-1]=='?')
        {
            if(s[n-2]!='a')
                s[n-1]='a';
            else if(s[n-2]!='b')
                s[n-1]='b';
            else
            {
                s[n-1]='c';
            }
        }
        bool b=1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                b=0;
                break;
            }
        }
        if(b)
            cout<<s<<endl;
        else 
            cout<<-1<<endl;
    }   
}