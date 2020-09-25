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
 
int n,ar[200000];   
int stat[200000];
int dist[200000];

stack<int> st;

int dfs(int i,bool p)
{
    // cout<<i<<" "<<stat[9]<<endl;
    if(i<0|| i>=n)
        return 1e9;
    st.push(i); 
    if(ar[i]%2!=p)
        return 0;
    if(stat[i]==1)  
    {
        return 1e9;
    }
    if(stat[i]==2)
    {
        return dist[i];
    }
    stat[i]=1;
    dist[i] = min(dfs(i-ar[i],p),dfs(i+ar[i],p))+1;
    stat[i]=2;
    return dist[i];
}
 
int main()
{
    IOS
    n=200000;
    REP(i,n)
        ar[i]=1;
    ar[0]=2;
    REP(i,n)
    {
        stat[i]=0;
        dist[i]=-1;
    }
    REP(i,n)
    {
        if(stat[i]!=2)
        {
            dist[i] = dfs(i,ar[i]%2);
        }
    }
    int a=1;
    while(a)
    {
        a=0;
        for(int t=0;t<n;t++)
        {        
            ll tmp=dist[t];
            if(t+ar[t]<n)
            {
                if(ar[t]%2==ar[t+ar[t]]%2) 
                {
                    tmp = min(tmp,dist[t+ar[t]]+1);
                }
            }
            if(t-ar[t]>=0)
            {
                if(ar[t]%2==ar[t-ar[t]]%2)
                {
                    tmp = min(tmp,dist[t-ar[t]]+1);
                }
            }
            if(tmp!=dist[t])
            {
                dist[t]=tmp;
                a=1;
            }
        }
    }
    REP(i,n)
    {
        if(dist[i]>n)   dist[i]=-1;
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}
