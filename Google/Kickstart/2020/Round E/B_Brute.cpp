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
ll n,a,b,c;
vl vt;
int main()
{
    IOS
    t=10;
    while(t--)
    {
        vt.clear();
        deque<ll> dq;
        n = 20;
        a = rand()%n+1;
        b = rand()%n+1;
        c = rand()%min(a,b)+1;
        bool boo=1;
        if(a+b-c>n || (a==1 && b==1 && n>1))
        {
            // cout<<"Case #"<<te+1<<": "<<"IMPOSSIBLE\n";
            // continue;
            boo=0;
        }
        if(n==2)
        {
            if(a==2 && b==2 &&c==2)
            {
                // cout<<"Case #"<<te+1<<": "<<"2 2\n";
                // continue;
                boo=0;
            }
            if(a==2 && b==1)
            {
                boo=0;
                // cout<<"Case #"<<te+1<<": "<<"1 2\n";
                // continue;
            }
            if(a==1 && b==2)
            {
                boo=0;
                // cout<<"Case #"<<te+1<<": "<<"2 1\n";
                // continue;
            }
        }
        if(c==1)
        {
            dq.pb(3);
            ll lft = n-(a+b-c);
            if(lft>0)
            {
                if(a>c)
                {
                    REP(i,lft)
                    {
                        dq.pf(1);
                    }
                }
                else if (b>c)
                {
                    REP(i,lft)
                    {
                        dq.pb(1);
                    }
                }
                else
                {
                    boo=0;
                    // continue;
                }
            }
            REP(i,b-c)
            {
                dq.pb(2);
            }
            REP(i,a-c)
            {
                dq.pf(2);
            }
        }
        else
        {
            dq.pb(3);
            ll lft = n-(a+b-c);
            REP(i,lft)
            {
                dq.pb(1);
            }
            REP(i,c-1)
            {
                dq.pb(3);
            }
            REP(i,b-c)
            {
                dq.pb(2);
            }
            REP(i,a-c)
            {
                dq.pf(2);
            }
        }

        // cout<<"Case #"<<te+1<<": ";
        REP(i,n)    
        {
            vt.pb(dq.front());
            dq.pop_front();
        }
        // cout<<endl;
        
        cout<<n<<" "<<a<<" "<<b<<" "<<c<<endl;
        if(boo)
        REP(i,n)
        {
            cout<<vt[i]<<" ";
        }
        else
        {
            cout<<"IMP";
        }
        
        cout<<endl<<endl;
    }
}