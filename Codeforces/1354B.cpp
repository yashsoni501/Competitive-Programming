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

ll t;
string s;
vl v[4];
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        cin>>s;
        v[1].clear();
        v[2].clear();
        v[3].clear();
        
        REP(i,sz(s))
        {
            v[s[i]-'0'].pb(i);
        }

        bool b1=0,b2=0,b3=0;
        for(int i=sz(s)-1;i>=0;i--)
        {
            if(b1&&b2&&b3)  break;
            if(s[i]=='1')   b1=1;
            if(s[i]=='2')   b2=1;
            if(s[i]=='3')   b3=1;
        }
        bool boo=1;
        REP(i,3)
        {
            if(sz(v[i+1])==0)
            {
                boo=0;
            }
        }
        if(!boo)
        {
            cout<<"0\n";
            continue;
        }
        ll cnt=sz(s);
        REP(i,sz(s))
        {
            ll x,y;
            if(s[i]=='1')
            {
                if(upper_bound(all(v[2]),i)!=v[2].end())
                    x = *upper_bound(all(v[2]),i);
                else
                {
                    break;
                }
                
                if(upper_bound(all(v[3]),i)!=v[3].end())
                    y = *upper_bound(all(v[3]),i);
                else 
                    break;

                if(x>i &&y>i)
                cnt = min(cnt,max(x,y)-i+1);
            }
            else if(s[i]=='2')
            {
                if(upper_bound(all(v[1]),i)!=v[1].end())
                    x = *upper_bound(all(v[1]),i);
                else
                {
                    break;
                }
                
                if(upper_bound(all(v[3]),i)!=v[3].end())
                    y = *upper_bound(all(v[3]),i);
                else 
                    break;

                if(x>i &&y>i)
                cnt = min(cnt,max(x,y)-i+1);
            }
            else
            {
                if(upper_bound(all(v[2]),i)!=v[2].end())
                    x = *upper_bound(all(v[2]),i);
                else
                {
                    break;
                }
                
                if(upper_bound(all(v[1]),i)!=v[1].end())
                    y = *upper_bound(all(v[1]),i);
                else 
                    break;

                if(x>i &&y>i)
                cnt = min(cnt,max(x,y)-i+1);
            }
        }
        cout<<cnt<<endl;
    }
    
}