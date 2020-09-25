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
set<ll> st;
bool vis[200000];
set<ll>::iterator it;

void upd(ll i)
{
    vis[i]=1;
    st.erase(i);
    if(i>0 && !vis[i-1])
    {
        if(s[i-1]=='0')
        {
            s[i-1]='1';
            st.in(i-1);
        }
        else
        {
            s[i-1]='0';
            st.erase(i-1);
        }
    }
    if(i<sz(s)-1 && !vis[i+1])
    {
        if(s[i+1]=='0')
        {
            s[i+1]='1';
            st.in(i+1);
        }
        else
        {
            s[i+1]='0';
            st.erase(i+1);
        }
    }
}

int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        st.clear();
        cin>>s;
        REP(i,sz(s))
        {
            vis[i] = 0;
            if(s[i]=='1')
            {
                st.in(i);
            }
        }
        
        while(!st.empty())
        {
            it=st.begin();
            upd(*it);    
        }
        bool b=1;
        REP(i,sz(s))
        {
            if(!vis[i])
            {
                b=0;
                break;
            }
        }
        if(b)   cout<<"WIN\n";
        else
        {
            cout<<"LOSE\n";
        }
        
    }
}