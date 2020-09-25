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

ll a,b,c,d;

int main()
{
    IOS
    cin>>a>>b>>c>>d;
    ll t=a+b+c+d;
    if(t==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    deque<int> de;
    if(a)   {de.pb(0),a--;}
    else if(b)  {de.pb(1),b--;}
    else if(c)  {de.pb(2),c--;}
    else    {de.pb(3),d--;}
    t--;
    while(t--)
    {
        //cout<<"here"<<endl;
        //trace(a)    trace(b)    trace(c)    trace(d)
        bool psh=0;
        if((a&& !psh))
        {
            if(de.front()==1)
            {
                de.pf(0);
                a--;
                psh=1;
            }
            else if(de.back()==1)
            {
                de.pb(0);
                a--;
                psh=1;
            }
        }
        if((b&&!psh))
        {
            if(de.front()==0 || de.front()==2)
            {
                de.pf(1);
                b--;
                psh=1;
            }
            else if(de.back()==0 || de.back()==2)
            {
                de.pb(1);
                b--;
                psh=1;
            }
        }
        if((c&&!psh))
        {
            if(de.front()==1||de.front()==3)
            {
                de.pf(2);
                c--;
                psh=1;
            }
            else if(de.back()==1||de.back()==3)
            {
                de.pb(2);
                c--;
                psh=1;
            }
        }
        if((d&&!psh))
        {
            if(de.front()==2)
            {
                de.pf(3);
                d--;
                psh=1;
            }
            else if(de.back()==2)
            {
                de.pb(3);
                d--;
                psh=1;
            }
        }
        //trace(psh)
        if(!psh)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    while(!de.empty())
    {
        cout<<de.front()<<" ";
        de.pop_front();
    }
    cout<<endl;
}