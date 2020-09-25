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
inline ll addm(ll a, ll b, ll m){a += b; if(a >= m)a -= m; return a;}
inline ll subm(ll a, ll b, ll m){a -= b; if(a < 0)a += m; return a;}
inline ll mulm(ll a, ll b, ll m){return (ll)((ll) a * b %m);}
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

ll t,n,k,w;
ll l[1000010], h[1000010], p[1000010];
ll cl[4];
ll ch[4];

priority_queue<pll> pq; 
int main()
{
    // IOS
    cin>>t;
    // t=10;
    REP(te,t)
    {
        while(!pq.empty())   pq.pop();
        cin>>n>>k>>w;
        // n = 1000000;
        // k = 1000000;
        // w = 20;
        // REP(i,n)    l[i] = i+1;
        // REP(i,n)    h[i] = i+1;
        REP(i,k)    cin>>l[i];
        REP(i,4)    cin>>cl[i];
        REP(i,k)    cin>>h[i];
        REP(i,4)    cin>>ch[i];
     
        FOR(i,k,n,1)    l[i] = addm(addm(mulm(cl[0], l[i-2], cl[3]), mulm(cl[1], l[i-1], cl[3]),  cl[3]), cl[2], cl[3])+1;
        FOR(i,k,n,1)    h[i] = addm(addm(mulm(ch[0], h[i-2], ch[3]), mulm(ch[1], h[i-1], ch[3]),  ch[3]), ch[2], ch[3])+1;

        cout<<"li: ";
        REP(i,n)    cout<<l[i]<<" ";
        cout<<endl;
        cout<<"hi: ";
        REP(i,n)    cout<<h[i]<<" ";
        cout<<endl;

        p[0] = add(add(w,w), add(h[0],h[0]));
        pq.push({h[0], 0});

        FOR(i,1,n,1)
        {
            pll top = pq.top();
            while(!pq.empty() && l[top.ss] < l[i]-w)
            {
                pq.pop();
                top = pq.top();
            }
            if(pq.empty())
            {
                p[i] = add(p[i-1], add(add(w,w), add(h[i],h[i])));
            }
            else
            {
                p[i] = add(p[top.ss], mul(2, (l[i]-l[top.ss])));
                if(h[i] > top.ff)
                {
                    p[i] = add(p[i], mul(2, (h[i]-top.ff)));
                }
            }
            pq.push({h[i], i});
        }

        cout<<"pi: ";
        REP(i,n)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
        ll ans=1;
        REP(i,n)
        {
            ans = mul(ans, p[i]);
        }

        cout<<"Case #"<<te+1<<": "<<ans<<endl;
    }
}