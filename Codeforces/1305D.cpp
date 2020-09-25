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

ll n;
set<ll> pos;
vl adj[2000];
bool vis[2000];

int getNum(vector<int>& v) 
{ 
  
    // Size of the vector 
    int n = v.size(); 
  
    // Generate a random number 
    srand(time(NULL)); 
  
    // Make sure the number is within 
    // the index range 
    int index = rand() % n; 
  
    // Get random number from the vector 
    int num = v[index]; 
  
    // Remove the number from the vector 
    swap(v[index], v[n - 1]); 
    v.pop_back(); 
  
    // Return the removed number 
    return num; 
} 
  
// Function to generate n non-repeating random numbers 
vl generateRandom(int n) 
{ 
    vector<ll> v(n); 
  
    // Fill the vector with the values 
    // 1, 2, 3, ..., n 
    for (int i = 0; i < n; i++) 
        v[i] = i; 
  
    // While vector has elements 
    // get a random number from the vector and print it 
    return v;
} 

ll gma,gmat;
void dfsfar(int st, int d)
{
    // trace(st) trace(d)
    if(d>gmat && pos.find(st)!=pos.end())
    {
        gmat = d;
        gma = st;
    }
    vl vt(generateRandom(sz(adj[st])));
    REP(i,sz(adj[st]))
    {
        if(!vis[adj[st][vt[i]]])
        {
            vis[adj[st][vt[i]]] = 1;
            dfsfar(adj[st][vt[i]],d+1);
        }
    }    
}

bool bt=0;
void dfsrm(ll a, ll b)
{
    if(a==b)
    {
        bt=1;
        return;
    }
    REP(i,sz(adj[a]))
    {
        if(!bt && !vis[adj[a][i]])
        {
            vis[adj[a][i]]=1;
            dfsrm(adj[a][i],b);
        }
        if(bt)
        {
            break;
        }
    }
    if(bt)
    {
        // trace(a)
        pos.erase(a);
        return;
    }
}

int main()
{
    cin>>n;
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    REP(i,n)    pos.insert(i+1);
    ll cnt=0;
    while(sz(pos)>1)
    {
        if(cnt>n/2)
        {cout<<"! n"<<endl;
        return 0;}
        REP(i,n+1)
        {
            vis[i]=0;
        }
        vis[*pos.begin()]=1;
        gma=*pos.begin();
        gmat = 0;
        dfsfar(*pos.begin(),0);
        REP(i,n+1)
        {
            vis[i]=0;
        }
        vis[gma]=1;
        gmat=0;
        ll gma2 = gma;
        dfsfar(gma,0);
        // ll dfsfart = gma;
        // trace(gma)  trace(gmat)
        cout<<"? "<<gma<<" "<<gma2<<endl;
        ll inp;
        cin>>inp;
        REP(i,n+1)    vis[i] = 0;
        vis[gma]=1;
        bt=0;
        dfsrm(gma,inp);
        REP(i,n+1)    vis[i] = 0;
        vis[gma2] = 1;
        bt=0;
        dfsrm(gma2, inp);
        cnt++;
    }
    cout<<"! "<<*pos.begin()<<endl;
}