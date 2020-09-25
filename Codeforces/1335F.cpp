#include<bits/stdc++.h>
using namespace std;
 
#define ll int
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

pll next(pll a, char dir)
{
    if(dir == 'R')  return {a.ff, a.ss+1};
    if(dir == 'L')  return {a.ff, a.ss-1};
    if(dir == 'D')  return {a.ff+1, a.ss};
    if(dir == 'U')  return {a.ff-1, a.ss};
}

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

unordered_map<pll, vector<pll>, hash_pair> adj;
unordered_map<pll, char, hash_pair> nxt;
unordered_map<pll, int, hash_pair> cmp;
unordered_map<pll, char, hash_pair> clr;
unordered_map<pll, int, hash_pair> ind;
unordered_set<pll, hash_pair> vis;
unordered_map<ll, ll> clen;
unordered_set<pll, hash_pair> st;
ll itr, cnt, cmpd, cleng, oset;

pll p1, p2, pn;
int main()
{
    IOS

    ll t=1;
    cin>>t;
    while(t--)
    {
        st.clear();
        clen.clear();
        vis.clear();
        adj.clear();
        nxt.clear();
        cmp.clear();

        ll n,m;
        cin>>n>>m;
        REP(i,n)    REP(j,m)    cin>>clr[{i,j}];
        REP(i,n)    REP(j,m)    cin>>nxt[{i,j}];
        
        REP(i,n)
        {
            REP(j,m)
            {
                p1 = {i,j};
                p2 = next(p1, nxt[p1]);
                if(!adj.count(p1))
                {
                    adj[p1] = vector<pll>();
                }
                if(!adj.count(p2))
                {
                    adj[p2] = vector<pll>();
                }
                adj[p1].pb(p2);
                adj[p2].pb(p1);
            }
        }
        cnt=1;
        for(auto it:adj)
        {
            if(sz(it.ss)==1)
            {
                p1 = it.ff;
                vis.in(p1);
                cmp[p1] = cnt;
                itr = 0;
                ind[p1] = itr++;
                while(!vis.count(next(p1,nxt[p1])))
                {
                    p1 = next(p1, nxt[p1]);
                    cmp[p1] = cnt;
                    ind[p1] = itr++;
                    vis.in(p1);
                }
                pn = next(p1,nxt[p1]);
                if(cmp[p1]==cmp[pn])
                {
                    clen[cmp[p1]] = ind[p1] - ind[pn]+1;
                    p2 = it.ff;
                    REP(i,itr)
                    {
        // cout<<"here"<<endl;
                        ind[p2] %= clen[cmp[p2]];
                        p2 = next(p2, nxt[p2]);
                    }
                }
                else
                {
                    cmpd = cmp[pn];
                    cleng = clen[cmpd];
                    oset = ((ind[pn] - itr)%cleng+cleng)%cleng;
                    p2 = it.ff;
                    REP(i,itr)
                    {
                        ind[p2] = (oset+i)%cleng;
                        cmp[p2] = cmpd;
                        p2 = next(p2, nxt[p2]);
                    }
                }
                
                cnt++;
            }
        }
        for(auto it:adj)
        {
            if(!vis.count(it.ff))
            {
                p1 = it.ff;
                vis.in(p1);
                cmp[p1] = cnt;
                clen[cnt] = 1;
                ind[p1] = 0;
                while(!vis.count(next(p1, nxt[p1])))
                {
                    p1 = next(p1, nxt[p1]);
                    ind[p1] = clen[cnt];
                    clen[cnt]++;
                    cmp[p1] = cnt;
                    vis.in(p1);

                }
                cnt++;
            }
        }
        // if(sz(vis)!=n*m)
        // {
        //     cout<<"ouchh!"<<endl;
        //     trace(sz(vis))
        // }
        // else
        // {
        //     cout<<"yeahh!"<<endl;
        // }
        ll sum=0;
        for(auto it:clen)
        {
            sum+=it.ss;
        }
        for(auto it:adj)
        {
            if(clr[it.ff]=='0')
            {
                st.in({cmp[it.ff], ind[it.ff]});
            }
        }
        cout<<sum<<" "<<sz(st)<<endl;

        REP(i,n)
        {
            REP(j,m)
            {
                adj[{i,j}].clear();
            }
        }
    }   
}