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

ll t,a,b;
string s;
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cin>>s;
        ll n= sz(s);
        bool boo=1;
        REP(i,(n+1)/2)
        {
            if(s[i]!=s[n-i-1])
            {
                if(s[i]=='?')   s[i] = s[n-i-1];
                else if(s[n-i-1]=='?')  s[n-i-1]=s[i];
                else boo=0;
            }
        }
        if(!boo)
        {
            cout<<"-1\n";
            continue;
        }
        if(n%2==0)
        {
            if(a+b!=n || a%2 || b%2)
            {
                cout<<"-1\n";
                continue;
            }
        }
        else
        {
            if(a+b != n) 
            {
                cout<<"-1\n";
                continue;
            }
            if(s[(n-1)/2]=='1' && b%2==0 || s[(n-1)/2]=='0' && a%2==0)
            {
                cout<<"-1\n";
                continue;
            }
            if(s[(n-1)/2]=='?')
            {
                // cout<<"here\n";
                if(a%2) s[(n-1)/2]='0';
                else
                {
                    s[(n-1)/2]='1';
                }
            }
        }
        ll cnt[3]={};
        REP(i,n)
        {
            if(s[i]=='0') cnt[0]++;
            if(s[i]=='1') cnt[1]++;
            if(s[i]=='?') cnt[2]++;
        }
        // trace(cnt[0])
        // trace(cnt[1])
        // trace(cnt[2])
        // trace(s)
        
        if(cnt[0]>a || cnt[1]>b)
        {
            cout<<"-1\n";
            continue;
        }
        cnt[0] = a-cnt[0];
        cnt[1] = b-cnt[1];
        REP(i,n/2)
        {
            if(s[i]=='?')
            if(cnt[0])
            {
                s[i]='0';
                s[n-i-1]='0';
                cnt[0]-=2;
            }
            else
            {
                s[i]='1';
                s[n-i-1]='1';
                cnt[1]-=2;
            }
        }
        cout<<s<<endl;
    }
}