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

int typebata(string p)
{
    if(p[0]=='0' && p[sz(p)-1]=='0')
        return 0;
    if(p[0]=='0' && p[sz(p)-1]=='1')
        return 1;
    if(p[0]=='1' && p[sz(p)-1]=='0')
        return 2;
    if(p[0]=='1' && p[sz(p)-1]=='1')
        return 3;
}

string nvrt(string p)
{
    string x="";
    REP(i,sz(p))
    {   
        x+=p[sz(p)-i-1];
    }
    return x;
}

ll t,n;
pair<string,int> s[300000];
vl vc;
vector<string> stype[4];
set<string> st;   
int main()
{
    IOS
    cin>>t;
    while(t--)
    {
        vc.clear();
        st.clear();
        REP(i,4)    stype[i].clear();
        cin>>n;
        REP(i,n)
        {
            cin>>s[i].ff;
            s[i].ss=i+1;
            stype[typebata(s[i].ff)].pb(s[i].ff);
            st.insert(s[i].ff);
        }
        sort(s,s+n);
        
        ll a=sz(stype[0]),b=sz(stype[1]),c=sz(stype[2]),d=sz(stype[3]);
        // trace(a)    trace(b)    trace(c)    trace(d)
        if(b==0&& c==0)
        {
            if(a==0 || d==0)
            {
                cout<<0<<endl<<endl;
                continue;
            }
            else
            {
                cout<<-1<<endl;
                continue;
            }
            
        }
        else
        {
            int i=0;
            while(abs(b-c)>(b+c)%2 && i<n)
            {
                if(b>c)
                {
                    if(typebata(s[i].ff)==1)
                    {
                        if(st.find(nvrt(s[i].ff))==st.end())
                        {
                            vc.pb(s[i].ss);
                            b--;c++;
                        }
                    }
                }
                else
                {
                    if(typebata(s[i].ff)==2)
                    {
                        if(st.find(nvrt(s[i].ff))==st.end())
                        {
                            vc.pb(s[i].ss);
                            c--;b++;
                        }
                    }
                }
                
                i++;
            }
            if(abs(b-c)>(b+c)%2)
            {
                cout<<-1<<endl;
                continue;
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